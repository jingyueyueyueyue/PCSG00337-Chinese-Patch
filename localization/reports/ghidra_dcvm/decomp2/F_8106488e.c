
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106488e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 extraout_r1;
  undefined **ppuVar1;
  undefined4 uVar2;
  undefined *puStack_40;
  undefined *puStack_3c;
  int iStack_38;
  undefined4 uStack_30;
  undefined **ppuStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined *puStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  ppuVar1 = &puStack_20;
  iStack_18 = _UNK_8111a5b0;
  puStack_20 = &UNK_8113d1c0;
  uStack_1c = param_5;
  func_0x81043428(param_4,param_2,param_3,&puStack_20);
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar2 = 0x810648c9;
  func_0x811185a0();
  puStack_28 = &UNK_8111a5b0;
  uStack_30 = param_5;
  iStack_38 = _UNK_8111a5b0;
  puStack_40 = &UNK_8113d1d4;
  puStack_3c = puStack_20;
  ppuStack_2c = &puStack_20;
  uStack_24 = uVar2;
  func_0x81043428(ppuVar1,extraout_r1,param_3,&puStack_40);
  if (_UNK_8111a5b0 == iStack_38) {
    return;
  }
  func_0x811185a0();
  return;
}

