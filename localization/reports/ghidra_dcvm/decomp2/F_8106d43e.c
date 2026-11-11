
void FUN_8106d43e(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  while (iVar1 != 0) {
    FUN_8106cfa4(iVar1,0);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 8);
    }
  }
  return;
}

