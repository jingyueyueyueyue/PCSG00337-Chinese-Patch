
void FUN_810955b0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x14);
  iVar2 = iVar3 + -1;
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x74);
  if (iVar2 < 0) {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
    *(undefined4 *)(param_1 + 0x34) = 3;
    iVar2 = iVar3;
  }
  else if (*(int *)(param_1 + 0x1c) < 0) {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
    *(undefined4 *)(param_1 + 0x34) = 3;
    iVar2 = iVar3;
  }
  else {
    *(int *)(param_1 + 0x14) = iVar2;
  }
  FUN_810964c8(*(int *)(param_1 + 0x24) + iVar2 * 8,uVar1,param_2);
  func_0x8109b066(*(undefined4 *)(param_1 + 0x28),param_2);
  return;
}

