
float FUN_810685ca(undefined4 param_1)

{
  byte bVar1;
  uint in_fpscr;
  float fVar2;
  
  bVar1 = func_0x81069828(param_1,8);
  fVar2 = (float)VectorUnsignedToFloat((uint)bVar1,(byte)(in_fpscr >> 0x15) & 3);
  return fVar2 / 255.0;
}

