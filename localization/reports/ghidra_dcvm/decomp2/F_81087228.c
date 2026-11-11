
int FUN_81087228(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0) {
    FUN_81086e3e(0,0,0x3f800000,0x3f800000,param_1);
    iVar1 = *(int *)(param_1 + 0x10);
  }
  return iVar1;
}

