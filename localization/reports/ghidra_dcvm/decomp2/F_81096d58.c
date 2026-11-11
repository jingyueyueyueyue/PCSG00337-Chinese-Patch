
undefined4 FUN_81096d58(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x24) + (*(int *)(param_1 + 0x14) + 1) * 8 + 4);
  if (*(int *)(param_1 + 8) == iVar3) {
    FUN_810949fe(param_1,2);
  }
  else {
    uVar2 = func_0x81094fd2(param_1);
    iVar3 = func_0x8109cf2a(uVar2,iVar3);
    if (iVar3 != 0) {
      FUN_810949fe(iVar3,2);
    }
  }
  iVar3 = *(int *)(param_1 + 0x14) + 2;
  if (iVar3 < 0) {
    func_0x81094a54(param_1,2);
  }
  else if (*(int *)(param_1 + 0x1c) < 3) {
    func_0x81094a54(param_1,3);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar3;
  }
  iVar3 = FUN_810949a0(param_1,*(undefined4 *)(param_1 + 0xc),0);
  if (iVar3 != 0) {
    iVar3 = *(int *)(param_1 + 0xc) +
            (*(uint *)(&UNK_8113846c +
                      (uint)*(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) * 0xc)
            & *(uint *)(param_1 + 0x60));
    bVar1 = *(byte *)(*(int *)(param_1 + 0x44) + iVar3 + 1);
    *(int *)(param_1 + 0xc) = iVar3;
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(&UNK_81138470 + (uint)bVar1 * 0xc);
  }
  return 1;
}

