
void FUN_810897d2(uint *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = param_2 + 3U & 0xfffffffc;
  *param_1 = uVar1;
  param_1[4] = param_4;
  uVar1 = param_3 - (uVar1 - param_2);
  param_1[1] = uVar1;
  param_1[3] = uVar1 >> 2;
  param_1[2] = 0;
  return;
}

