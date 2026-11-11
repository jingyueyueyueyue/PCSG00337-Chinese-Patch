
void FUN_810964c8(uint *param_1,uint param_2,int param_3)

{
  *param_1 = *param_1 & 0xffffff00 | 0x23;
  param_1[1] = param_2 | param_3 << 8;
  return;
}

