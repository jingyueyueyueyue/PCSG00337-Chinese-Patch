
undefined4 FUN_8109932a(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  iVar1 = iVar2 + 2;
  if (*(int *)(*(int *)(param_1 + 0x24) + (iVar2 + 1) * 8 + 4) == 0) {
    if (iVar1 < 0) {
      func_0x81094a54(param_1,2);
    }
    else if (*(int *)(param_1 + 0x1c) < 3) {
      func_0x81094a54(param_1,3);
    }
    else {
      *(int *)(param_1 + 0x14) = iVar1;
    }
    iVar1 = FUN_810949a0(param_1,*(undefined4 *)(param_1 + 0xc),0);
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0xc) +
              (*(uint *)(&UNK_8113846c +
                        (uint)*(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) *
                        0xc) & *(uint *)(param_1 + 0x60));
      *(undefined4 *)(param_1 + 0x38) =
           *(undefined4 *)
            (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar1 + 1) * 0xc);
      *(int *)(param_1 + 0xc) = iVar1;
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + iVar2 * 8 + 4);
    if (iVar1 < 0) {
      func_0x81094a54(param_1,2);
    }
    else if (*(int *)(param_1 + 0x1c) < 3) {
      func_0x81094a54(param_1,3);
    }
    else {
      *(int *)(param_1 + 0x14) = iVar1;
    }
    iVar1 = FUN_810949a0(param_1,iVar2,4);
    if (iVar1 != 0) {
      *(int *)(param_1 + 0xc) = iVar2;
      *(undefined4 *)(param_1 + 0x38) =
           *(undefined4 *)
            (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar2 + 1) * 0xc);
    }
  }
  return 1;
}

