
int * FUN_81065f0e(int *param_1)

{
  int iVar1;
  
  if (*param_1 != 0) {
    if (param_1 == (int *)param_1[2]) {
      func_0x810df5d0();
    }
    else {
      iVar1 = param_1[1];
      ((int *)param_1[2])[1] = iVar1;
      *(int *)(iVar1 + 8) = param_1[2];
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}

