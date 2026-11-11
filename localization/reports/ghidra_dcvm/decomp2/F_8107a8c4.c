
void FUN_8107a8c4(float *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  float fVar4;
  uint in_fpscr;
  
  fVar1 = param_1[4];
  if (fVar1 != 0.0) {
    if (param_2 == 0) {
      param_2 = 1;
    }
    fVar4 = (float)((int)param_1[3] + param_2);
    param_1[3] = fVar4;
    if ((uint)fVar1 < (uint)fVar4) {
      param_1[3] = fVar1;
      fVar4 = fVar1;
    }
    switch(param_1[5]) {
    default:
      if (fVar1 == fVar4) {
        *param_1 = param_1[2];
      }
      break;
    case 1.401298e-45:
      fVar4 = (float)VectorUnsignedToFloat(fVar4,(byte)(in_fpscr >> 0x15) & 3);
      fVar1 = (float)VectorUnsignedToFloat(fVar1,(byte)(in_fpscr >> 0x15) & 3);
      *param_1 = (param_1[2] - param_1[1]) * (fVar4 / fVar1) + param_1[1];
      break;
    case 2.802597e-45:
    case 4.203895e-45:
    case 5.605194e-45:
    case 7.006492e-45:
      iVar2 = func_0x810c8324(fVar1,(int)param_1[5] + -1);
      uVar3 = func_0x810c83e2(fVar4,iVar2 + 1);
      fVar1 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x15) & 3);
      fVar4 = (float)VectorUnsignedToFloat(iVar2,(byte)(in_fpscr >> 0x15) & 3);
      fVar1 = fVar1 / fVar4;
      if ((fVar1 <= 0.25) || (fVar1 < 0.75 == NAN(fVar1))) {
        *param_1 = param_1[1];
      }
      else {
        *param_1 = param_1[2];
      }
    }
    fVar1 = *param_1;
    if (fVar1 <= 0.0) {
      *param_1 = 0.0;
    }
    else if (fVar1 < 1.0 == NAN(fVar1)) {
      *param_1 = 1.0;
    }
  }
  return;
}

