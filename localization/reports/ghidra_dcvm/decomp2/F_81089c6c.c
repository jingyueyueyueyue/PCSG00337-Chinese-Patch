
int FUN_81089c6c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar1 = func_0x81005a98(0x20);
  func_0x811183a0(iVar1,*(int *)(param_1 + 4),
                  *(int *)(param_1 + 8) - *(int *)(param_1 + 4) & 0xfffffffc);
  iVar2 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 8);
  if (iVar2 != 0) {
    func_0x81005af0();
  }
  *(int *)(param_1 + 4) = iVar1;
  *(int *)(param_1 + 0xc) = iVar1 + 0x20;
  *(uint *)(param_1 + 8) = iVar1 + (iVar3 - iVar2 & 0xfffffffcU);
  return param_1;
}

