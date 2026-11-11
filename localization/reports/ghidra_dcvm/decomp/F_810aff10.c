
int FUN_810aff10(int param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uStack_10;
  
  if ((*(int *)(param_1 + 200) == 0) || (*(int *)(param_1 + 0xe0) == 0)) {
    iVar3 = -0x79ffffe9;
  }
  else if (*(int *)(param_1 + 0xc) == 0x1f) {
    func_0x810b7ae4(param_1 + 0x6c);
    iVar4 = *(int *)(param_1 + 200);
    uStack_10 = 0;
    bVar1 = *(byte *)(iVar4 + 0x10);
    if ((bVar1 & 4) == 0) {
      if ((bVar1 & 8) == 0) {
        iVar3 = -0x79ffffe9;
        if ((bVar1 & 0x10) != 0) {
          iVar3 = func_0x810afa92(param_1,iVar4,&uStack_10);
        }
      }
      else {
        iVar3 = FUN_810afbc8(param_1,iVar4,&uStack_10);
      }
    }
    else {
      iVar3 = func_0x810afd78(param_1,iVar4,&uStack_10);
    }
    if (iVar3 == 0) {
      func_0x810aefe4(param_1,uStack_10);
      puVar5 = (undefined4 *)(param_1 + 0x10);
      do {
        ExclusiveAccess(puVar5);
        bVar2 = (bool)hasExclusiveAccess(puVar5);
      } while (!bVar2);
      *puVar5 = 1;
    }
  }
  else {
    iVar3 = -0x79ffffe8;
  }
  return iVar3;
}

