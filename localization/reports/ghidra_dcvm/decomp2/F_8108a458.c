
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108a458(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int **ppiVar3;
  int **ppiVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int **ppiVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  int *piStack_b0;
  int *piStack_ac;
  int *piStack_a8;
  int *piStack_a4;
  int *piStack_a0;
  int *piStack_9c;
  int iStack_98;
  int *piStack_94;
  int *piStack_90;
  int *piStack_8c;
  int *piStack_88;
  int **ppiStack_84;
  int **ppiStack_80;
  int **ppiStack_7c;
  undefined *puStack_78;
  int *piStack_60;
  int *piStack_5c;
  int *piStack_58;
  undefined4 *puStack_54;
  undefined4 *puStack_50;
  undefined4 *puStack_4c;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
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
  puVar9 = param_1 + 2;
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
  if (puVar9 != &uStack_20) {
    FUN_8107db94(puVar9);
    param_1[2] = uStack_20;
    param_1[3] = uStack_1c;
  }
  uStack_1c = 0;
  uStack_20 = 0;
  FUN_8107db94(&uStack_20);
  if (_UNK_8111a5b0 == piStack_18) {
    return;
  }
  uVar14 = 0x8108a4cd;
  puVar2 = (undefined4 *)func_0x811185a0();
  puStack_28 = &UNK_8111a5b0;
  piStack_38 = _UNK_8111a5b0;
  uStack_40 = 0;
  uStack_3c = 0;
  puVar10 = puVar2 + 2;
  puStack_34 = param_1;
  puStack_30 = puVar9;
  puStack_2c = &uStack_20;
  uStack_24 = uVar14;
  if (puVar2 != &uStack_40) {
    puStack_2c = &uStack_20;
    FUN_8107db94(puVar2);
    *puVar2 = uStack_40;
    puVar2[1] = uStack_3c;
  }
  uStack_3c = 0;
  uStack_40 = 0;
  FUN_8107db94(&uStack_40);
  uStack_40 = 0;
  uStack_3c = 0;
  if (puVar10 != &uStack_40) {
    FUN_8107db94(puVar10);
    puVar2[2] = uStack_40;
    puVar2[3] = uStack_3c;
  }
  uStack_3c = 0;
  uStack_40 = 0;
  FUN_8107db94(&uStack_40);
  FUN_8107db94(puVar10);
  FUN_8107db94(puVar2);
  if (_UNK_8111a5b0 == piStack_38) {
    return;
  }
  uVar14 = 0x8108a551;
  ppiVar3 = (int **)func_0x811185a0(puVar2);
  puStack_48 = &UNK_8111a5b0;
  piStack_58 = _UNK_8111a5b0;
  piStack_60 = (int *)0x0;
  piStack_5c = (int *)0x0;
  ppiVar11 = ppiVar3 + 2;
  puStack_54 = puVar2;
  puStack_50 = puVar10;
  puStack_4c = &uStack_40;
  uStack_44 = uVar14;
  if (ppiVar3 != &piStack_60) {
    puStack_4c = &uStack_40;
    FUN_8107db94(ppiVar3);
    *ppiVar3 = piStack_60;
    ppiVar3[1] = piStack_5c;
  }
  piStack_5c = (int *)0x0;
  piStack_60 = (int *)0x0;
  FUN_8107db94(&piStack_60);
  piStack_60 = (int *)0x0;
  piStack_5c = (int *)0x0;
  if (ppiVar11 != &piStack_60) {
    FUN_8107db94(ppiVar11);
    ppiVar3[2] = piStack_60;
    ppiVar3[3] = piStack_5c;
  }
  piStack_5c = (int *)0x0;
  piStack_60 = (int *)0x0;
  FUN_8107db94(&piStack_60);
  FUN_8107db94(ppiVar11);
  FUN_8107db94(ppiVar3);
  if (_UNK_8111a5b0 == piStack_58) {
    return;
  }
  piVar8 = piStack_58;
  uVar15 = func_0x811185a0(ppiVar3);
  piVar1 = piStack_60;
  piVar6 = (int *)((ulonglong)uVar15 >> 0x20);
  ppiVar4 = (int **)uVar15;
  puStack_78 = &UNK_8111a5b0;
  piStack_88 = _UNK_8111a5b0;
  piStack_a0 = (int *)0x0;
  piStack_9c = (int *)0x0;
  ppiStack_84 = ppiVar3;
  ppiStack_80 = ppiVar11;
  ppiStack_7c = &piStack_60;
  if (ppiVar4 != &piStack_a0) {
    ppiStack_7c = &piStack_60;
    FUN_8107db94(ppiVar4);
    *ppiVar4 = piStack_a0;
    ppiVar4[1] = piStack_9c;
  }
  piStack_9c = (int *)0x0;
  piStack_a0 = (int *)0x0;
  FUN_8107db94(&piStack_a0);
  piStack_a0 = (int *)0x0;
  piStack_9c = (int *)0x0;
  ppiVar3 = ppiVar4 + 2;
  if (ppiVar3 != &piStack_a0) {
    FUN_8107db94(ppiVar3);
    ppiVar4[2] = piStack_a0;
    ppiVar4[3] = piStack_9c;
  }
  piStack_9c = (int *)0x0;
  piStack_a0 = (int *)0x0;
  piStack_90 = piVar8;
  piStack_8c = piVar6;
  FUN_8107db94(&piStack_a0);
  piStack_94 = (int *)((int)piVar6 + 0x1fU & 0xffffffe0);
  iVar5 = ((int)piVar8 + 0x1fU & 0xffffffe0) * (int)piStack_94;
  if (param_4 == 0x2444000) {
    iVar13 = 2;
    iVar12 = 0;
LAB_8108a6c4:
    iVar7 = iVar13 * iVar5;
    if (iVar7 == 0) {
      iVar7 = 1;
    }
    iStack_98 = iVar5;
    piStack_ac = (int *)(**(code **)(*piVar1 + 0xc))(piVar1,iVar7,piVar1 + 9,piVar1[1]);
    piStack_b0 = piVar1;
    if (ppiVar4 != &piStack_b0) {
      FUN_8107db94(ppiVar4);
      *ppiVar4 = piStack_b0;
      ppiVar4[1] = piStack_ac;
      piStack_b0 = (int *)0x0;
      piStack_ac = (int *)0x0;
    }
    FUN_8107db94(&piStack_b0);
    if (iVar12 == 0) goto LAB_8108a748;
  }
  else {
    if (param_4 == 0x1266000) {
      iVar13 = 4;
      iVar12 = 0;
      goto LAB_8108a6c4;
    }
    if (param_4 == 0xee000) {
LAB_8108a6ae:
      iVar13 = 4;
      iVar12 = 1;
      goto LAB_8108a6c4;
    }
    if (param_4 == 0xcc000) {
LAB_8108a69c:
      iVar13 = 4;
      iVar12 = 0;
      goto LAB_8108a6c4;
    }
    if (param_4 == 0x66000) goto LAB_8108a6ae;
    if (param_4 == 0x44000) goto LAB_8108a69c;
    iVar12 = 0;
    iVar13 = 0;
    if (param_4 != 0x22000) goto LAB_8108a748;
    iVar12 = 1;
    iVar13 = 0;
    iStack_98 = iVar5;
  }
  iVar5 = iStack_98 * iVar12;
  if (iVar5 == 0) {
    iVar5 = 1;
  }
  piStack_a4 = (int *)(**(code **)(*piVar1 + 0xc))(piVar1,iVar5,piVar1 + 9,piVar1[1]);
  piStack_a8 = piVar1;
  if (ppiVar3 != &piStack_a8) {
    FUN_8107db94(ppiVar3);
    ppiVar4[2] = piStack_a8;
    ppiVar4[3] = piStack_a4;
    piStack_a8 = (int *)0x0;
    piStack_a4 = (int *)0x0;
  }
  FUN_8107db94(&piStack_a8);
LAB_8108a748:
  iVar5 = func_0x81116b90(ppiVar4 + 4,param_4,0x11000,piStack_94,ppiVar4[1],ppiVar4[3]);
  if (iVar5 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  ppiVar4[9] = piStack_8c;
  ppiVar4[10] = piStack_90;
  ppiVar4[0xb] = (int *)((iVar13 + iVar12) * 8);
  ppiVar4[0xc] = piStack_94;
  if (_UNK_8111a5b0 != piStack_88) {
    func_0x811185a0();
    return;
  }
  return;
}

