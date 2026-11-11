
undefined4 * FUN_81072b4c(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &UNK_811457a4;
  if (param_1[6] != 0) {
    if (param_1 + 6 == (undefined4 *)param_1[8]) {
      func_0x81101ac4();
    }
    else {
      iVar1 = param_1[7];
      ((undefined4 *)param_1[8])[1] = iVar1;
      *(undefined4 *)(iVar1 + 8) = param_1[8];
    }
  }
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *param_1 = &UNK_81145684;
  return param_1;
}

