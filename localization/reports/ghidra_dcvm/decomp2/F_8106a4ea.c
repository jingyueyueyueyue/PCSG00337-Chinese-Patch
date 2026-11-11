
void FUN_8106a4ea(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x50);
  iVar1 = iVar2;
  while (iVar2 != 0) {
    if ((*(byte *)(iVar2 + 0x42) & 1) == 0) {
      FUN_81080958(iVar2 + 0xc);
      iVar2 = iVar1;
    }
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 8);
      iVar1 = iVar2;
    }
  }
  iVar2 = *(int *)(param_1 + 0x48);
  iVar1 = iVar2;
  while (iVar2 != 0) {
    if ((*(byte *)(iVar2 + 0x42) & 1) == 0) {
      FUN_81080958(iVar2 + 0xc);
      iVar2 = iVar1;
    }
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 8);
      iVar1 = iVar2;
    }
  }
  return;
}

