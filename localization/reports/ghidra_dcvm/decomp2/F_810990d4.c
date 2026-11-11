
undefined4 FUN_810990d4(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x14) + -1;
  uVar1 = *(ushort *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 2);
  if (iVar3 < 0) {
    func_0x81094a54(param_1,2);
    iVar3 = *(int *)(param_1 + 0x14);
  }
  else if (*(int *)(param_1 + 0x1c) < 0) {
    func_0x81094a54(param_1,3);
    iVar3 = *(int *)(param_1 + 0x14);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar3;
  }
  iVar2 = *(int *)(param_1 + 0x24);
  iVar3 = iVar3 * 8;
  *(uint *)(iVar2 + iVar3) = *(uint *)(iVar2 + iVar3) & 0xffffff00 | 0x21;
  *(uint *)(iVar2 + iVar3 + 4) = -(uint)uVar1;
  iVar3 = FUN_810949a0(param_1,*(undefined4 *)(param_1 + 0xc),0);
  if (iVar3 != 0) {
    iVar3 = *(int *)(param_1 + 0xc) +
            (*(uint *)(&UNK_8113846c +
                      (uint)*(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) * 0xc)
            & *(uint *)(param_1 + 0x60));
    *(undefined4 *)(param_1 + 0x38) =
         *(undefined4 *)
          (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar3 + 1) * 0xc);
    *(int *)(param_1 + 0xc) = iVar3;
  }
  return 1;
}

