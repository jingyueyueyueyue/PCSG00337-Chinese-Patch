
void FUN_8107b6e4(undefined4 *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_2 + 4) == 0) || (iVar2 = *(int *)(param_2 + 8), iVar2 == 0)) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else if (param_3 < *(uint *)(iVar2 + 8)) {
    iVar1 = *(int *)(param_2 + 0x10);
    iVar2 = *(int *)(iVar2 + param_3 * 4 + 0xc);
    *param_1 = 0;
    param_1[1] = iVar2 + iVar1;
  }
  else {
    *param_1 = 0;
    param_1[1] = 0;
  }
  return;
}

