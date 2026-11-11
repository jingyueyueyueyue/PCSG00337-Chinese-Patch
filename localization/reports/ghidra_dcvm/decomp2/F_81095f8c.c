
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81095f8c(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  code *pcVar8;
  undefined8 uVar9;
  uint uStack_20;
  int iStack_1c;
  
  puVar7 = &uStack_20;
  iStack_1c = _UNK_8111a5b0;
  iVar1 = func_0x8109b4f2(*(undefined4 *)(param_1 + 0x28));
  if ((*(uint *)(iVar1 + 8) & 1) == 0) {
    func_0x81095ad2(param_1,param_2);
  }
  iVar1 = FUN_8109a5e4(iVar1);
  *(int *)(param_1 + 0x4c) = iVar1;
  if (*(int *)(param_1 + 0x34) == 1) {
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0x38) = _UNK_81138470;
      }
      else {
        iVar4 = FUN_810949a0(param_1,iVar1,4);
        if (iVar4 != 0) {
          *(int *)(param_1 + 0xc) = iVar1;
          *(undefined4 *)(param_1 + 0x38) =
               *(undefined4 *)
                (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar1 + 1) * 0xc);
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x38) = 0x8109643d;
    }
  }
  else {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
  }
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x14);
  func_0x810956d4(param_1,*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x74));
  func_0x810946e8(&uStack_20,param_1);
  piVar2 = *(int **)(*(int *)(param_1 + 0x40) + 100);
  piVar6 = *(int **)(param_1 + 0x4c);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))();
    piVar6 = *(int **)(param_1 + 0x4c);
  }
  pcVar8 = *(code **)(*piVar6 + 0xc);
  (*pcVar8)(piVar6,&uStack_20);
  if (_UNK_8111a5b0 == iStack_1c) {
    return;
  }
  uVar9 = func_0x811185a0();
  iVar1 = (int)uVar9;
  puVar3 = (undefined4 *)func_0x8109ca34(*(undefined4 *)(iVar1 + 0x40));
  iVar4 = func_0x8109c2ae(*puVar3,(int)((ulonglong)uVar9 >> 0x20));
  if (iVar4 == 0) {
    *(undefined **)(iVar1 + 0x38) = &UNK_81096439;
    *(undefined4 *)(iVar1 + 0x34) = 3;
  }
  else {
    iVar5 = FUN_8109b50a(iVar4,&UNK_81138184,3);
    if (iVar5 != -1) {
      FUN_81095cfa(iVar1,iVar4,&UNK_81138184,puVar7,pcVar8,0x40000000,uStack_20 & 0xff);
    }
  }
  return;
}

