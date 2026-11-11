
void FUN_8107c9de(int param_1)

{
  int **ppiVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 4);
  uVar2 = 0;
  ppiVar1 = *(int ***)(param_1 + 8);
  if (uVar3 != 0) {
    do {
      if (*ppiVar1 != (int *)0x0) {
        (**(code **)(**ppiVar1 + 0x24))();
      }
      uVar2 = uVar2 + 1;
      ppiVar1 = ppiVar1 + 1;
    } while (uVar2 < uVar3);
  }
  return;
}

