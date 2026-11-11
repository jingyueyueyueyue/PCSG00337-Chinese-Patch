
undefined4 * FUN_81086d44(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  *param_1 = &UNK_8114646c;
  iVar2 = *(int *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 8) = 0;
  if (iVar2 != 0) {
    FUN_8108a29e(iVar2);
    func_0x81005af0();
    iVar1 = param_1[1];
  }
  iVar2 = *(int *)(iVar1 + 0xc);
  *(undefined4 *)(iVar1 + 0xc) = 0;
  if (iVar2 != 0) {
    func_0x8108769e(iVar2);
    func_0x81005af0();
    iVar1 = param_1[1];
  }
  if (iVar1 != 0) {
    FUN_81086c10();
    func_0x81005af0();
  }
  param_1[1] = 0;
  func_0x810769a6(param_1);
  return param_1;
}

