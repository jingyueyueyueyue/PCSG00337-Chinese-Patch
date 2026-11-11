
undefined4 FUN_81099a24(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint unaff_r5;
  
  uVar1 = FUN_81095530(param_1,*(undefined4 *)
                                (*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x14) * 8 + 4));
  iVar3 = *(int *)(param_1 + 0x24);
  iVar2 = *(int *)(param_1 + 0x14) * 8;
  *(uint *)(iVar3 + iVar2) = unaff_r5 & 0xffffff00 | 100;
  *(undefined4 *)(iVar3 + iVar2 + 4) = uVar1;
  iVar2 = FUN_810949a0(param_1,*(undefined4 *)(param_1 + 0xc),0);
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_1 + 0xc) +
            (*(uint *)(&UNK_8113846c +
                      (uint)*(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) * 0xc)
            & *(uint *)(param_1 + 0x60));
    *(undefined4 *)(param_1 + 0x38) =
         *(undefined4 *)
          (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar2 + 1) * 0xc);
    *(int *)(param_1 + 0xc) = iVar2;
  }
  return 1;
}

