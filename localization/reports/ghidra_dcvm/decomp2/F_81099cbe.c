
undefined4 FUN_81099cbe(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x14) * 8 + 4);
  if (((int)uVar3 < 0) ||
     (*(uint *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 2) <= uVar3)) {
    func_0x81094a54(param_1,0x1e);
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_810949a0(param_1,*(int *)(param_1 + 0xc),0);
    if (iVar2 != 0) {
      iVar2 = *(int *)(param_1 + 0xc) +
              (*(uint *)(&UNK_8113846c +
                        (uint)*(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) *
                        0xc) & *(uint *)(param_1 + 0x60));
      *(undefined4 *)(param_1 + 0x38) =
           *(undefined4 *)
            (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar2 + 1) * 0xc);
      *(int *)(param_1 + 0xc) = iVar2;
    }
    uVar1 = 1;
  }
  return uVar1;
}

