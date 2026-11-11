
void FUN_8106a2a0(undefined4 param_1,int **param_2)

{
  int *piVar1;
  int **ppiVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = *param_2;
  while (piVar4 != (int *)0x0) {
    piVar1 = (int *)0x0;
    if (piVar4 != (int *)0x0) {
      piVar1 = piVar4 + 1;
    }
    if (*piVar1 == 0) {
      piVar1 = (int *)0x0;
      if (piVar4 != (int *)0x0) {
        piVar1 = piVar4 + 1;
      }
      *param_2 = (int *)piVar1[1];
    }
    else {
      piVar1 = (int *)0x0;
      if (piVar4 != (int *)0x0) {
        piVar1 = piVar4 + 1;
      }
      piVar3 = (int *)0x0;
      if (piVar4 != (int *)0x0) {
        piVar3 = piVar4 + 1;
      }
      *(int *)(*piVar3 + 8) = piVar1[1];
    }
    piVar1 = (int *)0x0;
    if (piVar4 != (int *)0x0) {
      piVar1 = piVar4 + 1;
    }
    if (piVar1[1] == 0) {
      ppiVar2 = (int **)0x0;
      if (piVar4 != (int *)0x0) {
        ppiVar2 = (int **)(piVar4 + 1);
      }
      param_2[1] = *ppiVar2;
    }
    else {
      piVar1 = (int *)0x0;
      if (piVar4 != (int *)0x0) {
        piVar1 = piVar4 + 1;
      }
      piVar3 = (int *)0x0;
      if (piVar4 != (int *)0x0) {
        piVar3 = piVar4 + 1;
      }
      *(int *)(piVar3[1] + 4) = *piVar1;
    }
    piVar1 = (int *)0x0;
    if (piVar4 != (int *)0x0) {
      piVar1 = piVar4 + 1;
    }
    piVar1[1] = 0;
    piVar1 = (int *)0x0;
    if (piVar4 != (int *)0x0) {
      piVar1 = piVar4 + 1;
    }
    *piVar1 = 0;
    (**(code **)(*piVar4 + 0xc))(piVar4);
    piVar4 = *param_2;
  }
  return;
}

