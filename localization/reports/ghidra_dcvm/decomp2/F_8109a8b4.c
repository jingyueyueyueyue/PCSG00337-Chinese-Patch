
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8109a8b4(int param_1)

{
  char cVar1;
  int iVar2;
  int **ppiVar3;
  int *piVar4;
  int **ppiVar5;
  int **ppiVar6;
  int **ppiVar7;
  int *piVar8;
  int *piVar9;
  bool bVar10;
  undefined8 uVar11;
  undefined auStack_38 [16];
  undefined4 uStack_28;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  FUN_8109a86e(auStack_38);
  piVar4 = *(int **)(param_1 + 8);
  piVar8 = piVar4;
  piVar9 = (int *)piVar4[1];
  if (*(char *)((int)(int *)piVar4[1] + 0x11) == '\0') {
    do {
      piVar8 = piVar9;
      iVar2 = func_0x811181a0(*(undefined4 *)(piVar8[3] + 0x10),uStack_28);
      if (iVar2 < 0) {
        piVar9 = (int *)piVar8[2];
        cVar1 = *(char *)((int)piVar9 + 0x11);
        piVar8 = piVar4;
      }
      else {
        piVar9 = (int *)*piVar8;
        cVar1 = *(char *)((int)piVar9 + 0x11);
      }
      piVar4 = piVar8;
    } while (cVar1 == '\0');
    piVar4 = *(int **)(param_1 + 8);
  }
  if (piVar8 != piVar4) {
    iVar2 = func_0x811181a0(uStack_28,*(undefined4 *)(piVar8[3] + 0x10));
    piVar4 = *(int **)(param_1 + 8);
    if (-1 < iVar2) goto LAB_8109a914;
  }
  piVar8 = piVar4;
LAB_8109a914:
  if (piVar4 == piVar8) {
    FUN_8109a7dc(auStack_38);
    iVar2 = 0;
  }
  else {
    iVar2 = piVar8[3];
    FUN_8109a7dc(auStack_38);
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return iVar2;
  }
  uVar11 = func_0x811185a0(iVar2);
  ppiVar3 = *(int ***)((int)uVar11 + 0x18);
  ppiVar6 = (int **)*ppiVar3;
  do {
    while( true ) {
      do {
        if (ppiVar6 == ppiVar3) {
          return 0;
        }
        if ((int *)((ulonglong)uVar11 >> 0x20) == ppiVar6[3]) {
          return 1;
        }
      } while (*(char *)((int)ppiVar6 + 0x11) != '\0');
      ppiVar5 = (int **)ppiVar6[2];
      ppiVar7 = ppiVar6;
      if (*(char *)((int)ppiVar5 + 0x11) != '\0') break;
      cVar1 = *(char *)((int)*ppiVar5 + 0x11);
      ppiVar6 = ppiVar5;
      ppiVar7 = (int **)*ppiVar5;
      while (cVar1 == '\0') {
        cVar1 = *(char *)((int)*ppiVar7 + 0x11);
        ppiVar6 = ppiVar7;
        ppiVar7 = (int **)*ppiVar7;
      }
    }
    do {
      ppiVar6 = (int **)ppiVar7[1];
      if (*(char *)((int)ppiVar6 + 0x11) != '\0') break;
      bVar10 = ppiVar7 == (int **)ppiVar6[2];
      ppiVar7 = ppiVar6;
    } while (bVar10);
  } while( true );
}

