
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_81097338(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  iVar1 = (*(int *)(param_1 + 0x14) + 1) * 8;
  uVar6 = *(uint *)(*(int *)(param_1 + 0x24) + iVar1);
  iVar4 = *(int *)(param_1 + 0x14) + 2;
  uStack_1c = *(undefined4 *)(*(int *)(param_1 + 0x24) + iVar1 + 4);
  uStack_20 = uVar6;
  if (iVar4 < 0) {
    func_0x81094a54(param_1,2);
  }
  else if (*(int *)(param_1 + 0x1c) < 3) {
    func_0x81094a54(param_1,3);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar4;
  }
  uVar2 = FUN_810951ba(param_1,&uStack_20);
  func_0x81094fd2(param_1);
  puVar3 = (undefined4 *)func_0x8109ca34();
  iVar1 = FUN_8109b780(*puVar3,uVar2);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x74);
  }
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  *(uint *)(param_1 + 0x2c) = uVar6 & 0xffffff00 | 0x21;
  iVar1 = FUN_810949a0(param_1,*(undefined4 *)(param_1 + 0xc),0);
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
  if (_UNK_8111a5b0 == iStack_18) {
    return 1;
  }
  iVar1 = func_0x811185a0(1);
  iVar5 = *(int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar1 + 0x14) * 8 + 4) + 1;
  iVar4 = *(int *)(iVar1 + 0x14) + iVar5;
  if (iVar4 < 0) {
    func_0x81094a54(iVar1,2);
  }
  else if (iVar5 < *(int *)(iVar1 + 0x1c)) {
    *(int *)(iVar1 + 0x14) = iVar4;
  }
  else {
    func_0x81094a54(iVar1,3);
  }
  iVar4 = FUN_810949a0(iVar1,*(undefined4 *)(iVar1 + 0xc),0);
  if (iVar4 != 0) {
    iVar4 = *(int *)(iVar1 + 0xc) +
            (*(uint *)(&UNK_8113846c +
                      (uint)*(byte *)(*(int *)(iVar1 + 0x44) + *(int *)(iVar1 + 0xc) + 1) * 0xc) &
            *(uint *)(iVar1 + 0x60));
    *(undefined4 *)(iVar1 + 0x38) =
         *(undefined4 *)(&UNK_81138470 + (uint)*(byte *)(*(int *)(iVar1 + 0x44) + iVar4 + 1) * 0xc);
    *(int *)(iVar1 + 0xc) = iVar4;
  }
  return 1;
}

