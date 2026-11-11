
undefined4 * FUN_81073e68(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x3c];
  *param_1 = &UNK_8114583c;
  if (iVar1 != 0) {
    FUN_8107db94(iVar1);
    func_0x81005af0(iVar1);
  }
  param_1[0x3c] = 0;
  func_0x81074cf2(param_1);
  return param_1;
}

