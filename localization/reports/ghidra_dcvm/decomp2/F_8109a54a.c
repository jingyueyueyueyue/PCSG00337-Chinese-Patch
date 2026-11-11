
undefined4 FUN_8109a54a(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x14) * 8;
  iVar3 = *(int *)(param_1 + 0x14) + 1;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(*(int *)(param_1 + 0x24) + iVar2);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(*(int *)(param_1 + 0x24) + iVar2 + 4);
  if (iVar3 < 0) {
    func_0x81094a54(param_1,2);
  }
  else if (*(int *)(param_1 + 0x1c) < 2) {
    func_0x81094a54(param_1,3);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar3;
  }
  iVar2 = FUN_810949a0(param_1,*(undefined4 *)(param_1 + 0xc),0);
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_1 + 0xc) +
            (*(uint *)(&UNK_8113846c +
                      (uint)*(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) * 0xc)
            & *(uint *)(param_1 + 0x60));
    bVar1 = *(byte *)(*(int *)(param_1 + 0x44) + iVar2 + 1);
    *(int *)(param_1 + 0xc) = iVar2;
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(&UNK_81138470 + (uint)bVar1 * 0xc);
  }
  return 1;
}

