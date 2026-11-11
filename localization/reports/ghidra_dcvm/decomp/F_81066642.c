
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ** FUN_81066642(int **param_1,int **param_2)

{
  int iVar1;
  int **ppiVar2;
  int **ppiVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  int **ppiVar10;
  int **ppiVar11;
  int **ppiVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  short asStack_b0 [2];
  undefined auStack_ac [4];
  int iStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  int iStack_9c;
  undefined auStack_98 [8];
  undefined4 uStack_90;
  int iStack_8c;
  int iStack_88;
  int *piStack_84;
  int **ppiStack_80;
  int **ppiStack_7c;
  int **ppiStack_78;
  int **ppiStack_74;
  int **ppiStack_70;
  int iStack_6c;
  int **ppiStack_68;
  undefined4 uStack_64;
  int **ppiStack_60;
  int **ppiStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  short asStack_50 [2];
  undefined auStack_4c [4];
  int iStack_48;
  undefined4 uStack_44;
  int *piStack_40;
  int **ppiStack_3c;
  undefined auStack_38 [8];
  int **ppiStack_30;
  int iStack_2c;
  
  iVar13 = iRam811ae688;
  iStack_2c = _UNK_8111a5b0;
  ppiVar11 = (int **)0x0;
  *(undefined *)((int)param_1 + 0x3e) = 0;
  ppiVar12 = (int **)0x1;
  param_1[4] = (int *)0x1;
  piVar6 = (int *)(iVar13 + 100);
  param_1[5] = (int *)0x0;
  iVar1 = func_0x8107b558(piVar6);
  if ((iVar1 == 0) || (iVar1 = func_0x8107b846(piVar6,param_2,auStack_4c), iVar1 == 0)) {
    ppiVar10 = (int **)0x0;
    if (iVar13 != 0) {
      ppiVar10 = (int **)(iVar13 + 4);
    }
    ppiVar2 = ppiVar10 + 1;
    (*(code *)ppiVar10[1][2])(ppiVar2);
    iVar1 = 0;
    if (iVar13 != 0) {
      iVar1 = iVar13 + 4;
    }
    if (*(int *)(iVar1 + 0x10) == 0) {
      (*(code *)ppiVar10[1][3])(ppiVar2);
      ppiVar3 = (int **)0x0;
      piVar8 = (int *)0x0;
      goto LAB_810668b0;
    }
    ppiVar11 = param_1 + 0xc;
    uVar7 = **(undefined4 **)(*(int *)(iVar1 + 0x10) + 0x1c);
    if (piRam81191264 == param_1[0xc]) {
      iStack_48 = 0;
      uStack_44 = 0;
      ppiStack_60 = ppiVar11;
      iVar1 = FUN_810a15b8(uVar7,&iStack_48,&uStack_44,param_2);
      if (iVar1 != 0) {
        param_1[0xc] = *(int **)(iStack_48 + 0x28);
      }
    }
    ppiStack_30 = ppiVar11;
    uVar7 = func_0x810a15ac(uVar7);
    iVar1 = func_0x81078072(uVar7,param_2,ppiVar11,1);
    if (iVar1 == 0) {
      *(undefined *)(param_1 + 0xf) = 1;
      param_1[6] = (int *)0x4;
      (*(code *)ppiVar10[1][3])(ppiVar2);
      ppiVar3 = (int **)0x0;
      piVar8 = (int *)0x0;
      goto LAB_810668b0;
    }
    (*(code *)ppiVar10[1][3])(ppiVar2);
    piVar6 = param_1[0xd];
    iVar14 = func_0x810c8324((int)piVar6 + iVar1 + -1,piVar6);
    iVar14 = iVar14 * (int)piVar6;
    piVar6 = *param_1;
    ppiVar12 = param_1 + 7;
    iVar1 = iVar14;
    if (iVar14 == 0) {
      iVar1 = 1;
    }
    ppiVar11 = ppiVar12;
    if (ppiVar12 == (int **)0x0) {
      ppiVar11 = (int **)(piVar6 + 9);
    }
    piVar6 = (int *)(**(code **)(*piVar6 + 0xc))(piVar6,iVar1,ppiVar11,piVar6[1]);
    param_1[0xe] = piVar6;
    while (piVar6 == (int *)0x0) {
      piVar6 = *param_1;
      iVar1 = iVar14;
      if (iVar14 == 0) {
        iVar1 = 1;
      }
      ppiVar11 = ppiVar12;
      if (ppiVar12 == (int **)0x0) {
        ppiVar11 = (int **)(piVar6 + 9);
      }
      piVar6 = (int *)(**(code **)(*piVar6 + 0xc))(piVar6,iVar1,ppiVar11,piVar6[1]);
      param_1[0xe] = piVar6;
      (**(code **)(**param_1 + 8))(*param_1);
      func_0x8108cfd4(1000);
      piVar6 = param_1[0xe];
    }
    ppiVar11 = (int **)(iVar13 + 4);
    ppiVar12 = param_1 + 4;
    while( true ) {
      ppiVar2 = (int **)0x0;
      if (iVar13 != 0) {
        ppiVar2 = ppiVar11;
      }
      ppiVar10 = ppiVar2 + 1;
      (*(code *)ppiVar2[1][2])(ppiVar10);
      piVar8 = param_1[0xe];
      ppiVar3 = (int **)0x0;
      if (iVar13 != 0) {
        ppiVar3 = ppiVar11;
      }
      if (ppiVar3[4] == (int *)0x0) {
        (*(code *)ppiVar2[1][3])(ppiVar10);
        ppiVar3 = (int **)0x0;
        goto LAB_810668b0;
      }
      ppiStack_5c = ppiStack_30;
      piVar6 = (int *)0x1;
      uStack_58 = 0;
      uStack_54 = 1;
      ppiStack_60 = param_2;
      FUN_810a1fa2(asStack_50,*(undefined4 *)ppiVar3[4][7],ppiVar12,piVar8);
      *(short *)(param_1 + 3) = asStack_50[0];
      if (asStack_50[0] != 0) break;
      func_0x8108cfd4(100);
      (*(code *)ppiVar2[1][3])(ppiVar10);
    }
    (*(code *)ppiVar2[1][3])(ppiVar10);
    *(undefined *)(param_1 + 0xf) = 1;
    param_1[6] = (int *)0x3;
  }
  else {
    iVar13 = 0;
    piStack_40 = *param_1;
    ppiVar10 = param_1 + 1;
    ppiVar11 = param_1 + 7;
    do {
      ppiStack_60 = ppiVar11;
      func_0x8107bd82(auStack_38,piVar6,param_2,piStack_40);
      ppiVar2 = (int **)func_0x8107db88(auStack_38);
      if (ppiVar2 == (int **)0x0) {
        func_0x8108cfd4(1000);
        (**(code **)(**param_1 + 8))();
      }
      func_0x8107db94(auStack_38);
      piStack_40 = *param_1;
    } while (ppiVar2 == (int **)0x0);
    ppiStack_3c = ppiVar2;
    if (ppiVar10 != &piStack_40) {
      func_0x8107db94(ppiVar10);
      param_1[1] = piStack_40;
      param_1[2] = (int *)ppiStack_3c;
      piStack_40 = (int *)0x0;
      ppiStack_3c = (int **)0x0;
    }
    func_0x8107db94(&piStack_40);
    *(undefined *)((int)param_1 + 0x3e) = 1;
    param_1[4] = (int *)0x0;
    param_1[5] = (int *)0x0;
  }
  ppiVar3 = (int **)0x1;
  piVar8 = piVar6;
  ppiVar12 = ppiVar3;
LAB_810668b0:
  if (_UNK_8111a5b0 == iStack_2c) {
    return ppiVar3;
  }
  uVar15 = 0x810668cb;
  uVar16 = func_0x811185a0(ppiVar3);
  iVar1 = iRam811ae688;
  uVar7 = (undefined4)((ulonglong)uVar16 >> 0x20);
  puVar4 = (undefined4 *)uVar16;
  iStack_88 = _UNK_8111a5b0;
  iVar14 = 0;
  if (iRam811ae688 != 0) {
    iVar14 = iRam811ae688 + 4;
  }
  iVar9 = iVar14 + 4;
  piStack_84 = piVar8;
  ppiStack_80 = ppiVar2;
  ppiStack_7c = ppiVar10;
  ppiStack_78 = param_1;
  ppiStack_74 = ppiVar11;
  ppiStack_70 = ppiVar12;
  iStack_6c = iVar13;
  ppiStack_68 = param_2;
  uStack_64 = uVar15;
  (**(code **)(*(int *)(iVar14 + 4) + 8))(iVar9);
  iVar13 = 0;
  if (iVar1 != 0) {
    iVar13 = iVar1 + 4;
  }
  iVar13 = *(int *)(iVar13 + 0x10);
  iStack_8c = iVar9;
  if (iVar13 == 0) {
    (**(code **)(*(int *)(iVar14 + 4) + 0xc))();
    ppiVar12 = (int **)0x0;
  }
  else {
    uStack_90 = 0;
    puVar4[4] = 1;
    puVar4[5] = 0;
    *(undefined *)((int)puVar4 + 0x3e) = 0;
    iVar5 = func_0x8107b846(iVar1 + 100,uVar7,auStack_ac);
    iVar9 = iStack_8c;
    if (iVar5 == 0) {
      uVar15 = **(undefined4 **)(iVar13 + 0x1c);
      if (piRam81191264 == (int *)puVar4[0xc]) {
        iStack_a8 = 0;
        uStack_a4 = 0;
        iVar13 = FUN_810a15b8(uVar15,&iStack_a8,&uStack_a4,uVar7,puVar4 + 0xc);
        if (iVar13 != 0) {
          puVar4[0xc] = *(undefined4 *)(iStack_a8 + 0x28);
        }
      }
      FUN_810a2d78(asStack_b0,uVar15,puVar4 + 4,puVar4 + 0xe,*puVar4,uVar7,puVar4 + 0xc,0);
      *(short *)(puVar4 + 3) = asStack_b0[0];
      if (asStack_b0[0] == 0) {
        (**(code **)(*(int *)(iVar14 + 4) + 0xc))(iVar9);
        ppiVar12 = (int **)0x0;
      }
      else {
        *(undefined *)(puVar4 + 0xf) = 1;
        puVar4[6] = 2;
        (**(code **)(*(int *)(iVar14 + 4) + 0xc))(iVar9);
        ppiVar12 = (int **)0x1;
      }
    }
    else {
      uStack_a0 = *puVar4;
      do {
        func_0x8107bd82(auStack_98,iVar1 + 100,uVar7,uStack_a0,puVar4 + 7);
        iVar13 = func_0x8107db88(auStack_98);
        if (iVar13 == 0) {
          func_0x8108cfd4(100);
        }
        func_0x8107db94(auStack_98);
        uStack_a0 = *puVar4;
      } while (iVar13 == 0);
      iStack_9c = iVar13;
      if (puVar4 + 1 != &uStack_a0) {
        func_0x8107db94(puVar4 + 1);
        puVar4[1] = uStack_a0;
        puVar4[2] = iStack_9c;
        uStack_a0 = 0;
        iStack_9c = 0;
      }
      func_0x8107db94(&uStack_a0);
      puVar4[4] = uStack_90;
      *(undefined *)((int)puVar4 + 0x3e) = 1;
      puVar4[5] = uStack_90;
      (**(code **)(*(int *)(iVar14 + 4) + 0xc))(iStack_8c);
      ppiVar12 = (int **)0x1;
    }
  }
  if (_UNK_8111a5b0 != iStack_88) {
    uVar16 = func_0x811185a0(ppiVar12);
    uVar7 = (undefined4)((ulonglong)uVar16 >> 0x20);
    iVar13 = (int)uVar16;
    func_0x81080bb2(iVar13 + 0x24);
    iVar1 = FUN_810668cc(iVar13,uVar7);
    if (iVar1 == 0) {
      ppiVar12 = (int **)FUN_81066642(iVar13,uVar7);
    }
    else {
      ppiVar12 = (int **)0x1;
    }
    return ppiVar12;
  }
  return ppiVar12;
}

