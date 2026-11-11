
int ** FUN_8109bafa(int **param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *param_1;
  while (piVar1 != (int *)0x0) {
    piVar2 = (int *)piVar1[2];
    if (piVar1[1] == 0) {
      *param_1 = (int *)piVar1[2];
    }
    else {
      *(int *)(piVar1[1] + 8) = piVar1[2];
    }
    if (piVar1[2] == 0) {
      param_1[1] = (int *)piVar1[1];
    }
    else {
      *(int *)(piVar1[2] + 4) = piVar1[1];
    }
    piVar1[2] = 0;
    piVar1[1] = 0;
    (**(code **)(*piVar1 + 4))(piVar1);
    piVar1 = piVar2;
  }
  return param_1;
}

