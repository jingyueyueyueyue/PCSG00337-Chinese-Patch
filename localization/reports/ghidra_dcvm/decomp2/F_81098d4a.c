
undefined4 FUN_81098d4a(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x14) + -1;
  if (iVar1 < 0) {
    func_0x81094a54(param_1,2);
    iVar1 = *(int *)(param_1 + 0x14);
  }
  else if (*(int *)(param_1 + 0x1c) < 0) {
    func_0x81094a54(param_1,3);
    iVar1 = *(int *)(param_1 + 0x14);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  iVar2 = *(int *)(param_1 + 0x24);
  *(uint *)(iVar2 + iVar1 * 8) = param_1 & 0xffffff00 | 0x24;
  *(undefined4 *)(iVar2 + iVar1 * 8 + 4) = 0;
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
  return 1;
}

