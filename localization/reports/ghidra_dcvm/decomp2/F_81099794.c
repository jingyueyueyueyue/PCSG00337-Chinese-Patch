
undefined4 FUN_81099794(int param_1)

{
  byte bVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar2 = (uint *)FUN_8109548c(param_1,*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x14) * 8);
  if (puVar2 == (uint *)0x0) {
    uVar3 = 0;
  }
  else {
    *puVar2 = *(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 2) & 0xf |
              *puVar2 & 0xfffffff0;
    iVar4 = FUN_810949a0(param_1,*(undefined4 *)(param_1 + 0xc),0);
    if (iVar4 != 0) {
      iVar4 = *(int *)(param_1 + 0xc) +
              (*(uint *)(&UNK_8113846c +
                        (uint)*(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) *
                        0xc) & *(uint *)(param_1 + 0x60));
      bVar1 = *(byte *)(*(int *)(param_1 + 0x44) + iVar4 + 1);
      *(int *)(param_1 + 0xc) = iVar4;
      *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(&UNK_81138470 + (uint)bVar1 * 0xc);
    }
    uVar3 = 1;
  }
  return uVar3;
}

