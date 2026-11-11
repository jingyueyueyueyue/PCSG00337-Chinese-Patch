
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_810782c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  longlong lVar7;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 *puStack_38;
  undefined4 *puStack_30;
  undefined4 *puStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 *puStack_18;
  
  puStack_18 = _UNK_8111a5b0;
  *param_1 = &UNK_81145a28;
  uStack_20 = 0;
  uStack_1c = 0;
  puVar2 = param_1 + 3;
  if (puVar2 != &uStack_20) {
    FUN_8107db94(puVar2);
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
  FUN_8107db94(puVar2);
  func_0x81005af0(param_1);
  if (_UNK_8111a5b0 == puStack_18) {
    return _UNK_8111a5b0;
  }
  uVar6 = 0x8107833d;
  puVar1 = (undefined4 *)func_0x811185a0();
  puStack_28 = &UNK_8111a5b0;
  puStack_38 = _UNK_8111a5b0;
  *puVar1 = &UNK_81145a28;
  uStack_40 = 0;
  uStack_3c = 0;
  puVar5 = puVar1 + 3;
  puStack_30 = param_1;
  puStack_2c = puVar2;
  uStack_24 = uVar6;
  if (puVar5 != &uStack_40) {
    FUN_8107db94(puVar5);
    puVar1[3] = uStack_40;
    puVar1[4] = uStack_3c;
  }
  uStack_3c = 0;
  uStack_40 = 0;
  FUN_8107db94(&uStack_40);
  puVar1[8] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  func_0x8110384c(puVar1 + 5);
  FUN_8107db94(puVar5);
  if (_UNK_8111a5b0 != puStack_38) {
    lVar7 = func_0x811185a0(puVar1);
    uVar3 = (uint)((ulonglong)lVar7 >> 0x20);
    iVar4 = *(int *)((int)lVar7 + 0x30);
    if (iVar4 == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)0x0;
      if ((-1 < lVar7) && (uVar3 < *(uint *)(*(int *)((int)lVar7 + 0x34) + 8))) {
        puVar2 = (undefined4 *)(iVar4 + uVar3 * 4);
      }
    }
    return puVar2;
  }
  return puVar1;
}

