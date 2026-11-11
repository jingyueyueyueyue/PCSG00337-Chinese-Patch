
int FUN_8107e268(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1[7] == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1,param_2);
    param_1[9] = iVar1;
    (**(code **)(*(int *)param_1[4] + 0x14))((int *)param_1[4],param_2);
    iVar1 = param_1[9];
  }
  return iVar1;
}

