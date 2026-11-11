
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81079468(undefined4 param_1,undefined4 param_2)

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
  uint uStack_f0;
  undefined auStack_ec [8];
  undefined4 uStack_e4;
  int *piStack_e0;
  int *piStack_d8;
  undefined4 *puStack_d4;
  undefined4 uStack_d0;
  undefined *puStack_cc;
  undefined4 *puStack_c8;
  undefined *puStack_c4;
  uint uStack_b0;
  int *piStack_ac;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  int *piStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 auStack_88 [2];
  undefined4 uStack_80;
  int *piStack_7c;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined *puStack_6c;
  undefined *puStack_68;
  undefined4 uStack_50;
  undefined auStack_4c [4];
  undefined auStack_48 [8];
  undefined4 uStack_40;
  int *piStack_3c;
  undefined *puStack_34;
  undefined4 uStack_18;
  undefined auStack_14 [4];
  int *piStack_10;
  
  piStack_10 = _UNK_8111a5b0;
  uStack_18 = 0;
  FUN_81078eaa(param_1,&uStack_18,auStack_14,param_2);
  if (_UNK_8111a5b0 == piStack_10) {
    return;
  }
  uVar2 = func_0x811185a0();
  puStack_34 = &UNK_8111a5b0;
  piStack_3c = _UNK_8111a5b0;
  uStack_40 = 0;
  FUN_81080bb2(auStack_48);
  uStack_50 = 0;
  puVar10 = auStack_48;
  uVar2 = FUN_81078eaa(uVar2,&uStack_50,auStack_4c,auStack_48);
  func_0x81005af0(uStack_40);
  if (_UNK_8111a5b0 == piStack_3c) {
    return;
  }
  piVar8 = piStack_3c;
  uVar15 = func_0x811185a0(uVar2);
  uVar4 = (undefined4)((ulonglong)uVar15 >> 0x20);
  puStack_68 = &UNK_8111a5b0;
  uStack_70 = 0;
  piStack_7c = _UNK_8111a5b0;
  uStack_80 = 0;
  uStack_74 = uVar2;
  puStack_6c = auStack_48;
  FUN_81080bb2(auStack_88,puVar10);
  uStack_90 = 0x81191264;
  puVar11 = auStack_88;
  uVar2 = FUN_81078eaa((int)uVar15,uVar4,piVar8,auStack_88);
  func_0x81005af0(uStack_80);
  if (_UNK_8111a5b0 == piStack_7c) {
    return;
  }
  uVar14 = 0x81079551;
  piVar9 = piStack_7c;
  uVar16 = func_0x811185a0(uVar2);
  uVar1 = uStack_90;
  puVar13 = (undefined4 *)((ulonglong)uVar16 >> 0x20);
  piStack_ac = _UNK_8111a5b0;
  *puVar13 = 0;
  *piVar9 = 0;
  uStack_a4 = uVar2;
  uStack_a0 = uVar4;
  piStack_9c = piVar8;
  uStack_98 = (int)uVar15;
  uStack_94 = uVar14;
  iVar3 = FUN_81078eaa((int)uVar16,puVar13,&uStack_b0);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    puVar12 = (undefined4 *)*puVar13;
    puVar13 = (undefined4 *)puVar12[0xe];
    if (puVar13 == (undefined4 *)0x0) {
      uStack_b0 = 0xffffffff;
    }
    puVar5 = (undefined4 *)0x0;
    puVar11 = puVar12;
    if ((-1 < (int)uStack_b0) &&
       (puVar5 = (undefined4 *)0x0, puVar11 = puVar5, uStack_b0 < *(uint *)(puVar12[0xd] + 8))) {
      puVar5 = puVar13 + uStack_b0 * 3;
      puVar11 = puVar5;
    }
    uVar2 = 1;
    *piVar9 = (int)puVar5;
  }
  if (_UNK_8111a5b0 != piStack_ac) {
    piVar8 = piStack_ac;
    uVar15 = func_0x811185a0(uVar2);
    piVar6 = (int *)((ulonglong)uVar15 >> 0x20);
    puStack_c4 = &UNK_8111a5b0;
    puStack_cc = &UNK_8111a5b0;
    uStack_d0 = 0;
    piStack_e0 = _UNK_8111a5b0;
    uStack_e4 = 0;
    piStack_d8 = piVar9;
    puStack_d4 = puVar13;
    puStack_c8 = auStack_88;
    FUN_81080bb2(auStack_ec,puVar11);
    *piVar6 = 0;
    *piVar8 = 0;
    iVar3 = FUN_81078eaa((int)uVar15,piVar6,&uStack_f0,auStack_ec,uVar1);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      iVar3 = *(int *)(*piVar6 + 0x38);
      if (iVar3 == 0) {
        uStack_f0 = 0xffffffff;
      }
      iVar7 = 0;
      if ((-1 < (int)uStack_f0) && (iVar7 = 0, uStack_f0 < *(uint *)(*(int *)(*piVar6 + 0x34) + 8)))
      {
        iVar7 = iVar3 + uStack_f0 * 0xc;
      }
      *piVar8 = iVar7;
      uVar2 = 1;
    }
    func_0x81005af0(uStack_e4);
    if (_UNK_8111a5b0 != piStack_e0) {
      func_0x811185a0(uVar2);
      uRam81191264 = 0xffffffff;
      return;
    }
    return;
  }
  return;
}

