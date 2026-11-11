
int ** FUN_81067070(int **param_1)

{
  int *piVar1;
  
  FUN_81074dfc(param_1 + 6);
  if (param_1[5] != (int *)0x0) {
    (**(code **)(*param_1[5] + 4))();
  }
  param_1[5] = (int *)0x0;
  if (param_1[4] != (int *)0x0) {
    (**(code **)(*param_1[4] + 4))();
  }
  param_1[4] = (int *)0x0;
  if (param_1[1] != (int *)0x0) {
    if (param_1 + 1 == (int **)param_1[3]) {
      func_0x81101ac4();
    }
    else {
      piVar1 = param_1[2];
      param_1[3][1] = (int)piVar1;
      piVar1[2] = (int)param_1[3];
    }
  }
  param_1[1] = (int *)0x0;
  param_1[2] = (int *)0x0;
  param_1[3] = (int *)0x0;
  if (*param_1 != (int *)0x0) {
    (**(code **)(**param_1 + 4))();
  }
  *param_1 = (int *)0x0;
  return param_1;
}

