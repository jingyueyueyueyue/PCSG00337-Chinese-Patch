
void FUN_81073fba(float param_1,int param_2)

{
  float fVar1;
  
  *(float *)(param_2 + 0xb4) = param_1;
  *(uint *)(param_2 + 0x84) = *(uint *)(param_2 + 0x84) | 0x8000000;
  fVar1 = (float)func_0x81118480(-param_1);
  if (fVar1 <= 1e-05) {
    *(uint *)(param_2 + 0x84) = *(uint *)(param_2 + 0x84) & 0xf7ffffff;
  }
  *(uint *)(param_2 + 0x88) = *(uint *)(param_2 + 0x88) | 3;
  return;
}

