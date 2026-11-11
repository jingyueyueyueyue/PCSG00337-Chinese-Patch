
undefined4 FUN_8109800c(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x14) * 8;
  iVar2 = *(int *)(param_1 + 0x24);
  uVar1 = 1;
  if ((*(uint *)(iVar2 + iVar3) & 0xf) != 0) {
    uVar1 = (uint)(*(int *)(iVar2 + iVar3 + 4) == 0);
  }
  *(uint *)(iVar2 + iVar3) = *(uint *)(iVar2 + iVar3) & 0xffffff00 | 0x21;
  *(uint *)(iVar2 + iVar3 + 4) = uVar1;
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

