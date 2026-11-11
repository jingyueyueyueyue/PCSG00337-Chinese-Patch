
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8109bab4(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uStack_10;
  int iStack_c;
  
  iStack_c = _UNK_8111a5b0;
  FUN_810698ea(param_2,&uStack_10,4);
  if (_UNK_8111a5b0 == iStack_c) {
    return;
  }
  puVar1 = (undefined4 *)func_0x811185a0(uStack_10);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0xff;
  return;
}

