
undefined4 * FUN_8108e9b0(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  puRam811ae7cc = param_1;
  *param_1 = &UNK_81146700;
  *(undefined *)(param_1 + 1) = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  iVar1 = func_0x81005a98(0x28);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = func_0x81094362(iVar1);
  }
  iVar1 = param_1[5];
  param_1[5] = uVar2;
  if (iVar1 != 0) {
    FUN_81094398(iVar1);
    func_0x81005af0();
    uVar2 = param_1[5];
  }
  func_0x810943e8(uVar2,&UNK_81137c28,2,0,0);
  return param_1;
}

