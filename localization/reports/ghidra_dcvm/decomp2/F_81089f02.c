
int * FUN_81089f02(int *param_1)

{
  int iVar1;
  
  FUN_81089e8e();
  if (*param_1 != 0) {
    if (param_1 == (int *)param_1[2]) {
      func_0x810cf3ec();
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

