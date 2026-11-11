
undefined4 FUN_8106bda4(int param_1)

{
  ushort uVar1;
  undefined uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = *(int *)(param_1 + 0x100);
  *(undefined2 *)(param_1 + 0xe8) = 0;
  *(undefined2 *)(param_1 + 0xe6) = 0;
  uVar5 = *(uint *)(param_1 + 0xdc);
  uVar3 = uVar5 & 1;
  if ((iVar6 == 0) || ((uVar5 & 4) == 0)) {
    iVar6 = *(int *)(param_1 + 0xf8);
    if (uVar3 == 0) {
      iVar6 = iVar6 + -1;
      *(int *)(param_1 + 0xf8) = iVar6;
      if (iVar6 < 0) {
        *(int *)(param_1 + 0xf8) = iVar6 + *(int *)(param_1 + 0x5c);
      }
      iVar6 = *(int *)(*(int *)(param_1 + 0xf4) + 4);
      *(int *)(param_1 + 0xf4) = iVar6;
      if (iVar6 == 0) {
        iVar6 = func_0x8106d280(param_1 + 0x58,*(int *)(param_1 + 0x5c) + -1);
        *(int *)(param_1 + 0xf4) = iVar6;
      }
      *(int *)(param_1 + 0xfc) = iVar6;
      uVar2 = FUN_8106b67c(param_1);
      *(undefined *)(param_1 + 0xd8) = uVar2;
      uVar7 = 1;
      uVar5 = *(uint *)(param_1 + 0xdc);
    }
    else {
      uVar7 = 0;
      if (iVar6 != 0) {
        iVar4 = *(int *)(*(int *)(param_1 + 0xf4) + 4);
        uVar7 = 1;
        *(int *)(param_1 + 0xf8) = iVar6 + -1;
        if (((*(ushort *)(iVar4 + 0x10) & 4) == 0) || (iVar6 + -1 != 0)) {
          *(int *)(param_1 + 0xfc) = iVar4;
        }
        else {
          *(undefined4 *)(param_1 + 0x100) = 1;
        }
        *(int *)(param_1 + 0xf4) = iVar4;
        uVar2 = FUN_8106b67c(param_1);
        *(undefined *)(param_1 + 0xd8) = uVar2;
        uVar5 = *(uint *)(param_1 + 0xdc);
      }
    }
    if ((uVar5 & 4) != 0) {
      return uVar7;
    }
    *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_1 + 0xf4);
    *(undefined4 *)(param_1 + 0x100) = 0;
    return uVar7;
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0xfc) + 4);
  if (iVar4 == 0) {
    if (uVar3 == 0) {
      iVar4 = func_0x8106d280(param_1 + 0x58,*(int *)(param_1 + 0x5c) + -1);
      uVar3 = *(uint *)(param_1 + 0xdc) & 1;
      iVar6 = *(int *)(param_1 + 0x100);
      goto LAB_8106be84;
    }
  }
  else {
LAB_8106be84:
    if (uVar3 == 0) goto LAB_8106be94;
  }
  if (((*(ushort *)(iVar4 + 0x10) & 4) != 0) && (*(int *)(iVar4 + 4) == 0)) {
    iVar4 = 0;
  }
LAB_8106be94:
  uVar7 = 0;
  if (iVar4 != 0) {
    uVar1 = *(ushort *)(iVar4 + 0x10);
    *(int *)(param_1 + 0xfc) = iVar4;
    *(int *)(param_1 + 0x100) = iVar6 + -1;
    uVar7 = 0;
    if ((uVar1 & 4) != 0) {
      uVar7 = FUN_8106bda4(param_1);
    }
  }
  return uVar7;
}

