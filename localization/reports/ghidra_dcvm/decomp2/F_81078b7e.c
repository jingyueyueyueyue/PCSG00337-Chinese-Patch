
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_81078b7e(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  *param_1 = &UNK_81145a44;
  func_0x81005b02(param_1[0x12]);
  *param_1 = &UNK_81145a28;
  uStack_20 = 0;
  uStack_1c = 0;
  puVar2 = param_1 + 3;
  if (puVar2 != &uStack_20) {
    FUN_8107db94(puVar2);
    param_1[3] = uStack_20;
    param_1[4] = uStack_1c;
  }
  uStack_1c = 0;
  uStack_20 = 0;
  FUN_8107db94(&uStack_20);
  param_1[8] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  func_0x8110384c(param_1 + 5);
  FUN_8107db94(puVar2);
  if (_UNK_8111a5b0 == iStack_18) {
    return param_1;
  }
  iVar1 = func_0x811185a0(param_1);
  return *(undefined4 **)(iVar1 + 0x48);
}

