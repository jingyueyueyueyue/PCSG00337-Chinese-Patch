
undefined4 * FUN_81084804(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &UNK_81146358;
  FUN_81076290(param_1);
  if (param_1[0x11] != 0) {
    func_0x81005af0();
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0;
  }
  FUN_8107db94(param_1 + 2);
  iVar1 = param_1[1];
  if (iVar1 != 0) {
    FUN_8107db94(iVar1 + 8);
    FUN_8107db94(iVar1);
    func_0x81005af0(iVar1);
  }
  param_1[1] = 0;
  return param_1;
}

