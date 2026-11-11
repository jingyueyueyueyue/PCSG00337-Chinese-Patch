
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float FUN_8107d416(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  
  do {
    uVar1 = (**(code **)(*param_1 + 8))(param_1);
    iVar2 = (int)((ulonglong)uVar1 * (ulonglong)_DAT_8107d45c >> 0x20);
    uVar1 = uVar1 + (iVar2 + (uVar1 - iVar2 >> 1) >> 0xe) * -0x7532;
  } while (30000 < uVar1);
  fVar3 = (float)VectorUnsignedToFloat(uVar1,(byte)(in_fpscr >> 0x15) & 3);
  return fVar3 / 30000.0;
}

