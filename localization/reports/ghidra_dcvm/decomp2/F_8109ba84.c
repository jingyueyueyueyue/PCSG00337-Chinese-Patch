
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8109ba84(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 extraout_r1;
  undefined4 uVar2;
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
  uVar2 = 0x8109bab3;
  func_0x811185a0();
  puStack_18 = &UNK_8111a5b0;
  iStack_1c = _UNK_8111a5b0;
  uStack_14 = uVar2;
  FUN_810698ea(extraout_r1,&uStack_20,4);
  if (_UNK_8111a5b0 == iStack_1c) {
    return;
  }
  puVar1 = (undefined4 *)func_0x811185a0(uStack_20);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0xff;
  return;
}

