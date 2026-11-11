
void FUN_8108d0da(void)

{
  int *piVar1;
  int iVar2;
  int **ppiVar3;
  int *piVar4;
  int **ppiVar5;
  
  if (ppiRam811adc54 == (int **)0x0) {
    piVar1 = (int *)func_0x81005a98(8);
    piVar4 = (int *)0x0;
    if (piVar1 != (int *)0x0) {
      *piVar1 = -1;
      piVar1[1] = -1;
      piVar4 = piVar1;
    }
    iVar2 = func_0x81118520();
    *piVar4 = iVar2;
    if (*piVar4 < 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    ppiVar3 = (int **)func_0x81005a98(8);
    ppiVar5 = (int **)0x0;
    if (ppiVar3 != (int **)0x0) {
      *ppiVar3 = piVar4;
      func_0x8109db5c(ppiVar3);
      ppiVar5 = ppiVar3;
    }
    ppiRam811adc54 = ppiVar5;
    ppiVar5[1] = (int *)&UNK_81137be4;
  }
  return;
}

