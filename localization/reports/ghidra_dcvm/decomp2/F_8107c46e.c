
void FUN_8107c46e(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort *puVar4;
  undefined *puVar5;
  undefined2 *puVar6;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    uVar3 = 0;
    uVar2 = *(uint *)(param_1 + 0x28);
    if (uVar2 != 0) {
      do {
        puVar4 = (ushort *)(uVar3 * *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18));
        *puVar4 = *puVar4 & 0xff00;
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    uVar3 = *(uint *)(param_1 + 0x2c);
    uVar2 = 0;
    if (uVar3 != 0) {
      do {
        puVar5 = (undefined *)(uVar2 * *(int *)(param_1 + 0x14) + iVar1);
        uVar2 = uVar2 + 1;
        *puVar5 = 0;
        puVar5[1] = 0;
      } while (uVar2 < uVar3);
    }
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    uVar3 = *(uint *)(param_1 + 0x28);
    uVar2 = 0;
    if (uVar3 != 0) {
      do {
        puVar6 = (undefined2 *)(uVar2 * *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x20));
        uVar2 = uVar2 + 1;
        puVar6[5] = puVar6[5] | 1;
        puVar6[3] = *puVar6;
        puVar6[4] = 0;
      } while (uVar2 < uVar3);
    }
  }
  return;
}

