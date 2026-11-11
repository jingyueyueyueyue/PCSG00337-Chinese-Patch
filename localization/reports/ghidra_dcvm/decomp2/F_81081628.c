
int FUN_81081628(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1[1];
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    iVar2 = *(int *)(*param_1 + 4) + piVar1[1] * 8 + *piVar1 * 8 + 8;
  }
  return iVar2;
}

