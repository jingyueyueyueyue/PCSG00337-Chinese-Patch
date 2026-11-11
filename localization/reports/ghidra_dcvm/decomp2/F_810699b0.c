
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810699b0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 extraout_s0;
  undefined8 uVar4;
  undefined *puStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  int iStack_8c;
  undefined4 uStack_84;
  undefined *puStack_80;
  undefined4 uStack_7c;
  undefined4 *puStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  int iStack_6c;
  undefined *puStack_64;
  undefined *puStack_60;
  undefined4 uStack_5c;
  undefined4 *puStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 *puStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined4 *puStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  *param_2 = param_4;
  uStack_18 = 0;
  puStack_20 = param_2;
  uStack_1c = param_3;
  func_0x81101fd0(param_1,&puStack_20);
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  uVar2 = 0x810699e1;
  uVar4 = func_0x811185a0();
  puStack_40 = (undefined4 *)((ulonglong)uVar4 >> 0x20);
  puStack_28 = &UNK_8111a5b0;
  uStack_2c = 0;
  iStack_34 = _UNK_8111a5b0;
  *puStack_40 = param_4;
  uStack_38 = 1;
  uStack_3c = param_3;
  uStack_24 = uVar2;
  func_0x81101fd0((int)uVar4,&puStack_40);
  if (_UNK_8111a5b0 == iStack_34) {
    return;
  }
  uVar3 = 0x81069a13;
  uVar4 = func_0x811185a0();
  puStack_58 = (undefined4 *)((ulonglong)uVar4 >> 0x20);
  uStack_48 = 1;
  iStack_4c = _UNK_8111a5b0;
  *puStack_58 = extraout_s0;
  uVar2 = 2;
  uStack_50 = 2;
  uStack_54 = param_3;
  uStack_44 = uVar3;
  func_0x81101fd0((int)uVar4,&puStack_58);
  if (_UNK_8111a5b0 == iStack_4c) {
    return;
  }
  uVar3 = 0x81069a47;
  uVar4 = func_0x811185a0();
  puStack_78 = (undefined4 *)((ulonglong)uVar4 >> 0x20);
  puStack_60 = &UNK_8111a5b0;
  puStack_64 = &UNK_8111a5b0;
  iStack_6c = _UNK_8111a5b0;
  *puStack_78 = uVar2;
  uStack_70 = 4;
  uStack_74 = param_3;
  uStack_5c = uVar3;
  func_0x81101fd0((int)uVar4,&puStack_78);
  uVar1 = (undefined)uVar2;
  if (_UNK_8111a5b0 == iStack_6c) {
    return;
  }
  uVar2 = 0x81069a79;
  uVar4 = func_0x811185a0();
  puStack_98 = (undefined *)((ulonglong)uVar4 >> 0x20);
  puStack_80 = &UNK_8111a5b0;
  uStack_84 = 4;
  iStack_8c = _UNK_8111a5b0;
  *puStack_98 = uVar1;
  uStack_90 = 3;
  uStack_94 = param_3;
  uStack_7c = uVar2;
  func_0x81101fd0((int)uVar4,&puStack_98);
  if (_UNK_8111a5b0 == iStack_8c) {
    return;
  }
  uVar4 = func_0x811185a0();
  *(int *)((int)uVar4 + 0x10) = (int)((ulonglong)uVar4 >> 0x20);
  *(undefined4 *)((int)uVar4 + 0x14) = param_3;
  return;
}

