
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8109ac3e(int param_1,undefined4 param_2)

{
  char cVar1;
  int **ppiVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined extraout_r1;
  int *piVar6;
  int *piVar7;
  int **ppiVar8;
  int *piVar9;
  int **ppiVar10;
  undefined8 uVar11;
  int iStack_50;
  int iStack_4c;
  int *piStack_44;
  int iStack_40;
  int *piStack_3c;
  undefined *puStack_38;
  undefined4 auStack_24 [2];
  undefined4 uStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  uStack_1c = 0;
  func_0x8108d650(auStack_24,0,8);
  piVar6 = *(int **)(param_1 + 0x18);
  piVar9 = (int *)piVar6[1];
  piVar7 = piVar6;
  auStack_24[0] = param_2;
  if (*(char *)((int)piVar9 + 0x11) == '\0') {
    do {
      piVar7 = piVar9;
      iVar3 = func_0x811181a0(*(undefined4 *)(piVar7[3] + 4),auStack_24[0]);
      if (iVar3 < 0) {
        piVar9 = (int *)piVar7[2];
        cVar1 = *(char *)((int)piVar9 + 0x11);
        piVar7 = piVar6;
      }
      else {
        piVar9 = (int *)*piVar7;
        cVar1 = *(char *)((int)piVar9 + 0x11);
      }
      piVar6 = piVar7;
    } while (cVar1 == '\0');
    piVar6 = *(int **)(param_1 + 0x18);
  }
  if (piVar7 == piVar6) {
LAB_8109acc0:
    piStack_44 = piVar6;
  }
  else {
    iVar3 = func_0x811181a0(auStack_24[0],*(undefined4 *)(piVar7[3] + 4));
    piVar6 = *(int **)(param_1 + 0x18);
    piStack_44 = piVar7;
    if (iVar3 < 0) goto LAB_8109acc0;
  }
  if (piVar6 == piStack_44) {
    iVar3 = 0;
  }
  else {
    iVar3 = piStack_44[3];
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar11 = func_0x811185a0(iVar3);
  iStack_4c = _UNK_8111a5b0;
  piVar7 = (int *)((ulonglong)uVar11 >> 0x20);
  iVar4 = (int)uVar11;
  puStack_38 = &UNK_8111a5b0;
  *(int *)(*piVar7 + 0xc) = iVar4;
  iVar3 = 1;
  iStack_50 = *piVar7;
  *piVar7 = 0;
  ppiVar8 = (int **)(*(int ***)(iVar4 + 0x18))[1];
  cVar1 = *(char *)((int)ppiVar8 + 0x11);
  ppiVar2 = *(int ***)(iVar4 + 0x18);
  piStack_3c = piVar9;
  iStack_40 = param_1;
  while (cVar1 == '\0') {
    uVar11 = func_0x811181a0(*(undefined4 *)(iStack_50 + 4),*(undefined4 *)((int)ppiVar8[3] + 4));
    piVar7 = (int *)((ulonglong)uVar11 >> 0x20);
    iVar3 = -((int)uVar11 >> 0x1f);
    if (iVar3 == 0) {
      piVar6 = ppiVar8[2];
    }
    else {
      piVar6 = *ppiVar8;
    }
    ppiVar2 = ppiVar8;
    ppiVar8 = (int **)piVar6;
    cVar1 = *(char *)((int)piVar6 + 0x11);
  }
  ppiVar8 = ppiVar2;
  if (iVar3 != 0) {
    if (ppiVar2 == (int **)**(int ***)(iVar4 + 0x18)) {
      func_0x8110c098(iVar4 + 0x14,1,ppiVar2,&iStack_50,(char)piVar7);
      goto LAB_8109adc6;
    }
    if (*(char *)((int)ppiVar2 + 0x11) == '\0') {
      ppiVar8 = (int **)*ppiVar2;
      ppiVar10 = ppiVar2;
      if (*(char *)((int)ppiVar8 + 0x11) == '\0') {
        cVar1 = *(char *)((int)ppiVar8[2] + 0x11);
        ppiVar10 = (int **)ppiVar8[2];
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)ppiVar10[2] + 0x11);
          ppiVar8 = ppiVar10;
          ppiVar10 = (int **)ppiVar10[2];
        }
      }
      else {
        do {
          ppiVar8 = ppiVar10;
          ppiVar10 = (int **)ppiVar8[1];
          if (*(char *)((int)ppiVar10 + 0x11) != '\0') break;
        } while (ppiVar8 == (int **)*ppiVar10);
        if (*(char *)((int)ppiVar8 + 0x11) == '\0') {
          ppiVar8 = ppiVar10;
        }
      }
    }
    else {
      ppiVar8 = (int **)ppiVar2[2];
    }
  }
  iVar5 = func_0x811181a0(ppiVar8[3][1],*(undefined4 *)(iStack_50 + 4));
  if (iVar5 < 0) {
    func_0x8110c098(iVar4 + 0x14,iVar3,ppiVar2,&iStack_50,extraout_r1);
  }
LAB_8109adc6:
  if (_UNK_8111a5b0 == iStack_4c) {
    return;
  }
  func_0x811185a0(1);
  return;
}

