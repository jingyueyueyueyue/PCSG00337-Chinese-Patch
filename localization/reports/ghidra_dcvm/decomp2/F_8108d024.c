
void FUN_8108d024(uint param_1)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  undefined4 uVar3;
  
  iVar1 = func_0x81118520();
  if (iVar1 < 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (0x69 < param_1) {
    param_1 = 0x69;
  }
  fVar2 = (float)VectorUnsignedToFloat(param_1,(byte)(in_fpscr >> 0x15) & 3);
  uVar3 = VectorFloatToUnsigned((fVar2 / 105.0) * 127.0 + 64.0,3);
  iVar1 = func_0x81118880(iVar1,uVar3);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  return;
}

