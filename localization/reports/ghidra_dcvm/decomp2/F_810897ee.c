
int FUN_810897ee(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_1[2];
  while (uVar1 = iVar2 + (param_2 + 3U & 0xfffffffc), (uint)param_1[1] < uVar1) {
    (*(code *)param_1[4])();
    iVar2 = param_1[2];
  }
  param_1[2] = uVar1;
  if ((uint)param_1[3] < uVar1) {
    param_1[3] = uVar1;
  }
  return *param_1 + iVar2;
}

