
undefined4 FUN_8109cb78(int **param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int **ppiVar5;
  int **ppiVar6;
  int **ppiVar7;
  
  param_1[0x11] = (int *)param_2;
  if (param_1[7] != (int *)0x0) {
    FUN_8109abb4();
  }
  if ((param_1[0x16] == (int *)0x0) &&
     ((ppiVar7 = (int **)*param_1, ppiVar7 != (int **)0x0 || (param_1[2] != (int *)0x0)))) {
    while (ppiVar7 != (int **)0x0) {
      ppiVar6 = (int **)ppiVar7[1];
      if (*ppiVar7 == (int *)0x0) {
        *param_1 = (int *)ppiVar6;
        piVar4 = (int *)0x0;
      }
      else {
        (*ppiVar7)[1] = (int)ppiVar6;
        piVar4 = *ppiVar7;
        ppiVar6 = (int **)ppiVar7[1];
      }
      if (ppiVar6 == (int **)0x0) {
        param_1[1] = piVar4;
      }
      else {
        *ppiVar6 = piVar4;
      }
      *ppiVar7 = (int *)0x0;
      ppiVar7[1] = (int *)0x0;
      FUN_810949fe(ppiVar7,1);
      piVar4 = param_1[3];
      ppiVar6 = (int **)*param_1;
      if (piVar4 == (int *)0x0) {
        *ppiVar7 = (int *)0x0;
        ppiVar7[1] = (int *)0x0;
        param_1[2] = (int *)ppiVar7;
      }
      else {
        *ppiVar7 = piVar4;
        ppiVar7[1] = (int *)0x0;
        piVar4[1] = (int)ppiVar7;
      }
      param_1[3] = (int *)ppiVar7;
      ppiVar7 = ppiVar6;
    }
    iVar2 = func_0x81118250(0x811adc60);
    if (iVar2 == 0) {
      ppiVar7 = (int **)param_1[2];
      while (ppiVar7 != (int **)0x0) {
        if (ppiVar7[0xd] == (int *)0x1) {
          FUN_81095606();
        }
        if (ppiVar7[0xd] == (int *)0x2) {
          ppiVar6 = (int **)ppiVar7[1];
          if (*ppiVar7 == (int *)0x0) {
            param_1[2] = (int *)ppiVar6;
            piVar4 = (int *)0x0;
            ppiVar5 = ppiVar6;
          }
          else {
            (*ppiVar7)[1] = (int)ppiVar6;
            piVar4 = *ppiVar7;
            ppiVar5 = (int **)ppiVar7[1];
          }
          if (ppiVar5 == (int **)0x0) {
            param_1[3] = piVar4;
          }
          else {
            *ppiVar5 = piVar4;
          }
          *ppiVar7 = (int *)0x0;
          ppiVar7[1] = (int *)0x0;
          bVar1 = ppiVar7 != (int **)0x0;
          ppiVar7 = ppiVar6;
          if (bVar1) {
            FUN_81094e48();
            func_0x81005af0();
          }
        }
        else if (ppiVar7 != (int **)0x0) {
          ppiVar7 = (int **)ppiVar7[1];
        }
      }
    }
    else {
      piVar3 = (int *)func_0x81005a98(0x7c);
      piVar4 = (int *)0x0;
      if (piVar3 != (int *)0x0) {
        func_0x8110cb00(piVar3,0x811add20);
        func_0x8110cb00(piVar3 + 7,0x811add3c);
        func_0x8110cb00(piVar3 + 0xe,0x811add58);
        func_0x8110cb00(piVar3 + 0x15,0x811add74);
        piVar3[0x1c] = iRam811add90;
        piVar3[0x1d] = iRam811add94;
        piVar3[0x1e] = iRam811add98;
        piVar4 = piVar3;
      }
      piVar3 = param_1[0x16];
      param_1[0x16] = piVar4;
      if (piVar3 != (int *)0x0) {
        if (0xf < (uint)piVar3[0x1b]) {
          func_0x81005af0(piVar3[0x16]);
        }
        piVar3[0x1a] = 0;
        piVar3[0x1b] = 0xf;
        *(undefined *)(piVar3 + 0x16) = 0;
        if (0xf < (uint)piVar3[0x14]) {
          func_0x81005af0(piVar3[0xf]);
        }
        piVar3[0x13] = 0;
        piVar3[0x14] = 0xf;
        *(undefined *)(piVar3 + 0xf) = 0;
        if (0xf < (uint)piVar3[0xd]) {
          func_0x81005af0(piVar3[8]);
        }
        piVar3[0xc] = 0;
        piVar3[0xd] = 0xf;
        *(undefined *)(piVar3 + 8) = 0;
        if (0xf < (uint)piVar3[6]) {
          func_0x81005af0(piVar3[1]);
        }
        *(undefined *)(piVar3 + 1) = 0;
        piVar3[5] = 0;
        piVar3[6] = 0xf;
        func_0x81005af0(piVar3);
      }
    }
    *(undefined *)(param_1 + 0x15) = 0;
    if ((*param_1 != (int *)0x0) || (param_1[2] != (int *)0x0)) {
      return 1;
    }
  }
  return 0;
}

