
void FUN_810686a0(undefined4 *param_1,undefined4 param_2)

{
  short sVar1;
  uint in_fpscr;
  undefined4 uVar2;
  
  sVar1 = func_0x81069828(param_2,0x10);
  uVar2 = VectorSignedToFloat((int)sVar1,(byte)(in_fpscr >> 0x15) & 3);
  *param_1 = uVar2;
  sVar1 = func_0x81069828(param_2,0x10);
  uVar2 = VectorSignedToFloat((int)sVar1,(byte)(in_fpscr >> 0x15) & 3);
  param_1[1] = uVar2;
  return;
}

