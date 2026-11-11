
/* WARNING: Possible PIC construction at 0x8106dd58: Changing call to branch */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106db5a(code *param_1,code *param_2)

{
  code **ppcVar1;
  code *pcVar2;
  code *pcVar3;
  code *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  code *pcVar7;
  code *unaff_r8;
  code *unaff_r9;
  undefined4 *puVar8;
  int *unaff_r10;
  code *unaff_r11;
  int iVar9;
  code **ppcVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  int *piVar14;
  undefined8 uVar15;
  undefined *puStack_28;
  undefined4 uStack_24;
  code *pcStack_20;
  code *pcStack_1c;
  code *pcStack_18;
  
  ppcVar10 = (code **)&puStack_28;
  pcVar7 = (code *)&UNK_8111a5b0;
  pcStack_18 = _UNK_8111a5b0;
  if (param_1[0x34] != (code)0x0) {
    func_0x8108d650(param_1 + 0x14,0,0x20);
  }
  uVar6 = *(undefined4 *)(param_1 + 4);
  pcVar4 = param_1 + 0x18;
  param_1[0x34] = (code)0x0;
  puVar11 = (undefined4 *)(param_1 + 0x2c);
  iVar9 = 3;
  do {
    iVar9 = iVar9 + -1;
    *puVar11 = *(undefined4 *)(pcVar4 + 0xc);
    puVar13 = (undefined4 *)(pcVar4 + 0x10);
    pcVar4 = pcVar4 + -8;
    puVar11[1] = *puVar13;
    puVar11 = puVar11 + -2;
  } while (iVar9 != 0);
  *(code **)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0x14) = uVar6;
  iVar12 = *(int *)(param_1 + 4);
  *(code **)(param_2 + 0x14) = param_1;
  iVar9 = *(int *)(param_1 + 0xc);
  param_1[0x34] = (code)0x1;
  if (iVar9 == 0) {
    pcVar4 = (code *)0x0;
    if (param_2 != (code *)0x0) {
      pcVar4 = param_2 + 4;
    }
    *(undefined4 *)(pcVar4 + 4) = 0;
    puVar11 = (undefined4 *)0x0;
    if (param_2 != (code *)0x0) {
      puVar11 = (undefined4 *)(param_2 + 4);
    }
    *puVar11 = 0;
    *(code **)(param_1 + 8) = param_2;
  }
  else {
    pcVar4 = (code *)0x0;
    if (param_2 != (code *)0x0) {
      pcVar4 = param_2 + 4;
    }
    *(undefined4 *)(pcVar4 + 4) = 0;
    piVar5 = (int *)0x0;
    if (param_2 != (code *)0x0) {
      piVar5 = (int *)(param_2 + 4);
    }
    *piVar5 = iVar9;
    *(code **)(iVar9 + 8) = param_2;
  }
  puVar11 = (undefined4 *)(iVar12 + 1);
  ppcVar1 = *(code ***)(param_1 + 0x10);
  *(code **)(param_1 + 0xc) = param_2;
  *(undefined4 **)(param_1 + 4) = puVar11;
  if (ppcVar1 != (code **)0x0) {
    puStack_28 = &UNK_811450c4;
    uStack_24 = 0x80000021;
    puVar11 = (undefined4 *)*ppcVar1;
    pcStack_20 = param_1;
    pcStack_1c = param_2;
    (*(code *)puVar11[0x11])(ppcVar1,&puStack_28);
  }
  if (_UNK_8111a5b0 == pcStack_18) {
    return;
  }
  pcVar4 = (code *)0x8106dc2f;
  uVar15 = func_0x811185a0();
  puVar13 = (undefined4 *)&UNK_811450c4;
  while( true ) {
    pcVar3 = (code *)((ulonglong)uVar15 >> 0x20);
    pcVar2 = (code *)uVar15;
    ppcVar10[-1] = pcVar4;
    ppcVar10[-2] = unaff_r11;
    ppcVar10[-3] = (code *)unaff_r10;
    ppcVar10[-4] = unaff_r9;
    ppcVar10[-5] = unaff_r8;
    ppcVar10[-6] = pcVar7;
    ppcVar10[-7] = param_2;
    ppcVar10[-8] = param_1;
    ppcVar10[-9] = (code *)puVar13;
    unaff_r11 = (code *)&UNK_8111a5b0;
    ppcVar10[-10] = _UNK_8111a5b0;
    puVar11[5] = pcVar2;
    pcVar7 = (code *)&UNK_811450c4;
    if (pcVar3 == (code *)0x0) {
      puVar8 = (undefined4 *)0x0;
      if (puVar11 != (undefined4 *)0x0) {
        puVar8 = puVar11 + 1;
      }
      puVar8[1] = 0;
      puVar8 = (undefined4 *)0x0;
      if (puVar11 != (undefined4 *)0x0) {
        puVar8 = puVar11 + 1;
      }
      *puVar8 = 0;
      unaff_r9 = (code *)(*(int *)(pcVar2 + 4) + 1);
      *(undefined4 **)(pcVar2 + 8) = puVar11;
      *(undefined4 **)(pcVar2 + 0xc) = puVar11;
      piVar5 = *(int **)(pcVar2 + 0x10);
    }
    else {
      puVar13 = (undefined4 *)0x0;
      if (puVar11 != (undefined4 *)0x0) {
        puVar13 = puVar11 + 1;
      }
      puVar13[1] = pcVar3;
      puVar13 = (undefined4 *)0x0;
      if (puVar11 != (undefined4 *)0x0) {
        puVar13 = puVar11 + 1;
      }
      *puVar13 = *(undefined4 *)(pcVar3 + 4);
      piVar14 = (int *)0x0;
      *(undefined4 **)(pcVar3 + 4) = puVar11;
      iVar9 = *(int *)(pcVar2 + 4);
      unaff_r8 = *(code **)(pcVar2 + 8);
      piVar5 = *(int **)(pcVar2 + 0x10);
      if (puVar11 != (undefined4 *)0x0) {
        piVar14 = puVar11 + 1;
      }
      if (*piVar14 != 0) {
        piVar14 = (int *)0x0;
        if (puVar11 != (undefined4 *)0x0) {
          piVar14 = puVar11 + 1;
        }
        *(undefined4 **)(*piVar14 + 8) = puVar11;
      }
      unaff_r9 = (code *)(iVar9 + 1);
      unaff_r10 = piVar5;
      if (unaff_r8 == pcVar3) {
        *(undefined4 **)(pcVar2 + 8) = puVar11;
      }
    }
    *(code **)(pcVar2 + 4) = unaff_r9;
    ppcVar10[-0xd] = (code *)0x80000021;
    ppcVar10[-0xc] = pcVar2;
    ppcVar10[-0xb] = (code *)puVar11;
    if (piVar5 != (int *)0x0) {
      ppcVar10[-0xe] = (code *)&UNK_811450c4;
      puVar11 = *(undefined4 **)(*piVar5 + 0x44);
      (*(code *)puVar11)(piVar5,ppcVar10 + -0xe);
    }
    if (pcVar2[0x34] != (code)0x0) {
      ppcVar10[-0xe] = (code *)&UNK_81143e70;
      puVar11 = (undefined4 *)0x20;
      func_0x8108d650(pcVar2 + 0x14,0);
    }
    pcVar2[0x34] = (code)0x0;
    if (_UNK_8111a5b0 == ppcVar10[-10]) break;
    pcVar4 = (code *)0x8106dd35;
    uVar15 = func_0x811185a0();
    param_1 = (code *)uVar15;
    ppcVar10[-0xf] = pcVar4;
    ppcVar10[-0x10] = pcVar2;
    ppcVar10[-0x11] = (code *)&UNK_81143e70;
    ppcVar10 = ppcVar10 + -0x12;
    *ppcVar10 = (code *)puVar13;
    if (*(int *)(param_1 + 4) <= (int)((ulonglong)uVar15 >> 0x20)) {
      FUN_8106db5a(param_1,puVar11);
      return;
    }
    uVar6 = func_0x8106d280(param_1);
    uVar15 = CONCAT44(uVar6,param_1);
    pcVar4 = (code *)0x8106dd5d;
    puVar13 = puVar11;
    param_2 = pcVar2;
  }
  return;
}

