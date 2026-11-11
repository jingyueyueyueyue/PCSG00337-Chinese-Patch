
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810794a2(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  uint uStack_d0;
  undefined auStack_cc [8];
  undefined4 uStack_c4;
  int *piStack_c0;
  int *piStack_b8;
  undefined4 *puStack_b4;
  undefined4 uStack_b0;
  undefined *puStack_ac;
  undefined4 *puStack_a8;
  undefined *puStack_a4;
  uint uStack_90;
  int *piStack_8c;
  undefined4 uStack_84;
  undefined4 uStack_80;
  int *piStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 auStack_68 [2];
  undefined4 uStack_60;
  int *piStack_5c;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined *puStack_4c;
  undefined *puStack_48;
  undefined4 uStack_30;
  undefined auStack_2c [4];
  undefined auStack_28 [8];
  undefined4 uStack_20;
  int *piStack_1c;
  
  piStack_1c = _UNK_8111a5b0;
  uStack_20 = 0;
  func_0x81080bb2(auStack_28);
  uStack_30 = 0;
  puVar10 = auStack_28;
  uVar2 = FUN_81078eaa(param_1,&uStack_30,auStack_2c,auStack_28);
  func_0x81005af0(uStack_20);
  if (_UNK_8111a5b0 == piStack_1c) {
    return;
  }
  piVar8 = piStack_1c;
  uVar15 = func_0x811185a0(uVar2);
  uVar4 = (undefined4)((ulonglong)uVar15 >> 0x20);
  puStack_48 = &UNK_8111a5b0;
  uStack_50 = 0;
  piStack_5c = _UNK_8111a5b0;
  uStack_60 = 0;
  uStack_54 = uVar2;
  puStack_4c = auStack_28;
  func_0x81080bb2(auStack_68,puVar10);
  uStack_70 = 0x81191264;
  puVar11 = auStack_68;
  uVar2 = FUN_81078eaa((int)uVar15,uVar4,piVar8,auStack_68);
  func_0x81005af0(uStack_60);
  if (_UNK_8111a5b0 == piStack_5c) {
    return;
  }
  uVar14 = 0x81079551;
  piVar9 = piStack_5c;
  uVar16 = func_0x811185a0(uVar2);
  uVar1 = uStack_70;
  puVar13 = (undefined4 *)((ulonglong)uVar16 >> 0x20);
  piStack_8c = _UNK_8111a5b0;
  *puVar13 = 0;
  *piVar9 = 0;
  uStack_84 = uVar2;
  uStack_80 = uVar4;
  piStack_7c = piVar8;
  uStack_78 = (int)uVar15;
  uStack_74 = uVar14;
  iVar3 = FUN_81078eaa((int)uVar16,puVar13,&uStack_90);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    puVar12 = (undefined4 *)*puVar13;
    puVar13 = (undefined4 *)puVar12[0xe];
    if (puVar13 == (undefined4 *)0x0) {
      uStack_90 = 0xffffffff;
    }
    puVar5 = (undefined4 *)0x0;
    puVar11 = puVar12;
    if ((-1 < (int)uStack_90) &&
       (puVar5 = (undefined4 *)0x0, puVar11 = puVar5, uStack_90 < *(uint *)(puVar12[0xd] + 8))) {
      puVar5 = puVar13 + uStack_90 * 3;
      puVar11 = puVar5;
    }
    uVar2 = 1;
    *piVar9 = (int)puVar5;
  }
  if (_UNK_8111a5b0 == piStack_8c) {
    return;
  }
  piVar8 = piStack_8c;
  uVar15 = func_0x811185a0(uVar2);
  piVar6 = (int *)((ulonglong)uVar15 >> 0x20);
  puStack_a4 = &UNK_8111a5b0;
  puStack_ac = &UNK_8111a5b0;
  uStack_b0 = 0;
  piStack_c0 = _UNK_8111a5b0;
  uStack_c4 = 0;
  piStack_b8 = piVar9;
  puStack_b4 = puVar13;
  puStack_a8 = auStack_68;
  func_0x81080bb2(auStack_cc,puVar11);
  *piVar6 = 0;
  *piVar8 = 0;
  iVar3 = FUN_81078eaa((int)uVar15,piVar6,&uStack_d0,auStack_cc,uVar1);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    iVar3 = *(int *)(*piVar6 + 0x38);
    if (iVar3 == 0) {
      uStack_d0 = 0xffffffff;
    }
    iVar7 = 0;
    if ((-1 < (int)uStack_d0) && (iVar7 = 0, uStack_d0 < *(uint *)(*(int *)(*piVar6 + 0x34) + 8))) {
      iVar7 = iVar3 + uStack_d0 * 0xc;
    }
    *piVar8 = iVar7;
    uVar2 = 1;
  }
  func_0x81005af0(uStack_c4);
  if (_UNK_8111a5b0 != piStack_c0) {
    func_0x811185a0(uVar2);
    uRam81191264 = 0xffffffff;
    return;
  }
  return;
}

