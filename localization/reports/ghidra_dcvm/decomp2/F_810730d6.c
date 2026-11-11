
undefined4 * FUN_810730d6(undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[2] = 0;
  *param_1 = &UNK_8114570c;
  iVar1 = *param_2;
  param_1[1] = 0;
  param_1[6] = iVar1;
  if (iVar1 == 0) {
    param_1[7] = 0;
    param_1[8] = 0;
  }
  else {
    param_1[7] = param_2;
    param_1[8] = param_2[2];
    param_2[2] = (int)(param_1 + 6);
    *(undefined4 **)(param_1[8] + 4) = param_1 + 6;
  }
  param_1[10] = 0;
  param_1[0xb] = 0;
  iVar1 = func_0x81005a98(0x34);
  if (iVar1 != 0) {
    *(int *)iVar1 = iVar1;
  }
  if (iVar1 != -4) {
    *(int *)(iVar1 + 4) = iVar1;
  }
  param_1[10] = iVar1;
  FUN_81072d36(param_1,0,0);
  return param_1;
}

