
undefined4 FUN_8108d088(void)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  undefined4 uVar3;
  
  iVar1 = func_0x811186b0();
  if (iVar1 < 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  fVar2 = (float)VectorSignedToFloat(iVar1 + -0x40,(byte)(in_fpscr >> 0x15) & 3);
  uVar3 = VectorFloatToUnsigned((fVar2 / 127.0) * 105.0,3);
  return uVar3;
}

