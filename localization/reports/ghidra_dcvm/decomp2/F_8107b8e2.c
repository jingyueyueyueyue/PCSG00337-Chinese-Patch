
int FUN_8107b8e2(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if (((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 8) == 0)) ||
     (*(int *)(param_1 + 0xc) == 0)) {
    return 0;
  }
  if (*(uint *)(*(int *)(param_1 + 8) + 8) <= param_2) {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0xc) + 8;
  if (param_2 == 0) {
    return iVar2;
  }
  do {
    iVar1 = func_0x81118330(iVar2);
    param_2 = param_2 - 1;
    iVar2 = iVar1 + iVar2 + 1;
  } while (param_2 != 0);
  return iVar2;
}

