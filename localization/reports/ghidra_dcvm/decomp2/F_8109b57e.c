
int * FUN_8109b57e(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 4);
    piVar2 = (int *)0x0;
    if (*piVar1 == 0x4d564344) {
      piVar2 = piVar1;
    }
    piVar1 = piVar2 + 4;
    if (piVar2[1] == 0x10) {
      piVar1 = (int *)0x0;
    }
    else {
      uVar4 = 0;
      while ((piVar1 != (int *)0x0 && (*piVar1 != 0x524f5453))) {
        iVar3 = piVar1[1];
        uVar4 = uVar4 + iVar3;
        if ((uVar4 < piVar2[1] - 0x10U) && (iVar3 != -1)) {
          piVar1 = (int *)((int)piVar1 + iVar3);
        }
        else {
          piVar1 = (int *)0x0;
        }
      }
    }
  }
  return piVar1;
}

