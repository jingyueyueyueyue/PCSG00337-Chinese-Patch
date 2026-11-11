
bool FUN_8106e8dc(int param_1)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  
  bVar1 = *(byte *)(param_1 + 0x42);
  if ((((bVar1 & 2) == 0) || ((bVar1 & 1) != 0)) || ((bVar1 & 4) == 0)) {
    bVar3 = false;
  }
  else {
    bVar3 = false;
    if ((*(byte *)(param_1 + 0x44) & 4) == 0) {
      if (*(int *)(param_1 + 0x38) == 0) {
        bVar3 = (*(byte *)(param_1 + 0x44) & 2) == 0;
      }
      else {
        bVar3 = false;
        iVar2 = FUN_8106e8dc();
        if (iVar2 != 0) {
          bVar3 = (*(byte *)(param_1 + 0x44) & 2) == 0;
        }
      }
    }
  }
  return bVar3;
}

