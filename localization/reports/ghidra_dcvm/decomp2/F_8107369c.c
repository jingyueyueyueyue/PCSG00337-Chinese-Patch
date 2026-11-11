
void FUN_8107369c(float param_1,undefined4 param_2,int param_3,char param_4)

{
  float fVar1;
  
  *(undefined4 *)(param_3 + 0x18) = param_2;
  *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | 1;
  *(float *)(param_3 + 0x14) = param_1;
  if (param_4 != '\0') {
    fVar1 = (float)func_0x81118480(1.0 - param_1);
    if (fVar1 < 1e-05 != NAN(fVar1)) {
      fVar1 = (float)func_0x81118480(1.0 - *(float *)(param_3 + 0x18));
      if (fVar1 < 1e-05 != NAN(fVar1)) {
        *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) & 0xfffffffe;
      }
    }
  }
  return;
}

