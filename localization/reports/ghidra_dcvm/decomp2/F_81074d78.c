
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_81074d78(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 *puStack_30;
  undefined4 *puStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  uStack_20 = 0;
  uStack_1c = param_2;
  FUN_81074d2e(param_1,&uStack_20);
  FUN_8107db94(&uStack_20);
  if (_UNK_8111a5b0 == iStack_18) {
    return param_1;
  }
  uVar2 = 0x81074db9;
  uVar3 = func_0x811185a0(param_1);
  uStack_3c = (undefined4)((ulonglong)uVar3 >> 0x20);
  puVar1 = (undefined4 *)uVar3;
  puStack_28 = &UNK_8111a5b0;
  iStack_38 = _UNK_8111a5b0;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  uStack_40 = 0;
  puStack_30 = param_1;
  puStack_2c = &uStack_20;
  uStack_24 = uVar2;
  FUN_81074d2e(puVar1,&uStack_40);
  FUN_8107db94(&uStack_40);
  if (_UNK_8111a5b0 == iStack_38) {
    return puVar1;
  }
  puVar1 = (undefined4 *)func_0x811185a0(puVar1);
  puVar1[2] = 0;
  puVar1[3] = 0;
  FUN_8107db94();
  FUN_8107db94(puVar1);
  return puVar1;
}

