
undefined4 FUN_810993f6(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(param_1 + 0x14);
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x24) + iVar2 * 8 + 4);
  uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x24) + (iVar2 + 1) * 8 + 4);
  if (iVar2 + 2 < 0) {
    func_0x81094a54(param_1,2);
  }
  else if (*(int *)(param_1 + 0x1c) < 3) {
    func_0x81094a54(param_1,3);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar2 + 2;
  }
  iVar2 = func_0x810949a0(param_1,*(undefined4 *)(param_1 + 0xc),0);
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_1 + 0xc) +
            (*(uint *)(&UNK_8113846c +
                      (uint)*(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) * 0xc)
            & *(uint *)(param_1 + 0x60));
    bVar1 = *(byte *)(*(int *)(param_1 + 0x44) + iVar2 + 1);
    *(int *)(param_1 + 0xc) = iVar2;
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(&UNK_81138470 + (uint)bVar1 * 0xc);
  }
  FUN_810959ea(param_1,uVar4,uVar3,0);
  return 1;
}

