
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_81078aec(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 *puStack_38;
  undefined4 *puStack_30;
  undefined4 *puStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 *puStack_18;
  
  puStack_18 = _UNK_8111a5b0;
  *param_1 = &UNK_81145a44;
  func_0x81005b02(param_1[0x12]);
  *param_1 = &UNK_81145a28;
  uStack_20 = 0;
  uStack_1c = 0;
  puVar3 = param_1 + 3;
  if (puVar3 != &uStack_20) {
    FUN_8107db94(puVar3);
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
  FUN_8107db94(puVar3);
  func_0x81005af0(param_1);
  if (_UNK_8111a5b0 == puStack_18) {
    return _UNK_8111a5b0;
  }
  uVar4 = 0x81078b7d;
  puVar1 = (undefined4 *)func_0x811185a0();
  puStack_28 = &UNK_8111a5b0;
  puStack_38 = _UNK_8111a5b0;
  *puVar1 = &UNK_81145a44;
  puStack_30 = param_1;
  puStack_2c = puVar3;
  uStack_24 = uVar4;
  func_0x81005b02(puVar1[0x12]);
  *puVar1 = &UNK_81145a28;
  uStack_40 = 0;
  uStack_3c = 0;
  puVar3 = puVar1 + 3;
  if (puVar3 != &uStack_40) {
    FUN_8107db94(puVar3);
    puVar1[3] = uStack_40;
    puVar1[4] = uStack_3c;
  }
  uStack_3c = 0;
  uStack_40 = 0;
  FUN_8107db94(&uStack_40);
  puVar1[8] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  func_0x8110384c(puVar1 + 5);
  FUN_8107db94(puVar3);
  if (_UNK_8111a5b0 == puStack_38) {
    return puVar1;
  }
  iVar2 = func_0x811185a0(puVar1);
  return *(undefined4 **)(iVar2 + 0x48);
}

