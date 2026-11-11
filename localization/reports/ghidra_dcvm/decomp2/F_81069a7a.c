
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81069a7a(undefined4 param_1,undefined *param_2,undefined4 param_3,undefined param_4)

{
  undefined8 uVar1;
  undefined *puStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  *param_2 = param_4;
  uStack_18 = 3;
  puStack_20 = param_2;
  uStack_1c = param_3;
  func_0x81101fd0(param_1,&puStack_20);
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  uVar1 = func_0x811185a0();
  *(int *)((int)uVar1 + 0x10) = (int)((ulonglong)uVar1 >> 0x20);
  *(undefined4 *)((int)uVar1 + 0x14) = param_3;
  return;
}

