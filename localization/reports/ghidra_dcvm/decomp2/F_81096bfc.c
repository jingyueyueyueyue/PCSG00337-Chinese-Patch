
void FUN_81096bfc(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x14) + 1;
  if (iVar1 < 0) {
    func_0x81094a54(param_1,2);
  }
  else if (*(int *)(param_1 + 0x1c) < 2) {
    func_0x81094a54(param_1,3);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  uVar2 = 0;
  iVar1 = FUN_810949a0(param_1,*(undefined4 *)(param_1 + 0xc));
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 0xc) +
            (*(uint *)(&UNK_8113846c +
                      (uint)*(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) * 0xc)
            & *(uint *)(param_1 + 0x60));
    uVar2 = *(uint *)(&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar1 + 1) * 0xc);
    *(uint *)(param_1 + 0x38) = uVar2;
    *(int *)(param_1 + 0xc) = iVar1;
  }
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 8);
  *(uint *)(param_1 + 0x2c) = uVar2 & 0xffffff00 | 0x21;
  return;
}

