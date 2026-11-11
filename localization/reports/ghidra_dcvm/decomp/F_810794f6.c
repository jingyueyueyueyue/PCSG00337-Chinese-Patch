
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810794f6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  uint uStack_98;
  undefined auStack_94 [8];
  undefined4 uStack_8c;
  int *piStack_88;
  int *piStack_80;
  undefined4 *puStack_7c;
  undefined4 uStack_78;
  undefined *puStack_74;
  undefined4 *puStack_70;
  undefined *puStack_6c;
  uint uStack_58;
  int *piStack_54;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 auStack_30 [2];
  undefined4 uStack_28;
  int *piStack_24;
  
  piStack_24 = _UNK_8111a5b0;
  uStack_28 = 0;
  func_0x81080bb2(auStack_30,param_4);
  uStack_38 = param_5;
  puVar9 = auStack_30;
  uVar2 = FUN_81078eaa(param_1,param_2,param_3,auStack_30);
  func_0x81005af0(uStack_28);
  if (_UNK_8111a5b0 == piStack_24) {
    return;
  }
  uVar12 = 0x81079551;
  piVar7 = piStack_24;
  uVar13 = func_0x811185a0(uVar2);
  uVar1 = uStack_38;
  puVar11 = (undefined4 *)((ulonglong)uVar13 >> 0x20);
  piStack_54 = _UNK_8111a5b0;
  *puVar11 = 0;
  *piVar7 = 0;
  uStack_4c = uVar2;
  uStack_48 = param_2;
  uStack_44 = param_3;
  uStack_40 = param_1;
  uStack_3c = uVar12;
  iVar3 = FUN_81078eaa((int)uVar13,puVar11,&uStack_58);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    puVar10 = (undefined4 *)*puVar11;
    puVar11 = (undefined4 *)puVar10[0xe];
    if (puVar11 == (undefined4 *)0x0) {
      uStack_58 = 0xffffffff;
    }
    puVar4 = (undefined4 *)0x0;
    puVar9 = puVar10;
    if ((-1 < (int)uStack_58) &&
       (puVar4 = (undefined4 *)0x0, puVar9 = puVar4, uStack_58 < *(uint *)(puVar10[0xd] + 8))) {
      puVar4 = puVar11 + uStack_58 * 3;
      puVar9 = puVar4;
    }
    uVar2 = 1;
    *piVar7 = (int)puVar4;
  }
  if (_UNK_8111a5b0 != piStack_54) {
    piVar8 = piStack_54;
    uVar13 = func_0x811185a0(uVar2);
    piVar5 = (int *)((ulonglong)uVar13 >> 0x20);
    puStack_6c = &UNK_8111a5b0;
    puStack_74 = &UNK_8111a5b0;
    uStack_78 = 0;
    piStack_88 = _UNK_8111a5b0;
    uStack_8c = 0;
    piStack_80 = piVar7;
    puStack_7c = puVar11;
    puStack_70 = auStack_30;
    func_0x81080bb2(auStack_94,puVar9);
    *piVar5 = 0;
    *piVar8 = 0;
    iVar3 = FUN_81078eaa((int)uVar13,piVar5,&uStack_98,auStack_94,uVar1);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      iVar3 = *(int *)(*piVar5 + 0x38);
      if (iVar3 == 0) {
        uStack_98 = 0xffffffff;
      }
      iVar6 = 0;
      if ((-1 < (int)uStack_98) && (iVar6 = 0, uStack_98 < *(uint *)(*(int *)(*piVar5 + 0x34) + 8)))
      {
        iVar6 = iVar3 + uStack_98 * 0xc;
      }
      *piVar8 = iVar6;
      uVar2 = 1;
    }
    func_0x81005af0(uStack_8c);
    if (_UNK_8111a5b0 != piStack_88) {
      func_0x811185a0(uVar2);
      uRam81191264 = 0xffffffff;
      return;
    }
    return;
  }
  return;
}

