
void FUN_81096398(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  FUN_810962f4();
  iVar2 = (*(int *)(param_1 + 0x14) + 1) * 8;
  if ((*(uint *)(*(int *)(param_1 + 0x24) + iVar2) & 0xf) == 1) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + iVar2 + 4) + 2;
    iVar3 = *(int *)(param_1 + 0x14) + iVar2;
    if (iVar3 < 0) {
      *(undefined **)(param_1 + 0x38) = &UNK_81096439;
      *(undefined4 *)(param_1 + 0x34) = 3;
    }
    else if (iVar2 < *(int *)(param_1 + 0x1c)) {
      *(int *)(param_1 + 0x14) = iVar3;
    }
    else {
      *(undefined **)(param_1 + 0x38) = &UNK_81096439;
      *(undefined4 *)(param_1 + 0x34) = 3;
    }
    iVar2 = FUN_810949a0(param_1,*(undefined4 *)(param_1 + 0xc),0);
    if (iVar2 != 0) {
      iVar2 = *(int *)(param_1 + 0xc) +
              (*(uint *)(&UNK_8113846c +
                        (uint)*(byte *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) *
                        0xc) & *(uint *)(param_1 + 0x60));
      bVar1 = *(byte *)(*(int *)(param_1 + 0x44) + iVar2 + 1);
      *(int *)(param_1 + 0xc) = iVar2;
      *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(&UNK_81138470 + (uint)bVar1 * 0xc);
    }
  }
  else {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
    *(undefined4 *)(param_1 + 0x34) = 3;
  }
  return;
}

