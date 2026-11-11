
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_81074dba(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  puVar1 = (undefined4 *)func_0x811185a0(param_1);
  puVar1[2] = 0;
  puVar1[3] = 0;
  FUN_8107db94();
  FUN_8107db94(puVar1);
  return puVar1;
}

