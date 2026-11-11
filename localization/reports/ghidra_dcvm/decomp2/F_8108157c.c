
undefined4 FUN_8108157c(int *param_1,int *param_2,uint **param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  
  puVar2 = *param_3;
  if ((puVar2 == (uint *)0x0) || ((*puVar2 & 0xf) != 3)) {
    param_1[2] = 3;
    uVar1 = 0;
  }
  else {
    param_1[2] = 0;
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2[2] = param_1[2];
    param_2[1] = *(int *)(*param_1 + 8) + puVar2[1] * 8 + 8;
    uVar1 = 1;
  }
  return uVar1;
}

