
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810787f6(int param_1,int **param_2)

{
  char cVar1;
  int **ppiVar2;
  int iVar3;
  int iVar4;
  int **ppiVar5;
  int **ppiVar6;
  int **ppiVar7;
  bool bVar8;
  int *piStack_28;
  int *piStack_24;
  int **ppiStack_20;
  int **ppiStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  piStack_28 = (int *)(**(code **)(**param_2 + 8))();
  piStack_24 = *param_2;
  if (piStack_24 == (int *)0x0) {
    ppiStack_20 = (int **)0x0;
    ppiStack_1c = (int **)0x0;
  }
  else {
    ppiStack_1c = (int **)param_2[2];
    param_2[2] = (int *)&piStack_24;
    ppiStack_1c[1] = (int *)&piStack_24;
    ppiStack_20 = param_2;
  }
  ppiVar6 = *(int ***)(param_1 + 0x18);
  bVar8 = true;
  cVar1 = *(char *)((int)ppiVar6[1] + 0x1d);
  ppiVar2 = ppiVar6;
  ppiVar7 = (int **)ppiVar6[1];
  while (cVar1 == '\0') {
    bVar8 = piStack_28 < ppiVar7[3];
    if (bVar8) {
      ppiVar5 = (int **)*ppiVar7;
    }
    else {
      ppiVar5 = (int **)ppiVar7[2];
    }
    ppiVar2 = ppiVar7;
    ppiVar7 = ppiVar5;
    cVar1 = *(char *)((int)ppiVar5 + 0x1d);
  }
  ppiVar7 = ppiVar2;
  if (bVar8 != false) {
    if (ppiVar2 == (int **)*ppiVar6) {
      func_0x811042a8(param_1 + 0x14,1,ppiVar2,&piStack_28,bVar8);
      goto LAB_810788e6;
    }
    if (*(char *)((int)ppiVar2 + 0x1d) == '\0') {
      ppiVar7 = (int **)*ppiVar2;
      ppiVar6 = ppiVar2;
      if (*(char *)((int)ppiVar7 + 0x1d) == '\0') {
        cVar1 = *(char *)((int)ppiVar7[2] + 0x1d);
        ppiVar6 = (int **)ppiVar7[2];
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)ppiVar6[2] + 0x1d);
          ppiVar7 = ppiVar6;
          ppiVar6 = (int **)ppiVar6[2];
        }
      }
      else {
        do {
          ppiVar7 = ppiVar6;
          ppiVar6 = (int **)ppiVar7[1];
          if (*(char *)((int)ppiVar6 + 0x1d) != '\0') break;
        } while (ppiVar7 == (int **)*ppiVar6);
        if (*(char *)((int)ppiVar7 + 0x1d) == '\0') {
          ppiVar7 = ppiVar6;
        }
      }
    }
    else {
      ppiVar7 = (int **)ppiVar2[2];
    }
  }
  if (ppiVar7[3] < piStack_28) {
    func_0x811042a8(param_1 + 0x14,bVar8,ppiVar2,&piStack_28,(char)param_1);
  }
LAB_810788e6:
  if (piStack_24 != (int *)0x0) {
    if (&piStack_24 == ppiStack_1c) {
      func_0x811047dc();
    }
    else {
      ppiStack_1c[1] = (int *)ppiStack_20;
      ppiStack_20[2] = (int *)ppiStack_1c;
    }
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  iVar3 = func_0x811185a0();
  func_0x811037fc(iVar3 + 0x14,*(undefined4 *)(*(int *)(iVar3 + 0x18) + 4));
  iVar4 = *(int *)(iVar3 + 0x18);
  *(int *)iVar4 = iVar4;
  *(int *)(iVar4 + 4) = iVar4;
  *(int *)(iVar4 + 8) = iVar4;
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  return;
}

