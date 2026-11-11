
void FUN_8106aa28(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x48);
  iVar2 = 0;
  for (iVar4 = *(int *)(param_1 + 0x50); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    bVar1 = *(byte *)(iVar4 + 0x42);
    if (((((bVar1 & 1) == 0) && ((bVar1 & 2) != 0)) && ((bVar1 & 4) != 0)) &&
       ((iVar2 == 0 || (*(ushort *)(iVar4 + 0x40) < *(ushort *)(iVar2 + 0x40))))) {
      iVar2 = iVar4;
    }
  }
  for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    bVar1 = *(byte *)(iVar3 + 0x42);
    if ((((bVar1 & 1) == 0) && ((bVar1 & 2) != 0)) &&
       (((bVar1 & 4) != 0 &&
        ((iVar2 == 0 || (*(ushort *)(iVar3 + 0x40) < *(ushort *)(iVar2 + 0x40))))))) {
      iVar2 = iVar3;
    }
  }
  return;
}

