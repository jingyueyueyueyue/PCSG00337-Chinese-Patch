
int FUN_8107e14c(byte *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  iVar1 = 0;
  uVar2 = 0;
  pbVar4 = param_1;
  if (param_1 != param_1 + param_2) {
    do {
      pbVar3 = pbVar4 + 1;
      iVar1 = iVar1 + (uint)*pbVar4 + uVar2;
      uVar2 = uVar2 + 1 & 0xff;
      pbVar4 = pbVar3;
    } while (pbVar3 != param_1 + param_2);
  }
  return iVar1;
}

