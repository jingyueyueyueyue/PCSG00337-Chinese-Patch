
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81069a14(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined *puStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  undefined4 uStack_44;
  undefined *puStack_40;
  undefined4 uStack_3c;
  undefined4 *puStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined *puStack_24;
  undefined4 *puStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  
  iStack_c = _UNK_8111a5b0;
  *param_3 = param_1;
  uVar2 = 2;
  uStack_10 = 2;
  puStack_18 = param_3;
  uStack_14 = param_4;
  func_0x81101fd0(param_2,&puStack_18);
  if (_UNK_8111a5b0 == iStack_c) {
    return;
  }
  uVar3 = func_0x811185a0();
  puStack_38 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
  puStack_24 = &UNK_8111a5b0;
  iStack_2c = _UNK_8111a5b0;
  *puStack_38 = uVar2;
  uStack_30 = 4;
  uStack_34 = param_4;
  func_0x81101fd0((int)uVar3,&puStack_38);
  uVar1 = (undefined)uVar2;
  if (_UNK_8111a5b0 == iStack_2c) {
    return;
  }
  uVar2 = 0x81069a79;
  uVar3 = func_0x811185a0();
  puStack_58 = (undefined *)((ulonglong)uVar3 >> 0x20);
  puStack_40 = &UNK_8111a5b0;
  uStack_44 = 4;
  iStack_4c = _UNK_8111a5b0;
  *puStack_58 = uVar1;
  uStack_50 = 3;
  uStack_54 = param_4;
  uStack_3c = uVar2;
  func_0x81101fd0((int)uVar3,&puStack_58);
  if (_UNK_8111a5b0 == iStack_4c) {
    return;
  }
  uVar3 = func_0x811185a0();
  *(int *)((int)uVar3 + 0x10) = (int)((ulonglong)uVar3 >> 0x20);
  *(undefined4 *)((int)uVar3 + 0x14) = param_4;
  return;
}

