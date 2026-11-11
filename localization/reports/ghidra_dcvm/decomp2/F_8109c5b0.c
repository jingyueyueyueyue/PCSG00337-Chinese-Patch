
void FUN_8109c5b0(int **param_1)

{
  int *piVar1;
  int **ppiVar2;
  int iVar3;
  int *piVar4;
  int **ppiVar5;
  
  piVar4 = *param_1;
  while (piVar4 != (int *)0x0) {
    piVar1 = (int *)piVar4[1];
    if (*piVar4 == 0) {
      *param_1 = piVar1;
      iVar3 = 0;
    }
    else {
      *(int **)(*piVar4 + 4) = piVar1;
      iVar3 = *piVar4;
      piVar1 = (int *)piVar4[1];
    }
    if (piVar1 == (int *)0x0) {
      param_1[1] = (int *)iVar3;
    }
    else {
      *piVar1 = iVar3;
    }
    *piVar4 = 0;
    piVar4[1] = 0;
    FUN_81094e48(piVar4);
    func_0x81005af0();
    piVar4 = *param_1;
  }
  ppiVar5 = (int **)param_1[2];
  while (ppiVar5 != (int **)0x0) {
    ppiVar2 = (int **)ppiVar5[1];
    if (*ppiVar5 == (int *)0x0) {
      param_1[2] = (int *)ppiVar2;
      piVar4 = (int *)0x0;
    }
    else {
      (*ppiVar5)[1] = (int)ppiVar2;
      piVar4 = *ppiVar5;
      ppiVar2 = (int **)ppiVar5[1];
    }
    if (ppiVar2 == (int **)0x0) {
      param_1[3] = piVar4;
    }
    else {
      *ppiVar2 = piVar4;
    }
    *ppiVar5 = (int *)0x0;
    ppiVar5[1] = (int *)0x0;
    FUN_81094e48(ppiVar5);
    func_0x81005af0();
    ppiVar5 = (int **)param_1[2];
  }
  return;
}

