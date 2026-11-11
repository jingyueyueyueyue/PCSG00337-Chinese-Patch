
undefined4 * FUN_8106926e(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[4];
  *param_1 = &UNK_81144b08;
  if (iVar1 != 0) {
    func_0x8108769e(iVar1);
    func_0x81005af0(iVar1);
  }
  param_1[4] = 0;
  func_0x81064852(param_1);
  return param_1;
}

