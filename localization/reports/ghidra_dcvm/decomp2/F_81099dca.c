
undefined4 FUN_81099dca(int param_1)

{
  int iVar1;
  int iVar2;
  uint in_fpscr;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x14) * 8;
  iVar2 = *(int *)(param_1 + 0x24);
  if ((*(uint *)(iVar2 + iVar1) & 0xf) != 2) {
    *(uint *)(iVar2 + iVar1) = *(uint *)(iVar2 + iVar1) & 0xfffffff0 | 2;
    uVar3 = VectorSignedToFloat(*(undefined4 *)(iVar2 + iVar1 + 4),(byte)(in_fpscr >> 0x15) & 3);
    *(undefined4 *)(iVar2 + iVar1 + 4) = uVar3;
  }
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

