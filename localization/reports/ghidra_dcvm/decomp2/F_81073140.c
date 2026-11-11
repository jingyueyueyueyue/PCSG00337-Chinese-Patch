
undefined4 * FUN_81073140(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = &UNK_8114570c;
  param_1[1] = 0;
  iVar1 = func_0x81005a98(0xa0);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = FUN_81087f9c(iVar1);
  }
  puVar3 = (undefined4 *)0x0;
  param_1[6] = iVar2;
  if (iVar2 != 0) {
    puVar3 = param_1 + 6;
  }
  param_1[7] = puVar3;
  param_1[8] = puVar3;
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
  (**(code **)(*(int *)param_1[6] + 8))((int *)param_1[6]);
  FUN_81072d36(param_1,0,0);
  return param_1;
}

