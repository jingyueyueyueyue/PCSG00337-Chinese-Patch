
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_8109c764(int **param_1,undefined4 param_2)

{
  bool bVar1;
  int **ppiVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  uint uStack_50;
  undefined auStack_4c [4];
  int iStack_48;
  int **ppiStack_40;
  undefined4 uStack_3c;
  int *piStack_38;
  undefined *puStack_34;
  int iStack_20;
  int iStack_1c;
  
  iStack_1c = _UNK_8111a5b0;
  func_0x8106986a(param_2,param_1 + 0x12,4);
  func_0x8106986a(param_2,param_1[0x14],(uint)(param_1[0x13] + 2) >> 3);
  piVar5 = param_1[2];
  iVar8 = 0;
  iStack_20 = 0;
  piVar6 = *param_1;
  for (; piVar5 != (int *)0x0; piVar5 = (int *)piVar5[1]) {
    if (piVar5[0xd] == 1) {
      iVar8 = iVar8 + 1;
      iStack_20 = iVar8;
    }
  }
  for (; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[1]) {
    if (piVar6[0xd] == 0) {
      iVar8 = iVar8 + 1;
      iStack_20 = iVar8;
    }
  }
  func_0x8106986a(param_2,&iStack_20,4);
  piVar5 = param_1[2];
  while (piVar5 != (int *)0x0) {
    if (piVar5[0xd] == 1) {
      func_0x810697dc(param_2,0,1);
      iVar8 = func_0x81094e9c(piVar5,param_2);
      if (iVar8 == 0) {
        bVar1 = false;
        goto LAB_8109c83c;
      }
    }
    if (piVar5 != (int *)0x0) {
      piVar5 = (int *)piVar5[1];
    }
  }
  param_1 = (int **)*param_1;
  while (param_1 != (int **)0x0) {
    if (param_1[0xd] == (int *)0x0) {
      func_0x810697dc(param_2,0,1);
      iVar8 = func_0x81094e9c(param_1,param_2);
      if (iVar8 == 0) {
        bVar1 = false;
        goto LAB_8109c83c;
      }
    }
    if (param_1 != (int **)0x0) {
      param_1 = (int **)param_1[1];
    }
  }
  bVar1 = true;
LAB_8109c83c:
  if (_UNK_8111a5b0 == iStack_1c) {
    return bVar1;
  }
  uVar9 = func_0x811185a0(bVar1);
  uVar4 = (undefined4)((ulonglong)uVar9 >> 0x20);
  ppiVar2 = (int **)uVar9;
  puStack_34 = &UNK_8111a5b0;
  iStack_48 = _UNK_8111a5b0;
  ppiStack_40 = param_1;
  uStack_3c = param_2;
  piStack_38 = piVar5;
  FUN_810698ea(uVar4,ppiVar2 + 0x12,4);
  FUN_810698ea(uVar4,ppiVar2[0x14],(uint)(ppiVar2[0x13] + 2) >> 3);
  FUN_810698ea(uVar4,&uStack_50,4);
  if (uStack_50 != 0) {
    uVar7 = 0;
    do {
      iVar8 = func_0x81005a98(100);
      piVar5 = (int *)0x0;
      if (iVar8 != 0) {
        piVar5 = (int *)FUN_81094940();
      }
      if (piVar5 == (int *)0x0) {
        bVar1 = false;
        goto LAB_8109c926;
      }
      piVar5[0x10] = (int)ppiVar2;
      FUN_810949fe(piVar5,0);
      iVar8 = func_0x81069828(uVar4,1);
      if (iVar8 != 0) {
        FUN_810698ea(uVar4,0,0);
      }
      iVar3 = func_0x81094fd6(piVar5,uVar4);
      if (iVar3 == 0) {
        FUN_81094e48(piVar5);
        func_0x81005af0();
        bVar1 = false;
        goto LAB_8109c926;
      }
      if (iVar8 != 0) {
        FUN_810698ea(uVar4,0,0);
        FUN_810698ea(uVar4,auStack_4c,4);
      }
      piVar6 = ppiVar2[1];
      if (piVar6 == (int *)0x0) {
        *piVar5 = 0;
        piVar5[1] = 0;
        *ppiVar2 = piVar5;
      }
      else {
        *piVar5 = (int)piVar6;
        piVar5[1] = 0;
        piVar6[1] = (int)piVar5;
      }
      uVar7 = uVar7 + 1;
      ppiVar2[1] = piVar5;
    } while (uVar7 < uStack_50);
  }
  bVar1 = true;
LAB_8109c926:
  if (_UNK_8111a5b0 == iStack_48) {
    return bVar1;
  }
  uVar9 = func_0x811185a0(bVar1);
  iVar3 = (int)((ulonglong)uVar9 >> 0x20);
  iVar8 = (int)uVar9;
  *(int *)(iVar8 + 0x4c) = iVar3;
  *(undefined *)(iVar8 + 0x54) = 0;
  uVar7 = iVar3 + 8U >> 3;
  iVar3 = func_0x81005aaa(uVar7);
  *(int *)(iVar8 + 0x50) = iVar3;
  if (iVar3 != 0) {
    func_0x8108d650(iVar3,0,uVar7);
    **(byte **)(iVar8 + 0x50) = **(byte **)(iVar8 + 0x50) | 1;
  }
  return iVar3 != 0;
}

