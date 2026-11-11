
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_81094d4e(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined auStack_18 [4];
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  if (*(int *)(param_1 + 0x4c) != 0) {
    piVar1 = *(int **)(*(int *)(param_1 + 0x40) + 100);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))();
    }
    func_0x810946e8(auStack_18,param_1);
    (**(code **)(**(int **)(param_1 + 0x4c) + 0x10))(*(int **)(param_1 + 0x4c),auStack_18);
    *(undefined4 *)(param_1 + 0x4c) = 0;
    if (*(int *)(param_1 + 0x34) == 1) {
      iVar2 = *(int *)(param_1 + 0xc);
      if (iVar2 < 0) {
        *(undefined4 *)(param_1 + 0x38) = _UNK_81138470;
      }
      else {
        iVar4 = FUN_810949a0(param_1,iVar2,4);
        if (iVar4 != 0) {
          *(int *)(param_1 + 0xc) = iVar2;
          *(undefined4 *)(param_1 + 0x38) =
               *(undefined4 *)
                (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar2 + 1) * 0xc);
        }
      }
    }
    else {
      *(undefined **)(param_1 + 0x38) = &UNK_81096439;
    }
  }
  if ((*(int *)(param_1 + 0x34) == 2) && (*(int *)(param_1 + 0x24) != 0)) {
    iVar2 = *(int *)(param_1 + 0x10);
    iVar4 = *(int *)(param_1 + 0x1c);
    while ((iVar4 != iVar2 && (func_0x81094bac(param_1), *(int *)(param_1 + 0x28) != 0))) {
      iVar2 = *(int *)(param_1 + 0x10);
    }
  }
  *(undefined **)(param_1 + 0x38) = &UNK_81096439;
  *(undefined4 *)(param_1 + 0x34) = 0;
  if ((*(int *)(param_1 + 0x40) != 0) && (*(int *)(param_1 + 0x28) != 0)) {
    puVar3 = (undefined4 *)func_0x8109ca34();
    FUN_8109c108(*puVar3,*(undefined4 *)(param_1 + 0x28));
  }
  *(undefined **)(param_1 + 0x58) = &UNK_81138164;
  *(undefined4 *)(param_1 + 0x5c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  if (_UNK_8111a5b0 != iStack_14) {
    iVar2 = func_0x811185a0();
    FUN_81094d4e();
    if (((*(int *)(iVar2 + 0x40) != 0) &&
        (FUN_8109ce98(*(int *)(iVar2 + 0x40),*(undefined4 *)(iVar2 + 8)),
        *(int *)(iVar2 + 0x24) != 0)) &&
       (piVar1 = (int *)func_0x8109ce56(*(undefined4 *)(iVar2 + 0x40)), *(int *)(iVar2 + 0x24) != 0)
       ) {
      (**(code **)(*piVar1 + 0x10))();
    }
    return iVar2;
  }
  return _UNK_8111a5b0;
}

