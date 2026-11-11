
/* WARNING: Possible PIC construction at 0x8106d8fa: Changing call to branch */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106d6b0(int param_1)

{
  char cVar1;
  undefined8 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  undefined *unaff_r6;
  undefined *puVar11;
  undefined *unaff_r8;
  undefined **ppuVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined *puStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  int *piStack_44;
  int iStack_40;
  int iStack_3c;
  int *piStack_38;
  undefined *puStack_34;
  undefined *puStack_30;
  undefined4 uStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int *piStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  piVar10 = *(int **)(param_1 + 8);
  if (piVar10 != (int *)0x0) {
    iVar5 = piVar10[2];
    if (piVar10[1] == 0) {
      *(int *)(param_1 + 8) = iVar5;
    }
    else {
      *(int *)(piVar10[1] + 8) = iVar5;
      iVar5 = piVar10[2];
    }
    if (iVar5 == 0) {
      *(int *)(param_1 + 0xc) = piVar10[1];
    }
    else {
      *(int *)(iVar5 + 4) = piVar10[1];
    }
    iVar5 = *(int *)(param_1 + 4);
    piVar10[1] = 0;
    piVar10[2] = 0;
    *(int *)(param_1 + 4) = iVar5 + -1;
    piVar3 = *(int **)(param_1 + 0x10);
    uStack_24 = 0x80000020;
    unaff_r6 = &UNK_81143e70;
    iStack_20 = param_1;
    piStack_1c = piVar10;
    if (piVar3 != (int *)0x0) {
      puStack_28 = &UNK_8114509c;
      (**(code **)(*piVar3 + 0x44))(piVar3,&puStack_28);
    }
    puStack_28 = &UNK_81143e70;
    (**(code **)(*piVar10 + 4))(piVar10);
    if (*(char *)(param_1 + 0x34) != '\0') {
      func_0x8108d650(param_1 + 0x14,0,0x20);
    }
    *(undefined *)(param_1 + 0x34) = 0;
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar13 = 0x8106d753;
  iVar5 = func_0x811185a0();
  puStack_30 = &UNK_8111a5b0;
  ppuVar12 = &puStack_50;
  iStack_40 = _UNK_8111a5b0;
  piVar3 = *(int **)(iVar5 + 0xc);
  puVar11 = unaff_r6;
  iStack_3c = param_1;
  piStack_38 = piVar10;
  puStack_34 = unaff_r6;
  uStack_2c = uVar13;
  if (piVar3 != (int *)0x0) {
    iVar6 = piVar3[2];
    if (piVar3[1] == 0) {
      *(int *)(iVar5 + 8) = iVar6;
    }
    else {
      *(int *)(piVar3[1] + 8) = iVar6;
      iVar6 = piVar3[2];
    }
    if (iVar6 == 0) {
      *(int *)(iVar5 + 0xc) = piVar3[1];
    }
    else {
      *(int *)(iVar6 + 4) = piVar3[1];
    }
    iVar6 = *(int *)(iVar5 + 4);
    piVar3[1] = 0;
    piVar3[2] = 0;
    *(int *)(iVar5 + 4) = iVar6 + -1;
    piVar10 = *(int **)(iVar5 + 0x10);
    uStack_4c = 0x80000020;
    puVar11 = &UNK_81143e70;
    iStack_48 = iVar5;
    piStack_44 = piVar3;
    if (piVar10 != (int *)0x0) {
      puStack_50 = &UNK_8114509c;
      (**(code **)(*piVar10 + 0x44))(piVar10,&puStack_50);
    }
    puStack_50 = &UNK_81143e70;
    if (*(char *)(iVar5 + 0x34) != '\0') {
      func_0x8108d650(iVar5 + 0x14,0,0x20);
    }
    iVar6 = *piVar3;
    *(undefined *)(iVar5 + 0x34) = 0;
    (**(code **)(iVar6 + 4))(piVar3);
  }
  if (_UNK_8111a5b0 == iStack_40) {
    return;
  }
  uVar13 = 0x8106d7f7;
  uVar14 = func_0x811185a0();
  uVar15 = CONCAT44(&UNK_8111a5b0,puVar11);
  while( true ) {
    uVar2 = uVar14;
    piVar7 = (int *)((ulonglong)uVar2 >> 0x20);
    iVar6 = (int)uVar2;
    ppuVar12[-1] = (undefined *)uVar13;
    ppuVar12[-2] = unaff_r8;
    *(undefined8 *)(ppuVar12 + -4) = uVar15;
    ppuVar12[-5] = (undefined *)piVar3;
    ppuVar12[-6] = (undefined *)iVar5;
    unaff_r8 = &UNK_8111a5b0;
    ppuVar12[-8] = (undefined *)_UNK_8111a5b0;
    *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + -1;
    piVar10 = *(int **)(iVar6 + 0x10);
    piVar3 = (int *)&UNK_81143e70;
    piVar8 = (int *)0x0;
    if (piVar7 != (int *)0x0) {
      piVar8 = piVar7 + 1;
    }
    if (*piVar8 == 0) {
      piVar8 = (int *)0x0;
      if (piVar7 != (int *)0x0) {
        piVar8 = piVar7 + 1;
      }
      *(int *)(iVar6 + 8) = piVar8[1];
    }
    else {
      piVar8 = (int *)0x0;
      if (piVar7 != (int *)0x0) {
        piVar8 = piVar7 + 1;
      }
      piVar9 = (int *)0x0;
      if (piVar7 != (int *)0x0) {
        piVar9 = piVar7 + 1;
      }
      *(int *)(*piVar9 + 8) = piVar8[1];
    }
    piVar8 = (int *)0x0;
    if (piVar7 != (int *)0x0) {
      piVar8 = piVar7 + 1;
    }
    if (piVar8[1] == 0) {
      piVar8 = (int *)0x0;
      if (piVar7 != (int *)0x0) {
        piVar8 = piVar7 + 1;
      }
      *(int *)(iVar6 + 0xc) = *piVar8;
    }
    else {
      piVar8 = (int *)0x0;
      if (piVar7 != (int *)0x0) {
        piVar8 = piVar7 + 1;
      }
      piVar9 = (int *)0x0;
      if (piVar7 != (int *)0x0) {
        piVar9 = piVar7 + 1;
      }
      *(int *)(piVar9[1] + 4) = *piVar8;
    }
    piVar8 = (int *)0x0;
    if (piVar7 != (int *)0x0) {
      piVar8 = piVar7 + 1;
    }
    piVar8[1] = 0;
    piVar8 = (int *)0x0;
    if (piVar7 != (int *)0x0) {
      piVar8 = piVar7 + 1;
    }
    *piVar8 = 0;
    *(undefined8 *)(ppuVar12 + -10) = uVar2;
    ppuVar12[-0xb] = (undefined *)0x80000020;
    if (piVar10 != (int *)0x0) {
      ppuVar12[-0xc] = &UNK_8114509c;
      (**(code **)(*piVar10 + 0x44))(piVar10,ppuVar12 + -0xc);
    }
    cVar1 = *(char *)(iVar6 + 0x34);
    ppuVar12[-0xc] = &UNK_81143e70;
    if (cVar1 != '\0') {
      func_0x8108d650(iVar6 + 0x14,0,0x20);
    }
    *(undefined *)(iVar6 + 0x34) = 0;
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 4))(piVar7);
    }
    if ((undefined *)_UNK_8111a5b0 == ppuVar12[-8]) break;
    uVar13 = 0x8106d8e5;
    uVar15 = func_0x811185a0();
    iVar5 = (int)uVar15;
    ppuVar12[-0xd] = (undefined *)uVar13;
    ppuVar12 = ppuVar12 + -0xe;
    *ppuVar12 = (undefined *)0x0;
    if (*(int *)(iVar5 + 4) <= (int)((ulonglong)uVar15 >> 0x20)) {
      return;
    }
    uVar4 = func_0x8106d280(iVar5);
    uVar13 = 0x8106d8ff;
    uVar14 = CONCAT44(uVar4,iVar5);
    uVar15 = uVar2;
  }
  return;
}

