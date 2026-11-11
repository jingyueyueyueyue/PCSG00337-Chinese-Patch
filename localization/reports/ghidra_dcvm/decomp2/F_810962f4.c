
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810962f4(int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int unaff_r5;
  undefined4 uVar8;
  undefined *puVar9;
  undefined auStack_18 [4];
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  func_0x810946e8(auStack_18,param_1);
  piVar5 = *(int **)(*(int *)(param_1 + 0x40) + 100);
  piVar2 = *(int **)(param_1 + 0x4c);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0xc))(piVar5,piVar2);
    piVar2 = *(int **)(param_1 + 0x4c);
  }
  (**(code **)(*piVar2 + 0x10))(piVar2,auStack_18);
  func_0x81094a76(param_1);
  *(undefined4 *)(param_1 + 0x4c) = 0;
  if (*(int *)(param_1 + 0x34) == 1) {
    unaff_r5 = *(int *)(param_1 + 0xc);
    if (unaff_r5 < 0) {
      *(undefined4 *)(param_1 + 0x38) = _UNK_81138470;
    }
    else {
      iVar3 = FUN_810949a0(param_1,unaff_r5,4);
      if (iVar3 != 0) {
        *(int *)(param_1 + 0xc) = unaff_r5;
        *(undefined4 *)(param_1 + 0x38) =
             *(undefined4 *)
              (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + unaff_r5 + 1) * 0xc);
      }
    }
  }
  else {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
  }
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  uVar8 = 0x81096397;
  iVar3 = func_0x811185a0();
  puVar9 = &UNK_8111a5b0;
  FUN_810962f4();
  iVar4 = (*(int *)(iVar3 + 0x14) + 1) * 8;
  uVar7 = *(uint *)(*(int *)(iVar3 + 0x24) + iVar4);
  if ((uVar7 & 0xf) == 1) {
    iVar4 = *(int *)(*(int *)(iVar3 + 0x24) + iVar4 + 4) + 2;
    iVar6 = *(int *)(iVar3 + 0x14) + iVar4;
    if (iVar6 < 0) {
      *(undefined **)(iVar3 + 0x38) = &UNK_81096439;
      *(undefined4 *)(iVar3 + 0x34) = 3;
    }
    else if (iVar4 < *(int *)(iVar3 + 0x1c)) {
      *(int *)(iVar3 + 0x14) = iVar6;
    }
    else {
      *(undefined **)(iVar3 + 0x38) = &UNK_81096439;
      *(undefined4 *)(iVar3 + 0x34) = 3;
    }
    iVar4 = FUN_810949a0(iVar3,*(undefined4 *)(iVar3 + 0xc),0,uVar7,param_1,unaff_r5,puVar9,uVar8);
    if (iVar4 != 0) {
      iVar4 = *(int *)(iVar3 + 0xc) +
              (*(uint *)(&UNK_8113846c +
                        (uint)*(byte *)(*(int *)(iVar3 + 0x44) + *(int *)(iVar3 + 0xc) + 1) * 0xc) &
              *(uint *)(iVar3 + 0x60));
      bVar1 = *(byte *)(*(int *)(iVar3 + 0x44) + iVar4 + 1);
      *(int *)(iVar3 + 0xc) = iVar4;
      *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(&UNK_81138470 + (uint)bVar1 * 0xc);
    }
  }
  else {
    *(undefined **)(iVar3 + 0x38) = &UNK_81096439;
    *(undefined4 *)(iVar3 + 0x34) = 3;
  }
  return;
}

