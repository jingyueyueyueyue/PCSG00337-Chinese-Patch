
undefined4 * FUN_8109aeec(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &UNK_81147248;
  FUN_8109aea2(param_1);
  if (0xf < (uint)param_1[0x1a]) {
    func_0x81005af0(param_1[0x15]);
  }
  param_1[0x19] = 0;
  param_1[0x1a] = 0xf;
  *(undefined *)(param_1 + 0x15) = 0;
  if (param_1[3] != 0) {
    if (param_1 + 3 == (undefined4 *)param_1[5]) {
      func_0x8110ca84();
    }
    else {
      iVar1 = param_1[4];
      ((undefined4 *)param_1[5])[1] = iVar1;
      *(undefined4 *)(iVar1 + 8) = param_1[5];
    }
  }
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}

