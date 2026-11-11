
void FUN_81085fdc(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[2] = 0;
  *param_1 = param_3;
  param_1[1] = param_4;
  iVar1 = *param_2;
  param_1[3] = iVar1;
  if (iVar1 == 0) {
    param_1[4] = 0;
    param_1[5] = 0;
  }
  else {
    param_1[4] = param_2;
    param_1[5] = param_2[2];
    param_2[2] = (int)(param_1 + 3);
    *(undefined4 **)(param_1[5] + 4) = param_1 + 3;
  }
  param_1[6] = 0;
  iVar1 = 5;
  param_1[7] = 0;
  puVar2 = param_1 + 9;
  param_1[8] = 0;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2 = puVar2 + 3;
  } while (iVar1 != 0);
  return;
}

