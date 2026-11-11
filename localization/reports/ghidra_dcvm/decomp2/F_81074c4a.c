
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_81074c4a(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  
  iStack_10 = _UNK_8111a5b0;
  *param_1 = 0;
  param_1[1] = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 != &uStack_18) {
    FUN_8107db94(param_1);
    *param_1 = uStack_18;
    param_1[1] = uStack_14;
  }
  uStack_14 = 0;
  uStack_18 = 0;
  FUN_8107db94(&uStack_18);
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (_UNK_8111a5b0 == iStack_10) {
    return param_1;
  }
  puVar1 = (undefined4 *)func_0x811185a0(param_1);
  FUN_8107db94();
  return puVar1;
}

