
/* WARNING: Possible PIC construction at 0x8106dd58: Changing call to branch */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106da8a(int param_1,int param_2)

{
  int *piVar1;
  code **ppcVar2;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  code *pcVar9;
  code *unaff_r8;
  code *unaff_r9;
  undefined4 *puVar10;
  int *unaff_r10;
  code *unaff_r11;
  int iVar11;
  code **ppcVar12;
  int iVar13;
  undefined4 uVar14;
  code *pcVar15;
  undefined4 *puVar16;
  int *piVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined *puStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  code *pcStack_40;
  undefined *puStack_3c;
  int iStack_38;
  int iStack_34;
  undefined *puStack_30;
  undefined4 uStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  code *pcStack_18;
  
  pcStack_18 = _UNK_8111a5b0;
  if (*(char *)(param_1 + 0x34) != '\0') {
    func_0x8108d650(param_1 + 0x14,0,0x20);
  }
  *(undefined *)(param_1 + 0x34) = 0;
  iVar5 = param_1 + 0x18;
  puVar8 = (undefined4 *)(param_1 + 0x2c);
  iVar13 = 3;
  do {
    iVar13 = iVar13 + -1;
    *puVar8 = *(undefined4 *)(iVar5 + 0xc);
    puVar16 = (undefined4 *)(iVar5 + 0x10);
    iVar5 = iVar5 + -8;
    puVar8[1] = *puVar16;
    puVar8 = puVar8 + -2;
  } while (iVar13 != 0);
  *(int *)(param_1 + 0x18) = param_2;
  *(int *)(param_2 + 0x14) = param_1;
  *(undefined4 *)(param_1 + 0x14) = 0;
  iVar5 = *(int *)(param_1 + 8);
  *(undefined *)(param_1 + 0x34) = 1;
  if (iVar5 == 0) {
    iVar5 = 0;
    if (param_2 != 0) {
      iVar5 = param_2 + 4;
    }
    *(undefined4 *)(iVar5 + 4) = 0;
    puVar8 = (undefined4 *)0x0;
    if (param_2 != 0) {
      puVar8 = (undefined4 *)(param_2 + 4);
    }
    *puVar8 = 0;
    iVar5 = *(int *)(param_1 + 4);
    *(int *)(param_1 + 0xc) = param_2;
  }
  else {
    iVar13 = 0;
    if (param_2 != 0) {
      iVar13 = param_2 + 4;
    }
    *(int *)(iVar13 + 4) = iVar5;
    *(int *)(iVar5 + 4) = param_2;
    puVar8 = (undefined4 *)0x0;
    if (param_2 != 0) {
      puVar8 = (undefined4 *)(param_2 + 4);
    }
    *puVar8 = 0;
    iVar5 = *(int *)(param_1 + 4);
  }
  piVar1 = *(int **)(param_1 + 0x10);
  *(int *)(param_1 + 8) = param_2;
  *(int *)(param_1 + 4) = iVar5 + 1;
  if (piVar1 != (int *)0x0) {
    puStack_28 = &UNK_811450c4;
    uStack_24 = 0x80000021;
    iStack_20 = param_1;
    iStack_1c = param_2;
    (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_28);
  }
  if (_UNK_8111a5b0 == pcStack_18) {
    return;
  }
  uVar14 = 0x8106db59;
  uVar18 = func_0x811185a0();
  iVar13 = (int)((ulonglong)uVar18 >> 0x20);
  iVar5 = (int)uVar18;
  puStack_30 = &UNK_8111a5b0;
  puStack_3c = &UNK_811450c4;
  ppcVar12 = (code **)&puStack_50;
  pcVar9 = (code *)&UNK_8111a5b0;
  pcStack_40 = _UNK_8111a5b0;
  iStack_38 = param_1;
  iStack_34 = param_2;
  uStack_2c = uVar14;
  if (*(char *)(iVar5 + 0x34) != '\0') {
    func_0x8108d650(iVar5 + 0x14,0,0x20);
  }
  uVar14 = *(undefined4 *)(iVar5 + 4);
  iVar6 = iVar5 + 0x18;
  *(undefined *)(iVar5 + 0x34) = 0;
  puVar8 = (undefined4 *)(iVar5 + 0x2c);
  iVar11 = 3;
  do {
    iVar11 = iVar11 + -1;
    *puVar8 = *(undefined4 *)(iVar6 + 0xc);
    puVar16 = (undefined4 *)(iVar6 + 0x10);
    iVar6 = iVar6 + -8;
    puVar8[1] = *puVar16;
    puVar8 = puVar8 + -2;
  } while (iVar11 != 0);
  *(int *)(iVar5 + 0x18) = iVar13;
  *(undefined4 *)(iVar5 + 0x14) = uVar14;
  iVar11 = *(int *)(iVar5 + 4);
  *(int *)(iVar13 + 0x14) = iVar5;
  iVar6 = *(int *)(iVar5 + 0xc);
  *(undefined *)(iVar5 + 0x34) = 1;
  if (iVar6 == 0) {
    iVar6 = 0;
    if (iVar13 != 0) {
      iVar6 = iVar13 + 4;
    }
    *(undefined4 *)(iVar6 + 4) = 0;
    puVar8 = (undefined4 *)0x0;
    if (iVar13 != 0) {
      puVar8 = (undefined4 *)(iVar13 + 4);
    }
    *puVar8 = 0;
    *(int *)(iVar5 + 8) = iVar13;
  }
  else {
    iVar7 = 0;
    if (iVar13 != 0) {
      iVar7 = iVar13 + 4;
    }
    *(undefined4 *)(iVar7 + 4) = 0;
    piVar1 = (int *)0x0;
    if (iVar13 != 0) {
      piVar1 = (int *)(iVar13 + 4);
    }
    *piVar1 = iVar6;
    *(int *)(iVar6 + 8) = iVar13;
  }
  puVar8 = (undefined4 *)(iVar11 + 1);
  ppcVar2 = *(code ***)(iVar5 + 0x10);
  *(int *)(iVar5 + 0xc) = iVar13;
  *(undefined4 **)(iVar5 + 4) = puVar8;
  if (ppcVar2 != (code **)0x0) {
    puStack_50 = &UNK_811450c4;
    uStack_4c = 0x80000021;
    puVar8 = (undefined4 *)*ppcVar2;
    uStack_48 = uVar18;
    (*(code *)puVar8[0x11])(ppcVar2,&puStack_50);
  }
  if (_UNK_8111a5b0 == pcStack_40) {
    return;
  }
  pcVar15 = (code *)0x8106dc2f;
  uVar19 = func_0x811185a0();
  puVar16 = (undefined4 *)&UNK_811450c4;
  while( true ) {
    pcVar4 = (code *)((ulonglong)uVar19 >> 0x20);
    pcVar3 = (code *)uVar19;
    ppcVar12[-1] = pcVar15;
    ppcVar12[-2] = unaff_r11;
    ppcVar12[-3] = (code *)unaff_r10;
    ppcVar12[-4] = unaff_r9;
    ppcVar12[-5] = unaff_r8;
    ppcVar12[-6] = pcVar9;
    *(undefined8 *)(ppcVar12 + -8) = uVar18;
    ppcVar12[-9] = (code *)puVar16;
    unaff_r11 = (code *)&UNK_8111a5b0;
    ppcVar12[-10] = _UNK_8111a5b0;
    puVar8[5] = pcVar3;
    pcVar9 = (code *)&UNK_811450c4;
    if (pcVar4 == (code *)0x0) {
      puVar10 = (undefined4 *)0x0;
      if (puVar8 != (undefined4 *)0x0) {
        puVar10 = puVar8 + 1;
      }
      puVar10[1] = 0;
      puVar10 = (undefined4 *)0x0;
      if (puVar8 != (undefined4 *)0x0) {
        puVar10 = puVar8 + 1;
      }
      *puVar10 = 0;
      unaff_r9 = (code *)(*(int *)(pcVar3 + 4) + 1);
      *(undefined4 **)(pcVar3 + 8) = puVar8;
      *(undefined4 **)(pcVar3 + 0xc) = puVar8;
      piVar1 = *(int **)(pcVar3 + 0x10);
    }
    else {
      puVar16 = (undefined4 *)0x0;
      if (puVar8 != (undefined4 *)0x0) {
        puVar16 = puVar8 + 1;
      }
      puVar16[1] = pcVar4;
      puVar16 = (undefined4 *)0x0;
      if (puVar8 != (undefined4 *)0x0) {
        puVar16 = puVar8 + 1;
      }
      *puVar16 = *(undefined4 *)(pcVar4 + 4);
      piVar17 = (int *)0x0;
      *(undefined4 **)(pcVar4 + 4) = puVar8;
      iVar5 = *(int *)(pcVar3 + 4);
      unaff_r8 = *(code **)(pcVar3 + 8);
      piVar1 = *(int **)(pcVar3 + 0x10);
      if (puVar8 != (undefined4 *)0x0) {
        piVar17 = puVar8 + 1;
      }
      if (*piVar17 != 0) {
        piVar17 = (int *)0x0;
        if (puVar8 != (undefined4 *)0x0) {
          piVar17 = puVar8 + 1;
        }
        *(undefined4 **)(*piVar17 + 8) = puVar8;
      }
      unaff_r9 = (code *)(iVar5 + 1);
      unaff_r10 = piVar1;
      if (unaff_r8 == pcVar4) {
        *(undefined4 **)(pcVar3 + 8) = puVar8;
      }
    }
    *(code **)(pcVar3 + 4) = unaff_r9;
    ppcVar12[-0xd] = (code *)0x80000021;
    ppcVar12[-0xc] = pcVar3;
    ppcVar12[-0xb] = (code *)puVar8;
    if (piVar1 != (int *)0x0) {
      ppcVar12[-0xe] = (code *)&UNK_811450c4;
      puVar8 = *(undefined4 **)(*piVar1 + 0x44);
      (*(code *)puVar8)(piVar1,ppcVar12 + -0xe);
    }
    if (pcVar3[0x34] != (code)0x0) {
      ppcVar12[-0xe] = (code *)&UNK_81143e70;
      puVar8 = (undefined4 *)0x20;
      func_0x8108d650(pcVar3 + 0x14,0);
    }
    pcVar3[0x34] = (code)0x0;
    if (_UNK_8111a5b0 == ppcVar12[-10]) break;
    pcVar15 = (code *)0x8106dd35;
    uVar19 = func_0x811185a0();
    iVar5 = (int)uVar19;
    uVar18 = CONCAT44(pcVar3,iVar5);
    ppcVar12[-0xf] = pcVar15;
    ppcVar12[-0x10] = pcVar3;
    ppcVar12[-0x11] = (code *)&UNK_81143e70;
    ppcVar12 = ppcVar12 + -0x12;
    *ppcVar12 = (code *)puVar16;
    if (*(int *)(iVar5 + 4) <= (int)((ulonglong)uVar19 >> 0x20)) {
      FUN_8106db5a(iVar5,puVar8);
      return;
    }
    uVar14 = func_0x8106d280(iVar5);
    uVar19 = CONCAT44(uVar14,iVar5);
    pcVar15 = (code *)0x8106dd5d;
    puVar16 = puVar8;
  }
  return;
}

