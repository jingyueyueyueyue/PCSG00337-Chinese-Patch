
void FUN_81096642(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = func_0x81069828(param_2,4);
  *param_1 = *param_1 & 0xffffff0f | (uVar1 & 0xf) << 4;
  uVar1 = func_0x81069828(param_2,4);
  *param_1 = uVar1 & 0xf | *param_1 & 0xfffffff0;
  FUN_810965b4(param_1,param_2);
  return;
}

