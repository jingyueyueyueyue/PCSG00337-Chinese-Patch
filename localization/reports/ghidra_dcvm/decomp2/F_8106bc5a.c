
undefined4 FUN_8106bc5a(int param_1)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  bVar2 = *(byte *)(param_1 + 0xd8);
  *(undefined2 *)(param_1 + 0xe8) = 0;
  uVar5 = *(uint *)(param_1 + 0xdc);
  *(undefined2 *)(param_1 + 0xe6) = 0;
  uVar3 = uVar5 & 1;
  if ((bVar2 - 1 == *(int *)(param_1 + 0x100)) || ((uVar5 & 4) == 0)) {
    iVar4 = *(int *)(param_1 + 0xf8);
    if (uVar3 == 0) {
      *(int *)(param_1 + 0xf8) = iVar4 + 1;
      if (*(int *)(param_1 + 0x5c) <= iVar4 + 1) {
        *(undefined4 *)(param_1 + 0xf8) = 0;
      }
      iVar4 = *(int *)(*(int *)(param_1 + 0xf4) + 8);
      *(int *)(param_1 + 0xf4) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + 0x60);
      }
      iVar4 = *(int *)(*(int *)(param_1 + 0xfc) + 8);
      *(int *)(param_1 + 0xfc) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_1 + 0x60);
      }
      bVar2 = FUN_8106b67c(param_1);
      uVar5 = *(uint *)(param_1 + 0xdc);
      uVar7 = 1;
      *(byte *)(param_1 + 0xd8) = bVar2;
    }
    else {
      uVar7 = 0;
      if (*(int *)(param_1 + 0x5c) - (uint)bVar2 != iVar4) {
        uVar7 = 1;
        iVar8 = *(int *)(*(int *)(param_1 + 0xfc) + 8);
        *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(*(int *)(param_1 + 0xf4) + 8);
        *(int *)(param_1 + 0xf8) = iVar4 + 1;
        bVar2 = FUN_8106b67c(param_1);
        *(byte *)(param_1 + 0xd8) = bVar2;
        uVar5 = *(uint *)(param_1 + 0xdc);
        if (((*(ushort *)(iVar8 + 0x10) & 4) == 0) || (*(int *)(iVar8 + 8) != 0)) {
          *(int *)(param_1 + 0xfc) = iVar8;
        }
        else {
          *(uint *)(param_1 + 0x100) = bVar2 - 2;
        }
      }
    }
    if ((uVar5 & 4) != 0) {
      return uVar7;
    }
    iVar8 = *(int *)(param_1 + 0xf4);
    iVar4 = bVar2 - 1;
    *(int *)(param_1 + 0xfc) = iVar8;
    *(int *)(param_1 + 0x100) = iVar4;
    if (iVar4 < 1) {
      return uVar7;
    }
    iVar6 = 0;
    do {
      iVar8 = *(int *)(iVar8 + 8);
      *(int *)(param_1 + 0xfc) = iVar8;
      if ((iVar8 == 0) && ((uVar5 & 1) == 0)) {
        iVar8 = *(int *)(param_1 + 0x60);
        *(int *)(param_1 + 0xfc) = iVar8;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar4);
    return uVar7;
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0xfc) + 8);
  if (iVar4 == 0) {
    if (uVar3 == 0) {
      iVar4 = *(int *)(param_1 + 0x60);
      goto LAB_8106bd68;
    }
  }
  else {
LAB_8106bd68:
    if (uVar3 == 0) goto LAB_8106bd78;
  }
  if ((*(int *)(iVar4 + 8) == 0) && ((*(ushort *)(iVar4 + 0x10) & 4) != 0)) {
    iVar4 = 0;
  }
LAB_8106bd78:
  uVar7 = 0;
  if (iVar4 != 0) {
    uVar1 = *(ushort *)(iVar4 + 0x10);
    *(int *)(param_1 + 0xfc) = iVar4;
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
    uVar7 = 0;
    if ((uVar1 & 4) != 0) {
      uVar7 = FUN_8106bc5a(param_1);
    }
  }
  return uVar7;
}

