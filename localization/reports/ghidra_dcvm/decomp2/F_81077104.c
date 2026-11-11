
undefined4 FUN_81077104(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int **ppiVar3;
  int *piVar4;
  
  piVar2 = *(int **)(param_1 + 0xc);
  while ((piVar4 = (int *)0x0, piVar2 != (int *)0x0 && (piVar4 = piVar2, (piVar2[6] & 3U) != 0))) {
    if (piVar2 != (int *)0x0) {
      piVar2 = (int *)piVar2[1];
    }
  }
  for (; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
    if (((uint)piVar2[5] <= (uint)piVar4[5]) && ((piVar2[6] & 3U) == 0)) {
      piVar4 = piVar2;
    }
  }
  if (piVar4 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    if (piVar4[4] != 0) {
      (**(code **)(**(int **)(param_1 + 8) + 0x10))();
    }
    piVar2 = (int *)piVar4[1];
    if (*piVar4 == 0) {
      *(int **)(param_1 + 0xc) = piVar2;
    }
    else {
      *(int **)(*piVar4 + 4) = piVar2;
      piVar2 = (int *)piVar4[1];
    }
    if (piVar2 == (int *)0x0) {
      *(int *)(param_1 + 0x10) = *piVar4;
    }
    else {
      *piVar2 = *piVar4;
    }
    ppiVar3 = *(int ***)(param_1 + 0x14);
    if (ppiVar3 == (int **)0x0) {
      piVar4[1] = 0;
      *(int **)(param_1 + 0x18) = piVar4;
    }
    else {
      piVar4[1] = (int)ppiVar3;
      *piVar4 = 0;
      *ppiVar3 = piVar4;
    }
    *piVar4 = 0;
    uVar1 = 1;
    *(int **)(param_1 + 0x14) = piVar4;
  }
  return uVar1;
}

