
undefined4 FUN_810733f0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2[1] == 0) {
    uVar1 = 0;
  }
  else {
    if (param_1 != param_2) {
      FUN_8107db94(param_1);
      param_1[1] = param_2[1];
      *param_1 = *param_2;
      *param_2 = 0;
      param_2[1] = 0;
    }
    uVar1 = 0;
    if (*(int *)param_1[1] == 0x49504344) {
      uVar1 = 1;
    }
  }
  return uVar1;
}

