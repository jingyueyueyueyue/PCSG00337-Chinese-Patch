
void FUN_81086e3e(int param_1)

{
  float *pfVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  
  pfVar1 = (float *)FUN_810897ee(*(undefined4 *)(*(int *)(iRam811ae690 + 4) + 0x40),0x40);
  fVar2 = (float)VectorUnsignedToFloat
                           (*(undefined4 *)(*(int *)(param_1 + 8) + 0x38),
                            (byte)(in_fpscr >> 0x15) & 3);
  fVar3 = (float)VectorUnsignedToFloat
                           (*(undefined4 *)(*(int *)(param_1 + 8) + 0x3c),
                            (byte)(in_fpscr >> 0x15) & 3);
  *(float **)(param_1 + 0x10) = pfVar1;
  pfVar1[1] = 0.0;
  pfVar1[2] = 0.0;
  pfVar1[3] = -1.0;
  *pfVar1 = 1.0 / (fVar2 * 0.5);
  pfVar1[4] = 0.0;
  pfVar1[5] = 1.0 / (fVar3 * 0.5);
  pfVar1[6] = 0.0;
  pfVar1[7] = -1.0;
  pfVar1[8] = 0.0;
  pfVar1[9] = 0.0;
  pfVar1[10] = 3.051851e-05;
  pfVar1[0xb] = 0.0;
  pfVar1[0xc] = 0.0;
  pfVar1[0xd] = 0.0;
  pfVar1[0xe] = 0.0;
  pfVar1[0xf] = 1.0;
  return;
}

