
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8109ba26(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_40;
  int iStack_3c;
  undefined *puStack_38;
  undefined4 uStack_34;
  int iStack_30;
  int iStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined *puStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  
  iStack_c = _UNK_8111a5b0;
  uStack_10 = param_3;
  func_0x8106986a(param_2,&uStack_10,4);
  if (_UNK_8111a5b0 == iStack_c) {
    return;
  }
  uVar3 = 0x8109ba55;
  func_0x811185a0();
  puStack_18 = &UNK_8111a5b0;
  iStack_1c = _UNK_8111a5b0;
  uStack_14 = uVar3;
  FUN_810698ea(extraout_r1,&uStack_20,4);
  if (_UNK_8111a5b0 == iStack_1c) {
    return;
  }
  uVar3 = 0x8109ba83;
  iVar2 = iStack_1c;
  func_0x811185a0(uStack_20);
  puStack_28 = &UNK_8111a5b0;
  iStack_2c = _UNK_8111a5b0;
  iStack_30 = iVar2;
  uStack_24 = uVar3;
  func_0x8106986a(extraout_r1_00,&iStack_30,4);
  if (_UNK_8111a5b0 == iStack_2c) {
    return;
  }
  uVar3 = 0x8109bab3;
  func_0x811185a0();
  puStack_38 = &UNK_8111a5b0;
  iStack_3c = _UNK_8111a5b0;
  uStack_34 = uVar3;
  FUN_810698ea(extraout_r1_01,&uStack_40,4);
  if (_UNK_8111a5b0 == iStack_3c) {
    return;
  }
  puVar1 = (undefined4 *)func_0x811185a0(uStack_40);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0xff;
  return;
}

