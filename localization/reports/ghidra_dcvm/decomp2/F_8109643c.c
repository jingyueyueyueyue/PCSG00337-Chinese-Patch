
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8109643c(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined auStack_18 [4];
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  if (*(int *)(param_1 + 0x4c) == 0) {
    uVar3 = 0;
  }
  else {
    func_0x810946e8(auStack_18,param_1);
    piVar4 = *(int **)(param_1 + 0x4c);
    pcVar1 = *(code **)(*piVar4 + 8);
    while (iVar2 = (*pcVar1)(piVar4,auStack_18), iVar2 < 3) {
      if (iVar2 < 1) goto LAB_810964aa;
      if (iVar2 < 2) {
        FUN_81096398(param_1);
        uVar3 = 0;
        goto LAB_810964b0;
      }
      piVar4 = *(int **)(param_1 + 0x4c);
      pcVar1 = *(code **)(*piVar4 + 8);
    }
    if (iVar2 < 4) {
      FUN_81096398(param_1);
      uVar3 = 1;
    }
    else if (iVar2 < 5) {
      FUN_810962f4(param_1);
      uVar3 = 1;
    }
    else {
LAB_810964aa:
      uVar3 = 0;
    }
  }
LAB_810964b0:
  if (_UNK_8111a5b0 != iStack_14) {
    func_0x811185a0(uVar3);
    return;
  }
  return;
}

