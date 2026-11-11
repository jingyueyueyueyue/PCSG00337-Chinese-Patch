
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106eb4a(int *param_1,undefined param_2)

{
  int *piVar1;
  int *piVar2;
  undefined extraout_r1;
  undefined extraout_r1_00;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined6 uVar9;
  undefined *puStack_158;
  undefined4 uStack_154;
  undefined *puStack_150;
  undefined4 uStack_14c;
  int *piStack_148;
  int iStack_144;
  undefined *puStack_140;
  int iStack_13c;
  undefined *puStack_138;
  undefined4 uStack_134;
  undefined *puStack_130;
  undefined4 uStack_12c;
  int iStack_128;
  code *pcStack_120;
  undefined4 uStack_11c;
  undefined *puStack_118;
  code *pcStack_114;
  int iStack_110;
  int iStack_10c;
  int iStack_104;
  undefined **ppuStack_100;
  undefined *puStack_fc;
  undefined *puStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  code *pcStack_e4;
  int iStack_e0;
  int iStack_d8;
  undefined **ppuStack_d4;
  undefined *puStack_d0;
  undefined4 uStack_cc;
  undefined *puStack_c8;
  undefined4 uStack_c4;
  undefined2 uStack_c0;
  undefined2 uStack_be;
  int iStack_bc;
  undefined *puStack_b8;
  int iStack_b4;
  undefined *puStack_b0;
  undefined4 uStack_ac;
  undefined *puStack_a8;
  undefined4 uStack_a4;
  undefined uStack_a0;
  undefined uStack_9f;
  undefined2 uStack_9e;
  undefined2 uStack_9c;
  int iStack_98;
  undefined *puStack_90;
  int iStack_8c;
  undefined *puStack_88;
  undefined4 uStack_84;
  undefined *puStack_80;
  undefined4 uStack_7c;
  undefined uStack_78;
  undefined uStack_77;
  undefined2 uStack_76;
  undefined2 uStack_74;
  int iStack_70;
  int iStack_68;
  undefined **ppuStack_64;
  undefined *puStack_60;
  undefined4 uStack_5c;
  undefined *puStack_58;
  undefined4 uStack_54;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  int iStack_4c;
  int iStack_48;
  undefined **ppuStack_44;
  undefined *puStack_40;
  undefined4 uStack_3c;
  undefined *puStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  int iStack_2c;
  undefined *puStack_28;
  undefined *puStack_18;
  undefined4 uStack_14;
  undefined uStack_10;
  int iStack_c;
  
  iStack_c = _UNK_8111a5b0;
  uStack_14 = 0x80000006;
  pcVar3 = *(code **)(*param_1 + 0x44);
  puStack_18 = &UNK_811452fc;
  uStack_10 = param_2;
  (*pcVar3)(param_1,&puStack_18);
  uStack_2e = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_c) {
    return;
  }
  uVar9 = func_0x811185a0();
  uStack_30 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_28 = &UNK_8111a5b0;
  iStack_2c = _UNK_8111a5b0;
  uStack_34 = 0x80000008;
  iVar5 = *(int *)uVar9;
  puStack_38 = &UNK_81145344;
  pcVar3 = *(code **)(iVar5 + 0x44);
  (*pcVar3)((int *)uVar9,&puStack_38);
  uStack_4e = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_2c) {
    return;
  }
  uVar7 = 0x8106ebd5;
  uVar9 = func_0x811185a0();
  uStack_50 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_40 = &UNK_8111a5b0;
  iStack_4c = _UNK_8111a5b0;
  uStack_54 = 0x80000009;
  iVar6 = *(int *)uVar9;
  uStack_76 = 0x5360;
  puStack_58 = &UNK_81145368;
  pcVar3 = *(code **)(iVar6 + 0x44);
  iStack_48 = iVar5;
  ppuStack_44 = &puStack_38;
  uStack_3c = uVar7;
  (*pcVar3)((int *)uVar9,&puStack_58);
  uStack_77 = SUB41(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_4c) {
    return;
  }
  uVar7 = 0x8106ec1f;
  piVar1 = (int *)func_0x811185a0();
  puStack_60 = &UNK_8111a5b0;
  iStack_70 = _UNK_8111a5b0;
  uStack_7c = 0x8000000a;
  iVar5 = *piVar1;
  uStack_9e = 0x538c;
  uStack_74 = SUB42(puStack_58,0);
  puStack_80 = &UNK_8114538c;
  pcVar3 = *(code **)(iVar5 + 0x44);
  uStack_78 = extraout_r1;
  iStack_68 = iVar6;
  ppuStack_64 = &puStack_58;
  uStack_5c = uVar7;
  (*pcVar3)(piVar1,&puStack_80);
  uStack_9f = SUB41(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_70) {
    return;
  }
  uVar7 = 0x8106ec71;
  piVar1 = (int *)func_0x811185a0();
  puStack_88 = &UNK_8111a5b0;
  puStack_90 = &UNK_81145384;
  iStack_98 = _UNK_8111a5b0;
  uStack_a4 = 0x8000000b;
  iVar6 = *piVar1;
  uStack_9c = SUB42(puStack_80,0);
  puStack_a8 = &UNK_811453b0;
  pcVar3 = *(code **)(iVar6 + 0x44);
  uStack_a0 = extraout_r1_00;
  iStack_8c = iVar5;
  uStack_84 = uVar7;
  (*pcVar3)(piVar1,&puStack_a8);
  uStack_be = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_98) {
    return;
  }
  uVar7 = 0x8106ecc3;
  uVar9 = func_0x811185a0();
  uStack_c0 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_b0 = &UNK_8111a5b0;
  puStack_b8 = &UNK_811453a8;
  iStack_bc = _UNK_8111a5b0;
  uStack_c4 = 0x8000000c;
  iVar5 = *(int *)uVar9;
  puStack_c8 = &UNK_811453d4;
  pcVar3 = *(code **)(iVar5 + 0x44);
  iStack_b4 = iVar6;
  uStack_ac = uVar7;
  (*pcVar3)((int *)uVar9,&puStack_c8);
  if (_UNK_8111a5b0 == iStack_bc) {
    return;
  }
  uVar7 = 0x8106ed0d;
  uVar8 = func_0x811185a0();
  uStack_e8 = (undefined4)((ulonglong)uVar8 >> 0x20);
  puStack_d0 = &UNK_8111a5b0;
  iStack_e0 = _UNK_8111a5b0;
  uStack_ec = 0x80000000;
  iVar6 = *(int *)uVar8;
  puStack_f0 = &UNK_81144c84;
  pcVar4 = *(code **)(iVar6 + 0x44);
  pcStack_e4 = pcVar3;
  iStack_d8 = iVar5;
  ppuStack_d4 = &puStack_c8;
  uStack_cc = uVar7;
  (*pcVar4)((int *)uVar8,&puStack_f0);
  if (_UNK_8111a5b0 == iStack_e0) {
    return;
  }
  iVar5 = func_0x811185a0();
  puStack_fc = &UNK_8111a5b0;
  iStack_10c = _UNK_8111a5b0;
  puStack_118 = &UNK_81145588;
  pcStack_114 = pcVar4;
  iStack_110 = iVar5;
  iStack_104 = iVar6;
  ppuStack_100 = &puStack_f0;
  func_0x810809d4(iVar5 + 0xc,&puStack_118);
  piVar1 = *(int **)(iVar5 + 0x24);
  if (piVar1 != (int *)0x0) {
    puStack_118 = &UNK_81145498;
    (**(code **)(*piVar1 + 8))(piVar1,iVar5,pcVar4);
  }
  if (_UNK_8111a5b0 == iStack_10c) {
    return;
  }
  uVar7 = 0x8106edad;
  piVar1 = (int *)func_0x811185a0();
  iStack_128 = _UNK_8111a5b0;
  uStack_12c = 0x80000001;
  puStack_130 = &UNK_81145254;
  pcStack_120 = pcVar4;
  uStack_11c = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_130);
  if (_UNK_8111a5b0 == iStack_128) {
    return;
  }
  uVar7 = 0x8106edeb;
  piVar1 = (int *)func_0x811185a0();
  puStack_138 = &UNK_81145498;
  puStack_140 = &UNK_8111a5b0;
  iStack_144 = _UNK_8111a5b0;
  uStack_154 = 0x80000002;
  puStack_158 = &UNK_81145278;
  iStack_13c = iVar5;
  uStack_134 = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_158);
  piVar2 = (int *)piVar1[0xe];
  if (piVar2 != (int *)0x0) {
    uStack_14c = 0x80000007;
    puStack_150 = &UNK_8114531c;
    puStack_158 = &UNK_81143e70;
    piStack_148 = piVar1;
    (**(code **)(*piVar2 + 0xac))(piVar2,piVar1,&puStack_150);
  }
  if (_UNK_8111a5b0 == iStack_144) {
    return;
  }
  iVar5 = func_0x811185a0();
  if (*(int **)(iVar5 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar5 + 0x24) + 0xc))();
  }
  return;
}

