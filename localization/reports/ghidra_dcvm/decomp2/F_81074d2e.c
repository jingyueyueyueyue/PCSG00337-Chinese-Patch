
undefined4 FUN_81074d2e(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_8107db94();
  piVar2 = (int *)param_2[1];
  if (*piVar2 == 0x53534344) {
    param_1[3] = piVar2[1];
    if (param_1 != param_2) {
      FUN_8107db94(param_1);
      param_1[1] = param_2[1];
      *param_1 = *param_2;
      *param_2 = 0;
      param_2[1] = 0;
    }
    param_1[2] = piVar2 + 0x10;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

