
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_81072d36(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  int **ppiVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  undefined8 uVar18;
  undefined auStack_80 [12];
  undefined auStack_74 [8];
  int iStack_6c;
  int iStack_68;
  undefined auStack_64 [4];
  uint uStack_60;
  undefined4 uStack_50;
  uint uStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  undefined4 *puStack_2c;
  
  puStack_2c = _UNK_8111a5b0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  piVar1 = (int *)func_0x81005a98(0x34);
  if (piVar1 != (int *)0x0) {
    *piVar1 = (int)piVar1;
  }
  if (piVar1 != (int *)0xfffffffc) {
    piVar1[1] = (int)piVar1;
  }
  piVar14 = piVar1;
  if ((undefined *)(param_1 + 0x24) != auStack_80) {
    piVar14 = *(int **)(param_1 + 0x28);
    *(int **)(param_1 + 0x28) = piVar1;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  ppiVar11 = (int **)*piVar14;
  *piVar14 = (int)piVar14;
  piVar14[1] = (int)piVar14;
  iStack_34 = param_3;
  while (ppiVar11 != (int **)piVar14) {
    piVar1 = *ppiVar11;
    if (0xf < ppiVar11[8]) {
      func_0x81005af0(ppiVar11[3]);
    }
    *(undefined *)(ppiVar11 + 3) = 0;
    ppiVar11[7] = (int *)0x0;
    ppiVar11[8] = (int *)0xf;
    func_0x81005af0(ppiVar11);
    ppiVar11 = (int **)piVar1;
  }
  func_0x81005af0(piVar14);
  if (param_2 != 0) {
    iVar7 = *(int *)(param_1 + 0x18);
    iVar15 = 0;
    *(undefined4 *)(iVar7 + 0x94) = 0;
    *(uint *)(iVar7 + 0x98) = *(uint *)(iVar7 + 0x98) & 0xffffff7f;
    *(undefined4 *)(iVar7 + 0x8c) = 0;
    *(undefined4 *)(iVar7 + 0x90) = 0;
    iVar7 = func_0x81118330(param_2);
    iVar7 = iVar7 + 1;
    if (iVar7 != 0) {
      if (iVar7 == 0) {
        func_0x811183a0(0,param_2,0);
      }
      else {
        iVar15 = 0;
        if (iVar7 != 0) {
          iVar15 = iVar7;
        }
        iVar15 = func_0x81005a98(iVar15);
        uVar2 = func_0x811183a0(iVar15,0,0);
        iVar3 = func_0x811183a0(uVar2,param_2,iVar7);
        func_0x811183a0(iVar3 + iVar7,0,0);
      }
    }
    iStack_38 = param_1;
    iStack_30 = iVar15;
    pcVar4 = (char *)func_0x81118180(iVar15,&UNK_81137258);
    iVar15 = param_1;
    iVar7 = iStack_38;
    while (iStack_38 = iVar15, pcVar4 != (char *)0x0) {
      uStack_60 = uStack_60 & 0xffffff00;
      uStack_4c = 0xf;
      iVar7 = *(int *)(iStack_38 + 0x28);
      uStack_50 = 0;
      piVar14 = *(int **)(iVar7 + 4);
      piVar5 = (int *)func_0x81005a98(0x34);
      piVar1 = (int *)iVar7;
      if (iVar7 == 0) {
        piVar1 = piVar5;
        piVar14 = piVar5;
      }
      if (piVar5 != (int *)0x0) {
        *piVar5 = (int)piVar1;
      }
      if (piVar5 != (int *)0xfffffffc) {
        piVar5[1] = (int)piVar14;
      }
      if (piVar5 + 2 != (int *)0x0) {
        *(undefined *)(piVar5 + 3) = 0;
        piVar5[7] = 0;
        piVar5[8] = 0xf;
        func_0x810c8628(piVar5 + 2,auStack_64,0,0xffffffff);
        piVar5[9] = iStack_48;
        piVar5[10] = iStack_44;
        piVar5[0xb] = iStack_40;
        piVar5[0xc] = iStack_3c;
      }
      iVar15 = iStack_38;
      iVar3 = *(int *)(iStack_38 + 0x2c);
      if (iVar3 == 0x4ec4ec3) {
        func_0x811184b0(&UNK_811457f0);
        iVar3 = *(int *)(iVar15 + 0x2c);
      }
      *(int *)(iVar15 + 0x2c) = iVar3 + 1;
      *(int **)(iVar7 + 4) = piVar5;
      *(int **)piVar5[1] = piVar5;
      if (0xf < uStack_4c) {
        func_0x81005af0(uStack_60);
      }
      uVar16 = 0;
      uStack_60 = uStack_60 & 0xffffff00;
      uStack_50 = 0;
      uStack_4c = 0xf;
      iVar7 = *(int *)(*(int *)(iStack_38 + 0x28) + 4);
      if (*pcVar4 != '\0') {
        uVar16 = func_0x81118330(pcVar4);
      }
      uVar17 = *(uint *)(iVar7 + 0x20);
      pcVar8 = (char *)(iVar7 + 0xc);
      pcVar9 = pcVar8;
      if (0xf < uVar17) {
        pcVar9 = *(char **)(iVar7 + 0xc);
      }
      if (pcVar4 < pcVar9) {
LAB_81072f42:
        if (uVar16 == 0xffffffff) {
          func_0x811184b0(&UNK_81138ed4);
          uVar17 = *(uint *)(iVar7 + 0x20);
        }
        if (uVar17 < uVar16) {
          iVar15 = *(int *)(iVar7 + 0x1c);
          uVar12 = uVar16 | 0xf;
          uVar13 = uVar16;
          if (((uVar12 != 0xffffffff) && (uVar13 = uVar12, uVar12 / 3 < uVar17 >> 1)) &&
             (uVar13 = 0xfffffffe, uVar17 <= -(uVar17 >> 1) - 2)) {
            uVar13 = uVar17 + (uVar17 >> 1);
          }
          pcVar9 = (char *)func_0x81005a98(uVar13 + 1);
          uVar17 = *(uint *)(iVar7 + 0x20);
          if (iVar15 != 0) {
            pcVar10 = pcVar8;
            if (0xf < uVar17) {
              pcVar10 = *(char **)(iVar7 + 0xc);
            }
            func_0x811182b0(pcVar9,pcVar10,iVar15);
            uVar17 = *(uint *)(iVar7 + 0x20);
          }
          if (0xf < uVar17) {
            func_0x81005af0(*(undefined4 *)(iVar7 + 0xc));
          }
          *(int *)(iVar7 + 0x1c) = iVar15;
          *(undefined *)(iVar7 + 0xc) = 0;
          *(char **)(iVar7 + 0xc) = pcVar9;
          *(uint *)(iVar7 + 0x20) = uVar13;
          if (uVar13 < 0x10) {
            pcVar9 = pcVar8;
          }
          pcVar9[iVar15] = '\0';
        }
        else if (uVar16 == 0) {
          *(undefined4 *)(iVar7 + 0x1c) = 0;
          pcVar9 = pcVar8;
          if (0xf < uVar17) {
            pcVar9 = *(char **)(iVar7 + 0xc);
          }
          *pcVar9 = '\0';
        }
        if (uVar16 != 0) {
          pcVar9 = pcVar8;
          if (0xf < *(uint *)(iVar7 + 0x20)) {
            pcVar9 = *(char **)(iVar7 + 0xc);
          }
          func_0x811182b0(pcVar9,pcVar4,uVar16);
          *(uint *)(iVar7 + 0x1c) = uVar16;
          if (0xf < *(uint *)(iVar7 + 0x20)) {
            pcVar8 = *(char **)(iVar7 + 0xc);
          }
          pcVar8[uVar16] = '\0';
        }
      }
      else {
        pcVar9 = pcVar8;
        if (0xf < uVar17) {
          pcVar9 = *(char **)(iVar7 + 0xc);
        }
        if (pcVar9 + *(int *)(iVar7 + 0x1c) <= pcVar4) goto LAB_81072f42;
        if (0xf < uVar17) {
          pcVar8 = *(char **)(iVar7 + 0xc);
        }
        func_0x810c8628(iVar7 + 8,iVar7 + 8,(int)pcVar4 - (int)pcVar8,uVar16);
      }
      iVar15 = iStack_38;
      uVar2 = *(undefined4 *)(iStack_38 + 0x34);
      *(undefined4 *)(iVar7 + 0x24) = 0;
      *(undefined4 *)(iVar7 + 0x28) = uVar2;
      (**(code **)(**(int **)(iStack_38 + 0x18) + 0xc))
                (auStack_74,*(int **)(iStack_38 + 0x18),pcVar4);
      *(int *)(iVar7 + 0x2c) = iStack_6c;
      *(int *)(iVar7 + 0x30) = iStack_68;
      if (*(int *)(iVar15 + 0x30) < iStack_6c) {
        *(int *)(iVar15 + 0x30) = iStack_6c;
      }
      *(int *)(iVar15 + 0x34) = iStack_68 + *(int *)(iVar15 + 0x34);
      pcVar4 = (char *)func_0x81118180(0,&UNK_81137258);
      iVar15 = iStack_38;
      iVar7 = iStack_38;
    }
    if (iStack_34 != 0) {
      piVar1 = *(int **)(iVar7 + 0x28);
      ppiVar11 = (int **)*piVar1;
      while (ppiVar11 != (int **)piVar1) {
        if (iStack_34 == 2) {
          iVar15 = *(int *)(iVar7 + 0x30) - (int)ppiVar11[0xb];
        }
        else {
          iVar15 = (*(int *)(iVar7 + 0x30) - (int)ppiVar11[0xb]) / 2;
        }
        ppiVar11[9] = (int *)iVar15;
        ppiVar11 = (int **)*ppiVar11;
      }
    }
    iStack_38 = iVar7;
    if (iStack_30 != 0) {
      func_0x81005af0();
    }
  }
  if (_UNK_8111a5b0 != puStack_2c) {
    uVar18 = func_0x811185a0();
    piVar1 = (int *)((ulonglong)uVar18 >> 0x20);
    puVar6 = (undefined4 *)uVar18;
    puVar6[3] = 0;
    puVar6[4] = 0;
    puVar6[5] = 0;
    puVar6[2] = 0;
    *puVar6 = &UNK_8114570c;
    iVar7 = *piVar1;
    puVar6[1] = 0;
    puVar6[6] = iVar7;
    if (iVar7 == 0) {
      puVar6[7] = 0;
      puVar6[8] = 0;
    }
    else {
      puVar6[7] = piVar1;
      puVar6[8] = piVar1[2];
      piVar1[2] = (int)(puVar6 + 6);
      *(undefined4 **)(puVar6[8] + 4) = puVar6 + 6;
    }
    puVar6[10] = 0;
    puVar6[0xb] = 0;
    iVar7 = func_0x81005a98(0x34);
    if (iVar7 != 0) {
      *(int *)iVar7 = iVar7;
    }
    if (iVar7 != -4) {
      *(int *)(iVar7 + 4) = iVar7;
    }
    puVar6[10] = iVar7;
    FUN_81072d36(puVar6,0,0);
    return puVar6;
  }
  return _UNK_8111a5b0;
}

