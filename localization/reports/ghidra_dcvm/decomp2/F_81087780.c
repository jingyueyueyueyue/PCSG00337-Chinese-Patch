
uint FUN_81087780(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = func_0x81116ae0();
  if (uVar1 == 0) {
    iVar2 = func_0x811167b0(param_1);
    func_0x81116c20(param_1);
    uVar1 = func_0x81088d98();
    uVar1 = (uVar1 & 0xf) * 4 * (iVar2 + 7U & 0xfffffff8) >> 3;
  }
  return uVar1;
}

