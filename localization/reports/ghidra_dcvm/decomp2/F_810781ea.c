
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_810781ea(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  longlong lVar8;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 *puStack_70;
  undefined4 *puStack_68;
  undefined4 *puStack_64;
  undefined *puStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 *puStack_50;
  undefined4 *puStack_48;
  undefined4 *puStack_44;
  undefined *puStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 *puStack_30;
  int iStack_28;
  undefined *puStack_24;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 *puStack_10;
  
  puStack_10 = _UNK_8111a5b0;
  uStack_18 = 0;
  uStack_14 = 0;
  if ((undefined4 *)(param_1 + 0xc) != &uStack_18) {
    FUN_8107db94();
    *(undefined4 *)(param_1 + 0xc) = uStack_18;
    *(undefined4 *)(param_1 + 0x10) = uStack_14;
  }
  uStack_14 = 0;
  uStack_18 = 0;
  FUN_8107db94(&uStack_18);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  if (_UNK_8111a5b0 == puStack_10) {
    return _UNK_8111a5b0;
  }
  puVar1 = (undefined4 *)func_0x811185a0();
  puStack_24 = &UNK_8111a5b0;
  puStack_30 = _UNK_8111a5b0;
  *puVar1 = &UNK_81145a28;
  uStack_38 = 0;
  uStack_34 = 0;
  puVar5 = puVar1 + 3;
  iStack_28 = param_1;
  if (puVar5 != &uStack_38) {
    FUN_8107db94(puVar5);
    puVar1[3] = uStack_38;
    puVar1[4] = uStack_34;
  }
  uStack_34 = 0;
  uStack_38 = 0;
  FUN_8107db94(&uStack_38);
  puVar1[8] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  func_0x8110384c(puVar1 + 5);
  FUN_8107db94(puVar5);
  if (_UNK_8111a5b0 != puStack_30) {
    uVar7 = 0x810782bf;
    puVar2 = (undefined4 *)func_0x811185a0(puVar1);
    puStack_40 = &UNK_8111a5b0;
    puStack_50 = _UNK_8111a5b0;
    *puVar2 = &UNK_81145a28;
    uStack_58 = 0;
    uStack_54 = 0;
    puVar6 = puVar2 + 3;
    puStack_48 = puVar1;
    puStack_44 = puVar5;
    uStack_3c = uVar7;
    if (puVar6 != &uStack_58) {
      FUN_8107db94(puVar6);
      puVar2[3] = uStack_58;
      puVar2[4] = uStack_54;
    }
    uStack_54 = 0;
    uStack_58 = 0;
    FUN_8107db94(&uStack_58);
    puVar2[8] = 0;
    puVar2[0xb] = 0;
    puVar2[0xc] = 0;
    puVar2[0xd] = 0;
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0x10] = 0;
    func_0x8110384c(puVar2 + 5);
    FUN_8107db94(puVar6);
    func_0x81005af0(puVar2);
    if (_UNK_8111a5b0 == puStack_50) {
      return _UNK_8111a5b0;
    }
    uVar7 = 0x8107833d;
    puVar1 = (undefined4 *)func_0x811185a0();
    puStack_60 = &UNK_8111a5b0;
    puStack_70 = _UNK_8111a5b0;
    *puVar1 = &UNK_81145a28;
    uStack_78 = 0;
    uStack_74 = 0;
    puVar5 = puVar1 + 3;
    puStack_68 = puVar2;
    puStack_64 = puVar6;
    uStack_5c = uVar7;
    if (puVar5 != &uStack_78) {
      FUN_8107db94(puVar5);
      puVar1[3] = uStack_78;
      puVar1[4] = uStack_74;
    }
    uStack_74 = 0;
    uStack_78 = 0;
    FUN_8107db94(&uStack_78);
    puVar1[8] = 0;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
    puVar1[0xf] = 0;
    puVar1[0x10] = 0;
    func_0x8110384c(puVar1 + 5);
    FUN_8107db94(puVar5);
    if (_UNK_8111a5b0 != puStack_70) {
      lVar8 = func_0x811185a0(puVar1);
      uVar3 = (uint)((ulonglong)lVar8 >> 0x20);
      iVar4 = *(int *)((int)lVar8 + 0x30);
      if (iVar4 == 0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)0x0;
        if ((-1 < lVar8) && (uVar3 < *(uint *)(*(int *)((int)lVar8 + 0x34) + 8))) {
          puVar1 = (undefined4 *)(iVar4 + uVar3 * 4);
        }
      }
      return puVar1;
    }
    return puVar1;
  }
  return puVar1;
}

