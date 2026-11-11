
void FUN_81075e4a(float param_1,float param_2,int *param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = 0;
  *param_3 = param_4;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  iVar4 = VectorFloatToUnsigned(param_1 * 65536.0,3);
  iVar5 = VectorFloatToUnsigned(param_2 * 65536.0,3);
  param_3[6] = param_5;
  param_3[7] = param_6;
  uVar2 = 0;
  iVar1 = *(int *)(param_4 + 0x20);
  param_3[8] = iVar4;
  param_3[9] = iVar5;
  if (iVar1 != 0) {
    uVar2 = (uint)*(byte *)(iVar1 + 0x11);
  }
  param_3[5] = uVar2;
  param_3[4] = (int)(uVar2 * iVar5) >> 0x10;
  if (iVar1 != 0) {
    uVar3 = (uint)*(byte *)(iVar1 + 0x10);
  }
  param_3[10] = param_5 + ((int)(uVar3 * 2 * iVar4) >> 0x10);
  param_3[0xc] = param_5 + ((int)(uVar3 * iVar4) >> 0x10);
  param_3[0xb] = param_5 + ((int)((uVar3 >> 1) * iVar4) >> 0x10);
  return;
}

