
void FUN_8107e8b6(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (((-1 < iVar1) && (iVar1 < 8)) && (param_1[iVar1 * 6 + 4] != 0)) {
    (**(code **)(*param_1 + 0x10))(param_1,param_1 + iVar1 * 6 + 1);
  }
  return;
}

