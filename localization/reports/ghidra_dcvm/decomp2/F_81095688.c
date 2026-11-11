
void FUN_81095688(int param_1,undefined *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == (undefined *)0x0) {
    param_2 = &UNK_81138164;
  }
  while( true ) {
    uVar1 = func_0x81094bac(param_1);
    if (uVar1 == 0xffffffff) {
      return;
    }
    iVar3 = *(int *)(param_1 + 0x28);
    iVar2 = iVar3 + 0x54;
    if (0xf < *(uint *)(iVar3 + 0x68)) {
      iVar2 = *(int *)(iVar3 + 0x54);
    }
    iVar2 = func_0x811181a0(iVar2,param_2);
    if (iVar2 == 0) break;
    if (((uVar1 & 0x40000000) != 0) && ((uVar1 & 0x80000000) == 0)) {
      func_0x81094bac(param_1);
    }
  }
  return;
}

