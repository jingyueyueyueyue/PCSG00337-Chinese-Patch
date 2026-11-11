
void FUN_8106ded0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  uVar1 = param_2[5];
  *(undefined2 *)((int)param_1 + 4) = *(undefined2 *)((int)param_1 + 0xc);
  *(undefined2 *)((int)param_1 + 6) = *(undefined2 *)((int)param_1 + 0xe);
  param_1[5] = uVar1;
  *(undefined2 *)(param_1 + 3) = 0;
  *(undefined2 *)((int)param_1 + 0x1a) = 0;
  return;
}

