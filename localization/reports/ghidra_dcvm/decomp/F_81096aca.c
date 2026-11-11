
void FUN_81096aca(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  
  iVar1 = func_0x810949a0(param_1,*(undefined4 *)(param_1 + 0xc),0);
  iVar6 = *(int *)(param_1 + 0x14);
  iVar11 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 0xc) +
            (*(uint *)(&UNK_8113846c +
                      (uint)*(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) * 0xc)
            & *(uint *)(param_1 + 0x60));
    *(undefined4 *)(param_1 + 0x38) =
         *(undefined4 *)
          (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar1 + 1) * 0xc);
    *(int *)(param_1 + 0xc) = iVar1;
  }
  uVar2 = iVar6 + 1;
  iVar5 = iVar11 + iVar6 * 8;
  iVar6 = iVar11 + (iVar6 + 2) * 8;
  *(uint *)(param_1 + 0x2c) = uVar2 & 0xffffff00 | 0x21;
  *(undefined4 *)(param_1 + 0x30) = 0;
  uVar3 = func_0x81094fd2(param_1);
  puVar4 = (undefined4 *)func_0x8109ca34();
  func_0x8109c2ae(*puVar4,*(undefined4 *)(iVar6 + 4));
  iVar1 = func_0x8109ceba(uVar3,*(undefined4 *)(iVar11 + uVar2 * 8 + 4));
  uVar10 = *(int *)(iVar5 + 4) - 2;
  puVar12 = (uint *)(*(int *)(param_1 + 0x24) + (*(int *)(param_1 + 0x14) + 3) * 8);
  if (uVar10 != 0) {
    uVar7 = 0;
    puVar9 = puVar12;
    do {
      uVar8 = *puVar9;
      if ((uVar8 & 0xf0) == 0) {
        *puVar9 = uVar8 & 0xffffff0f | 0x40;
        *puVar9 = uVar8 & 0xf | 0x40 | *(int *)(param_1 + 8) << 8;
      }
      uVar7 = uVar7 + 1;
      puVar9 = puVar9 + 2;
    } while (uVar7 < uVar10);
  }
  FUN_810960d8(iVar1,*(undefined4 *)(iVar6 + 4),uVar10,puVar12,1);
  iVar6 = *(int *)(iVar5 + 4) + 1;
  iVar11 = *(int *)(param_1 + 0x14) + iVar6;
  if (iVar11 < 0) {
    func_0x81094a54(param_1,2);
  }
  else if (iVar6 < *(int *)(param_1 + 0x1c)) {
    *(int *)(param_1 + 0x14) = iVar11;
  }
  else {
    func_0x81094a54(param_1,3);
  }
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar1 + 8);
  *(uint *)(param_1 + 0x2c) = uVar2 & 0xffffff00 | 0x21;
  return;
}

