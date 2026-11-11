
undefined4 FUN_810978a6(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint in_fpscr;
  undefined4 uVar7;
  
  iVar1 = *(int *)(param_1 + 0x24);
  iVar2 = (*(int *)(param_1 + 0x14) + 1) * 8;
  iVar6 = *(int *)(param_1 + 0x14) * 8;
  uVar4 = *(uint *)(iVar1 + iVar2) & 0xf;
  iVar3 = iVar1 + iVar2;
  iVar5 = iVar1 + iVar6;
  if ((uVar4 == 2) || ((*(uint *)(iVar1 + iVar6) & 0xf) == 2)) {
    if (uVar4 != 2) {
      *(uint *)(iVar1 + iVar2) = *(uint *)(iVar1 + iVar2) & 0xfffffff0 | 2;
      uVar7 = VectorSignedToFloat(*(undefined4 *)(iVar3 + 4),(byte)(in_fpscr >> 0x15) & 3);
      *(undefined4 *)(iVar3 + 4) = uVar7;
    }
    if ((*(uint *)(iVar1 + iVar6) & 0xf) != 2) {
      *(uint *)(iVar1 + iVar6) = *(uint *)(iVar1 + iVar6) & 0xfffffff0 | 2;
      uVar7 = VectorSignedToFloat(*(undefined4 *)(iVar5 + 4),(byte)(in_fpscr >> 0x15) & 3);
      *(undefined4 *)(iVar5 + 4) = uVar7;
    }
    uVar4 = *(uint *)(iVar1 + iVar2) & 0xf;
  }
  if (uVar4 == 2) {
    *(float *)(iVar3 + 4) = *(float *)(iVar3 + 4) * *(float *)(iVar5 + 4);
    iVar1 = *(int *)(param_1 + 0x14);
  }
  else {
    *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) * *(int *)(iVar5 + 4);
    iVar1 = *(int *)(param_1 + 0x14);
  }
  if (iVar1 + 1 < 0) {
    func_0x81094a54(param_1,2);
  }
  else if (*(int *)(param_1 + 0x1c) < 2) {
    func_0x81094a54(param_1,3);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar1 + 1;
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

