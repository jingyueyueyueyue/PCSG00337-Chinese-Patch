
void FUN_8108405e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = (float)VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x15) & 3);
  fVar3 = (float)VectorSignedToFloat(param_5,(byte)(in_fpscr >> 0x15) & 3);
  fVar2 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x15) & 3);
  fVar4 = (float)VectorSignedToFloat(param_3,(byte)(in_fpscr >> 0x15) & 3);
  func_0x81116880(fVar2 + fVar1 * 0.5,fVar1 * 0.5,fVar4 + fVar3 * 0.5,fVar3 * 0.5,0,0x3f800000,
                  *(undefined4 *)(**(int **)(param_1 + 4) + 4));
  return;
}

