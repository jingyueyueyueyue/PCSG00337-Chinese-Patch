
void FUN_8107c40a(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 != 0) {
    uVar4 = *(uint *)(param_1 + 0x2c);
    uVar5 = 0;
    if (uVar4 != 0) {
      iVar2 = *(int *)(param_1 + 0x14);
      do {
        puVar1 = (undefined *)(uVar5 * iVar2 + iVar3);
        uVar5 = uVar5 + 1;
        *puVar1 = 0;
        puVar1[1] = 0;
      } while (uVar5 < uVar4);
    }
  }
  return;
}

