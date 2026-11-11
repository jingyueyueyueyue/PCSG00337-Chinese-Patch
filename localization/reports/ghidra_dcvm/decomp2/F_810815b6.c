
undefined4 FUN_810815b6(int *param_1,int *param_2,undefined4 param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  
  puVar1 = (uint *)FUN_810812b0(param_1,param_3);
  if (puVar1 == (uint *)0x0) {
    param_1[2] = 2;
    uVar2 = 0;
  }
  else {
    param_1[2] = 0;
    if ((*puVar1 & 0xf) == 3) {
      *param_2 = *param_1;
      param_2[1] = param_1[1];
      param_2[2] = param_1[2];
      param_2[1] = *(int *)(*param_1 + 8) + puVar1[1] * 8 + 8;
      uVar2 = 1;
    }
    else {
      param_1[2] = 3;
      uVar2 = 0;
    }
  }
  return uVar2;
}

