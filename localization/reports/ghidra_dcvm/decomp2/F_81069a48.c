
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81069a48(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined *puStack_40;
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
  uStack_18 = 4;
  puStack_20 = param_2;
  uStack_1c = param_3;
  func_0x81101fd0(param_1,&puStack_20);
  uVar1 = (undefined)param_4;
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  uVar2 = 0x81069a79;
  uVar3 = func_0x811185a0();
  puStack_40 = (undefined *)((ulonglong)uVar3 >> 0x20);
  puStack_28 = &UNK_8111a5b0;
  uStack_2c = 4;
  iStack_34 = _UNK_8111a5b0;
  *puStack_40 = uVar1;
  uStack_38 = 3;
  uStack_3c = param_3;
  uStack_24 = uVar2;
  func_0x81101fd0((int)uVar3,&puStack_40);
  if (_UNK_8111a5b0 == iStack_34) {
    return;
  }
  uVar3 = func_0x811185a0();
  *(int *)((int)uVar3 + 0x10) = (int)((ulonglong)uVar3 >> 0x20);
  *(undefined4 *)((int)uVar3 + 0x14) = param_3;
  return;
}

