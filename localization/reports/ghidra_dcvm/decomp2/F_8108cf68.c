
void FUN_8108cf68(undefined4 *param_1,uint param_2)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  undefined4 uVar3;
  
  if (0x69 < param_2) {
    param_2 = 0x69;
  }
  fVar2 = (float)VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x15) & 3);
  uVar3 = VectorFloatToUnsigned((fVar2 / 105.0) * 127.0 + 64.0,3);
  iVar1 = func_0x81118880(*(undefined4 *)*param_1,uVar3);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  return;
}

