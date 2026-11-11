
int FUN_8107e0f2(int *param_1,uint param_2)

{
  int **ppiVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1[1];
  iVar3 = param_2 * 4;
  iVar5 = *(int *)(iVar4 + iVar3);
  if (iVar5 != -1) {
    if (param_2 != 1) {
      ppiVar1 = (int **)(iVar3 + *param_1);
      do {
        ppiVar1 = ppiVar1 + -1;
        param_2 = param_2 - 1;
        if (*ppiVar1 != (int *)0x0) {
          iVar5 = 0;
          for (piVar2 = (int *)**ppiVar1; piVar2 != (int *)*(int *)(*param_1 + iVar3);
              piVar2 = (int *)*piVar2) {
            iVar5 = iVar5 + 1;
          }
          *(int *)(iVar4 + iVar3) = iVar5;
          return iVar5;
        }
      } while (1 < param_2);
    }
    iVar5 = 0;
    *(undefined4 *)(iVar4 + iVar3) = 0;
  }
  return iVar5;
}

