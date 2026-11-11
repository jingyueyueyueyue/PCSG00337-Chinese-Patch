
undefined4 FUN_8106e880(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 0x42);
  if ((((bVar1 & 2) == 0) || ((bVar1 & 1) != 0)) || ((bVar1 & 4) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if ((*(byte *)(param_1 + 0x44) & 4) == 0) {
      if (*(int *)(param_1 + 0x38) == 0) {
        uVar2 = 1;
        if ((*(byte *)(param_1 + 0x44) & 1) != 0) {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
        iVar3 = FUN_8106e880();
        if ((iVar3 != 0) && (uVar2 = 1, (*(byte *)(param_1 + 0x44) & 1) != 0)) {
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}

