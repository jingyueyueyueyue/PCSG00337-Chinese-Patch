
/* WARNING: Possible PIC construction at 0x8106d8fa: Changing call to branch */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106d754(int param_1)

{
  char cVar1;
  undefined8 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  undefined *unaff_r6;
  undefined *unaff_r8;
  undefined **ppuVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined *puStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int *piStack_1c;
  int iStack_18;
  
  ppuVar10 = &puStack_28;
  iStack_18 = _UNK_8111a5b0;
  piVar9 = *(int **)(param_1 + 0xc);
  if (piVar9 != (int *)0x0) {
    iVar5 = piVar9[2];
    if (piVar9[1] == 0) {
      *(int *)(param_1 + 8) = iVar5;
    }
    else {
      *(int *)(piVar9[1] + 8) = iVar5;
      iVar5 = piVar9[2];
    }
    if (iVar5 == 0) {
      *(int *)(param_1 + 0xc) = piVar9[1];
    }
    else {
      *(int *)(iVar5 + 4) = piVar9[1];
    }
    iVar5 = *(int *)(param_1 + 4);
    piVar9[1] = 0;
    piVar9[2] = 0;
    *(int *)(param_1 + 4) = iVar5 + -1;
    piVar3 = *(int **)(param_1 + 0x10);
    uStack_24 = 0x80000020;
    unaff_r6 = &UNK_81143e70;
    iStack_20 = param_1;
    piStack_1c = piVar9;
    if (piVar3 != (int *)0x0) {
      puStack_28 = &UNK_8114509c;
      (**(code **)(*piVar3 + 0x44))(piVar3,&puStack_28);
    }
    puStack_28 = &UNK_81143e70;
    if (*(char *)(param_1 + 0x34) != '\0') {
      func_0x8108d650(param_1 + 0x14,0,0x20);
    }
    iVar5 = *piVar9;
    *(undefined *)(param_1 + 0x34) = 0;
    (**(code **)(iVar5 + 4))(piVar9);
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar11 = 0x8106d7f7;
  uVar12 = func_0x811185a0();
  uVar13 = CONCAT44(&UNK_8111a5b0,unaff_r6);
  while( true ) {
    uVar2 = uVar12;
    piVar6 = (int *)((ulonglong)uVar2 >> 0x20);
    iVar5 = (int)uVar2;
    ppuVar10[-1] = (undefined *)uVar11;
    ppuVar10[-2] = unaff_r8;
    *(undefined8 *)(ppuVar10 + -4) = uVar13;
    ppuVar10[-5] = (undefined *)piVar9;
    ppuVar10[-6] = (undefined *)param_1;
    unaff_r8 = &UNK_8111a5b0;
    ppuVar10[-8] = (undefined *)_UNK_8111a5b0;
    *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + -1;
    piVar3 = *(int **)(iVar5 + 0x10);
    piVar9 = (int *)&UNK_81143e70;
    piVar7 = (int *)0x0;
    if (piVar6 != (int *)0x0) {
      piVar7 = piVar6 + 1;
    }
    if (*piVar7 == 0) {
      piVar7 = (int *)0x0;
      if (piVar6 != (int *)0x0) {
        piVar7 = piVar6 + 1;
      }
      *(int *)(iVar5 + 8) = piVar7[1];
    }
    else {
      piVar7 = (int *)0x0;
      if (piVar6 != (int *)0x0) {
        piVar7 = piVar6 + 1;
      }
      piVar8 = (int *)0x0;
      if (piVar6 != (int *)0x0) {
        piVar8 = piVar6 + 1;
      }
      *(int *)(*piVar8 + 8) = piVar7[1];
    }
    piVar7 = (int *)0x0;
    if (piVar6 != (int *)0x0) {
      piVar7 = piVar6 + 1;
    }
    if (piVar7[1] == 0) {
      piVar7 = (int *)0x0;
      if (piVar6 != (int *)0x0) {
        piVar7 = piVar6 + 1;
      }
      *(int *)(iVar5 + 0xc) = *piVar7;
    }
    else {
      piVar7 = (int *)0x0;
      if (piVar6 != (int *)0x0) {
        piVar7 = piVar6 + 1;
      }
      piVar8 = (int *)0x0;
      if (piVar6 != (int *)0x0) {
        piVar8 = piVar6 + 1;
      }
      *(int *)(piVar8[1] + 4) = *piVar7;
    }
    piVar7 = (int *)0x0;
    if (piVar6 != (int *)0x0) {
      piVar7 = piVar6 + 1;
    }
    piVar7[1] = 0;
    piVar7 = (int *)0x0;
    if (piVar6 != (int *)0x0) {
      piVar7 = piVar6 + 1;
    }
    *piVar7 = 0;
    *(undefined8 *)(ppuVar10 + -10) = uVar2;
    ppuVar10[-0xb] = (undefined *)0x80000020;
    if (piVar3 != (int *)0x0) {
      ppuVar10[-0xc] = &UNK_8114509c;
      (**(code **)(*piVar3 + 0x44))(piVar3,ppuVar10 + -0xc);
    }
    cVar1 = *(char *)(iVar5 + 0x34);
    ppuVar10[-0xc] = &UNK_81143e70;
    if (cVar1 != '\0') {
      func_0x8108d650(iVar5 + 0x14,0,0x20);
    }
    *(undefined *)(iVar5 + 0x34) = 0;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    if ((undefined *)_UNK_8111a5b0 == ppuVar10[-8]) break;
    uVar11 = 0x8106d8e5;
    uVar13 = func_0x811185a0();
    param_1 = (int)uVar13;
    ppuVar10[-0xd] = (undefined *)uVar11;
    ppuVar10 = ppuVar10 + -0xe;
    *ppuVar10 = (undefined *)0x0;
    if (*(int *)(param_1 + 4) <= (int)((ulonglong)uVar13 >> 0x20)) {
      return;
    }
    uVar4 = func_0x8106d280(param_1);
    uVar11 = 0x8106d8ff;
    uVar12 = CONCAT44(uVar4,param_1);
    uVar13 = uVar2;
  }
  return;
}

