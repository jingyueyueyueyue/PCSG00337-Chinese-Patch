
void FUN_810959ea(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = func_0x8109b4fe(*(undefined4 *)(param_1 + 0x28));
  if (((*(char *)(iVar1 + 4) != '\x04') && ((param_4 & 0x40000000) != 0)) &&
     (iVar1 = FUN_8109b50a(*(undefined4 *)(param_1 + 0x28),&UNK_81138178,1), iVar1 != -1)) {
    iVar2 = *(int *)(param_1 + 0x14);
    iVar4 = iVar2 + -1;
    if (iVar4 < 0) {
      *(undefined **)(param_1 + 0x38) = &UNK_81096439;
      *(undefined4 *)(param_1 + 0x34) = 3;
      iVar4 = iVar2;
    }
    else if (*(int *)(param_1 + 0x1c) < 0) {
      *(undefined **)(param_1 + 0x38) = &UNK_81096439;
      *(undefined4 *)(param_1 + 0x34) = 3;
      iVar4 = iVar2;
    }
    else {
      *(int *)(param_1 + 0x14) = iVar4;
    }
    iVar2 = *(int *)(param_1 + 0x24);
    iVar4 = iVar4 * 8;
    *(uint *)(iVar2 + iVar4) = *(uint *)(iVar2 + iVar4) & 0xffffff00 | 0x21;
    *(undefined4 *)(iVar2 + iVar4 + 4) = 0;
    iVar1 = func_0x8109b4fe(*(undefined4 *)(param_1 + 0x28),iVar1);
    func_0x810956d4(param_1,*(uint *)(*(int *)(param_1 + 0x28) + 0x74) | param_4 & 0xbfffffff);
    uVar3 = *(uint *)(iVar1 + 8) & 0xffffff;
    param_4 = param_4 & 0x7fffffff;
    iVar1 = func_0x810949a0(param_1,uVar3,4);
    if (iVar1 != 0) {
      *(uint *)(param_1 + 0xc) = uVar3;
      *(undefined4 *)(param_1 + 0x38) =
           *(undefined4 *)
            (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + uVar3 + 1) * 0xc);
    }
  }
  FUN_810957b2(param_1,param_2,param_3,param_4);
  return;
}

