
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108a4ce(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int **ppiVar2;
  int **ppiVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int **ppiVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  int *piStack_90;
  int *piStack_8c;
  int *piStack_88;
  int *piStack_84;
  int *piStack_80;
  int *piStack_7c;
  int iStack_78;
  int *piStack_74;
  int *piStack_70;
  int *piStack_6c;
  int *piStack_68;
  int **ppiStack_64;
  int **ppiStack_60;
  int **ppiStack_5c;
  undefined *puStack_58;
  int *piStack_40;
  int *piStack_3c;
  int *piStack_38;
  undefined4 *puStack_34;
  undefined4 *puStack_30;
  undefined4 *puStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  
  piStack_18 = _UNK_8111a5b0;
  uStack_20 = 0;
  uStack_1c = 0;
  puVar8 = param_1 + 2;
  if (param_1 != &uStack_20) {
    FUN_8107db94(param_1);
    *param_1 = uStack_20;
    param_1[1] = uStack_1c;
  }
  uStack_1c = 0;
  uStack_20 = 0;
  FUN_8107db94(&uStack_20);
  uStack_20 = 0;
  uStack_1c = 0;
  if (puVar8 != &uStack_20) {
    FUN_8107db94(puVar8);
    param_1[2] = uStack_20;
    param_1[3] = uStack_1c;
  }
  uStack_1c = 0;
  uStack_20 = 0;
  FUN_8107db94(&uStack_20);
  FUN_8107db94(puVar8);
  FUN_8107db94(param_1);
  if (_UNK_8111a5b0 == piStack_18) {
    return;
  }
  uVar12 = 0x8108a551;
  ppiVar2 = (int **)func_0x811185a0(param_1);
  puStack_28 = &UNK_8111a5b0;
  piStack_38 = _UNK_8111a5b0;
  piStack_40 = (int *)0x0;
  piStack_3c = (int *)0x0;
  ppiVar9 = ppiVar2 + 2;
  puStack_34 = param_1;
  puStack_30 = puVar8;
  puStack_2c = &uStack_20;
  uStack_24 = uVar12;
  if (ppiVar2 != &piStack_40) {
    puStack_2c = &uStack_20;
    FUN_8107db94(ppiVar2);
    *ppiVar2 = piStack_40;
    ppiVar2[1] = piStack_3c;
  }
  piStack_3c = (int *)0x0;
  piStack_40 = (int *)0x0;
  FUN_8107db94(&piStack_40);
  piStack_40 = (int *)0x0;
  piStack_3c = (int *)0x0;
  if (ppiVar9 != &piStack_40) {
    FUN_8107db94(ppiVar9);
    ppiVar2[2] = piStack_40;
    ppiVar2[3] = piStack_3c;
  }
  piStack_3c = (int *)0x0;
  piStack_40 = (int *)0x0;
  FUN_8107db94(&piStack_40);
  FUN_8107db94(ppiVar9);
  FUN_8107db94(ppiVar2);
  if (_UNK_8111a5b0 == piStack_38) {
    return;
  }
  piVar7 = piStack_38;
  uVar13 = func_0x811185a0(ppiVar2);
  piVar1 = piStack_40;
  piVar5 = (int *)((ulonglong)uVar13 >> 0x20);
  ppiVar3 = (int **)uVar13;
  puStack_58 = &UNK_8111a5b0;
  piStack_68 = _UNK_8111a5b0;
  piStack_80 = (int *)0x0;
  piStack_7c = (int *)0x0;
  ppiStack_64 = ppiVar2;
  ppiStack_60 = ppiVar9;
  ppiStack_5c = &piStack_40;
  if (ppiVar3 != &piStack_80) {
    ppiStack_5c = &piStack_40;
    FUN_8107db94(ppiVar3);
    *ppiVar3 = piStack_80;
    ppiVar3[1] = piStack_7c;
  }
  piStack_7c = (int *)0x0;
  piStack_80 = (int *)0x0;
  FUN_8107db94(&piStack_80);
  piStack_80 = (int *)0x0;
  piStack_7c = (int *)0x0;
  ppiVar2 = ppiVar3 + 2;
  if (ppiVar2 != &piStack_80) {
    FUN_8107db94(ppiVar2);
    ppiVar3[2] = piStack_80;
    ppiVar3[3] = piStack_7c;
  }
  piStack_7c = (int *)0x0;
  piStack_80 = (int *)0x0;
  piStack_70 = piVar7;
  piStack_6c = piVar5;
  FUN_8107db94(&piStack_80);
  piStack_74 = (int *)((int)piVar5 + 0x1fU & 0xffffffe0);
  iVar4 = ((int)piVar7 + 0x1fU & 0xffffffe0) * (int)piStack_74;
  if (param_4 == 0x2444000) {
    iVar11 = 2;
    iVar10 = 0;
LAB_8108a6c4:
    iVar6 = iVar11 * iVar4;
    if (iVar6 == 0) {
      iVar6 = 1;
    }
    iStack_78 = iVar4;
    piStack_8c = (int *)(**(code **)(*piVar1 + 0xc))(piVar1,iVar6,piVar1 + 9,piVar1[1]);
    piStack_90 = piVar1;
    if (ppiVar3 != &piStack_90) {
      FUN_8107db94(ppiVar3);
      *ppiVar3 = piStack_90;
      ppiVar3[1] = piStack_8c;
      piStack_90 = (int *)0x0;
      piStack_8c = (int *)0x0;
    }
    FUN_8107db94(&piStack_90);
    if (iVar10 == 0) goto LAB_8108a748;
  }
  else {
    if (param_4 == 0x1266000) {
      iVar11 = 4;
      iVar10 = 0;
      goto LAB_8108a6c4;
    }
    if (param_4 == 0xee000) {
LAB_8108a6ae:
      iVar11 = 4;
      iVar10 = 1;
      goto LAB_8108a6c4;
    }
    if (param_4 == 0xcc000) {
LAB_8108a69c:
      iVar11 = 4;
      iVar10 = 0;
      goto LAB_8108a6c4;
    }
    if (param_4 == 0x66000) goto LAB_8108a6ae;
    if (param_4 == 0x44000) goto LAB_8108a69c;
    iVar10 = 0;
    iVar11 = 0;
    if (param_4 != 0x22000) goto LAB_8108a748;
    iVar10 = 1;
    iVar11 = 0;
    iStack_78 = iVar4;
  }
  iVar4 = iStack_78 * iVar10;
  if (iVar4 == 0) {
    iVar4 = 1;
  }
  piStack_84 = (int *)(**(code **)(*piVar1 + 0xc))(piVar1,iVar4,piVar1 + 9,piVar1[1]);
  piStack_88 = piVar1;
  if (ppiVar2 != &piStack_88) {
    FUN_8107db94(ppiVar2);
    ppiVar3[2] = piStack_88;
    ppiVar3[3] = piStack_84;
    piStack_88 = (int *)0x0;
    piStack_84 = (int *)0x0;
  }
  FUN_8107db94(&piStack_88);
LAB_8108a748:
  iVar4 = func_0x81116b90(ppiVar3 + 4,param_4,0x11000,piStack_74,ppiVar3[1],ppiVar3[3]);
  if (iVar4 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  ppiVar3[9] = piStack_6c;
  ppiVar3[10] = piStack_70;
  ppiVar3[0xb] = (int *)((iVar11 + iVar10) * 8);
  ppiVar3[0xc] = piStack_74;
  if (_UNK_8111a5b0 != piStack_68) {
    func_0x811185a0();
    return;
  }
  return;
}

