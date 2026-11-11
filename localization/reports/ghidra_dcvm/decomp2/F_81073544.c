
void FUN_81073544(float param_1,int param_2,char param_3)

{
  uint uVar1;
  float fVar2;
  
  if (param_1 != 3.141593 && param_1 < 3.141593 == NAN(param_1)) {
    do {
      param_1 = param_1 - 6.283185;
    } while (param_1 != 3.141593 && param_1 < 3.141593 == NAN(param_1));
  }
  for (; (int)((uint)(param_1 < -3.141593) << 0x1f) < 0; param_1 = param_1 + 6.283185) {
  }
  *(float *)(param_2 + 0x1c) = param_1;
  uVar1 = *(uint *)(param_2 + 4) & 0xffffffe3 | 2;
  *(uint *)(param_2 + 4) = uVar1;
  if (param_3 != '\0') {
    fVar2 = (float)func_0x81118480(-param_1);
    uVar1 = *(uint *)(param_2 + 4);
    param_1 = *(float *)(param_2 + 0x1c);
    if (fVar2 < 1e-05 != NAN(fVar2)) {
      uVar1 = uVar1 & 0xfffffffd;
      *(uint *)(param_2 + 4) = uVar1;
    }
  }
  if ((uVar1 & 2) != 0) {
    fVar2 = (float)func_0x81118480(3.141593 - param_1);
    if (fVar2 <= 1e-05) {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 8;
    }
    else {
      fVar2 = (float)func_0x81118480(1.570796 - *(float *)(param_2 + 0x1c));
      if (fVar2 <= 1e-05) {
        *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 4;
      }
      else {
        fVar2 = (float)func_0x81118480(-1.570796 - *(float *)(param_2 + 0x1c));
        if (fVar2 <= 1e-05) {
          *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 0x10;
        }
      }
    }
  }
  return;
}

