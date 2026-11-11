
void FUN_81080974(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  if (*(char *)(param_1 + 0xc) != '\0') {
    piVar5 = *(int **)(param_1 + 4);
    piVar2 = (int *)0x0;
    while (piVar1 = piVar5, piVar1 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar1 + 8))();
      piVar4 = *(int **)(param_1 + 4);
      piVar5 = piVar1;
      if ((iVar3 == 0) || (*(int *)(iVar3 + 4) == 0)) {
        if (piVar1 != (int *)0x0) {
          piVar5 = (int *)piVar1[1];
        }
        if (piVar2 == (int *)0x0) {
          if (piVar4 != (int *)0x0) {
            *(int *)(param_1 + 4) = piVar4[1];
            piVar4[1] = 0;
            (**(code **)(*piVar4 + 4))(piVar4);
          }
        }
        else {
          piVar2[1] = (int)piVar5;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
        }
      }
      else {
        piVar2 = piVar1;
        if (piVar1 != (int *)0x0) {
          piVar5 = (int *)piVar1[1];
        }
      }
    }
  }
  *(undefined *)(param_1 + 0xc) = 0;
  return;
}

