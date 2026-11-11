
int FUN_8109b780(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = iVar2 + 0x54;
    if (0xf < *(uint *)(iVar2 + 0x68)) {
      iVar1 = *(int *)(iVar2 + 0x54);
    }
    iVar1 = func_0x811181a0(param_2,iVar1);
    if (iVar1 == 0) break;
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 8);
    }
  }
  return iVar2;
}

