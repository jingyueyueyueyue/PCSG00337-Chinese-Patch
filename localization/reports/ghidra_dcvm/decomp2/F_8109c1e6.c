
uint FUN_8109c1e6(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1[2];
  do {
    uVar1 = uVar1 + 1 & 0xff;
    param_1[2] = uVar1;
    if (uVar1 == 0) {
      uVar1 = 1;
      param_1[2] = 1;
    }
    iVar2 = *param_1;
    if (*param_1 == 0) {
      return uVar1;
    }
    do {
      if (*(uint *)(iVar2 + 0x74) == uVar1) break;
      iVar2 = *(int *)(iVar2 + 8);
    } while (iVar2 != 0);
    if (iVar2 == 0) {
      return uVar1;
    }
  } while( true );
}

