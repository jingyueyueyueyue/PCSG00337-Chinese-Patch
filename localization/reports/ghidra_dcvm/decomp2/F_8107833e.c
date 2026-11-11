
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_8107833e(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  *param_1 = &UNK_81145a28;
  uStack_20 = 0;
  uStack_1c = 0;
  puVar1 = param_1 + 3;
  if (puVar1 != &uStack_20) {
    FUN_8107db94(puVar1);
    param_1[3] = uStack_20;
    param_1[4] = uStack_1c;
  }
  uStack_1c = 0;
  uStack_20 = 0;
  FUN_8107db94(&uStack_20);
  param_1[8] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  func_0x8110384c(param_1 + 5);
  FUN_8107db94(puVar1);
  if (_UNK_8111a5b0 != iStack_18) {
    lVar4 = func_0x811185a0(param_1);
    uVar2 = (uint)((ulonglong)lVar4 >> 0x20);
    iVar3 = *(int *)((int)lVar4 + 0x30);
    if (iVar3 == 0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = (undefined4 *)0x0;
      if ((-1 < lVar4) && (uVar2 < *(uint *)(*(int *)((int)lVar4 + 0x34) + 8))) {
        puVar1 = (undefined4 *)(iVar3 + uVar2 * 4);
      }
    }
    return puVar1;
  }
  return param_1;
}

