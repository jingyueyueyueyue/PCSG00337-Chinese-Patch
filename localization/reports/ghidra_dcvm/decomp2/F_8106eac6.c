
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106eac6(int *param_1,undefined param_2)

{
  int *piVar1;
  int *piVar2;
  undefined extraout_r1;
  undefined extraout_r1_00;
  undefined extraout_r1_01;
  undefined extraout_r1_02;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined6 uVar9;
  undefined *puStack_188;
  undefined4 uStack_184;
  undefined *puStack_180;
  undefined4 uStack_17c;
  int *piStack_178;
  int iStack_174;
  undefined *puStack_170;
  int iStack_16c;
  undefined *puStack_168;
  undefined4 uStack_164;
  undefined *puStack_160;
  undefined4 uStack_15c;
  int iStack_158;
  code *pcStack_150;
  undefined4 uStack_14c;
  undefined *puStack_148;
  code *pcStack_144;
  int iStack_140;
  int iStack_13c;
  int iStack_134;
  undefined **ppuStack_130;
  undefined *puStack_12c;
  undefined *puStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  code *pcStack_114;
  int iStack_110;
  int iStack_108;
  undefined **ppuStack_104;
  undefined *puStack_100;
  undefined4 uStack_fc;
  undefined *puStack_f8;
  undefined4 uStack_f4;
  undefined2 uStack_f0;
  undefined2 uStack_ee;
  int iStack_ec;
  undefined *puStack_e8;
  int iStack_e4;
  undefined *puStack_e0;
  undefined4 uStack_dc;
  undefined *puStack_d8;
  undefined4 uStack_d4;
  undefined uStack_d0;
  undefined uStack_cf;
  undefined2 uStack_ce;
  undefined2 uStack_cc;
  int iStack_c8;
  undefined *puStack_c0;
  int iStack_bc;
  undefined *puStack_b8;
  undefined4 uStack_b4;
  undefined *puStack_b0;
  undefined4 uStack_ac;
  undefined uStack_a8;
  undefined uStack_a7;
  undefined2 uStack_a6;
  undefined2 uStack_a4;
  int iStack_a0;
  int iStack_98;
  undefined **ppuStack_94;
  undefined *puStack_90;
  undefined4 uStack_8c;
  undefined *puStack_88;
  undefined4 uStack_84;
  undefined2 uStack_80;
  undefined2 uStack_7e;
  int iStack_7c;
  int iStack_78;
  undefined **ppuStack_74;
  undefined *puStack_70;
  undefined4 uStack_6c;
  undefined *puStack_68;
  undefined4 uStack_64;
  undefined2 uStack_60;
  undefined2 uStack_5e;
  int iStack_5c;
  undefined *puStack_58;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined uStack_40;
  int iStack_3c;
  undefined *puStack_38;
  undefined4 uStack_34;
  undefined *puStack_30;
  undefined4 uStack_2c;
  undefined uStack_28;
  int iStack_24;
  undefined *puStack_20;
  undefined4 uStack_1c;
  undefined *puStack_18;
  undefined4 uStack_14;
  undefined uStack_10;
  int iStack_c;
  
  iStack_c = _UNK_8111a5b0;
  uStack_14 = 0x80000003;
  puStack_18 = &UNK_8114529c;
  uStack_10 = param_2;
  (**(code **)(*param_1 + 0x44))(param_1,&puStack_18);
  if (_UNK_8111a5b0 == iStack_c) {
    return;
  }
  uVar7 = 0x8106eb07;
  piVar1 = (int *)func_0x811185a0();
  puStack_20 = &UNK_8111a5b0;
  iStack_24 = _UNK_8111a5b0;
  uStack_2c = 0x80000005;
  puStack_30 = &UNK_811452dc;
  uStack_28 = extraout_r1;
  uStack_1c = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_30);
  if (_UNK_8111a5b0 == iStack_24) {
    return;
  }
  uVar7 = 0x8106eb49;
  piVar1 = (int *)func_0x811185a0();
  puStack_38 = &UNK_8111a5b0;
  iStack_3c = _UNK_8111a5b0;
  uStack_44 = 0x80000006;
  pcVar3 = *(code **)(*piVar1 + 0x44);
  puStack_48 = &UNK_811452fc;
  uStack_40 = extraout_r1_00;
  uStack_34 = uVar7;
  (*pcVar3)(piVar1,&puStack_48);
  uStack_5e = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_3c) {
    return;
  }
  uVar9 = func_0x811185a0();
  uStack_60 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_58 = &UNK_8111a5b0;
  iStack_5c = _UNK_8111a5b0;
  uStack_64 = 0x80000008;
  iVar5 = *(int *)uVar9;
  puStack_68 = &UNK_81145344;
  pcVar3 = *(code **)(iVar5 + 0x44);
  (*pcVar3)((int *)uVar9,&puStack_68);
  uStack_7e = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_5c) {
    return;
  }
  uVar7 = 0x8106ebd5;
  uVar9 = func_0x811185a0();
  uStack_80 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_70 = &UNK_8111a5b0;
  iStack_7c = _UNK_8111a5b0;
  uStack_84 = 0x80000009;
  iVar6 = *(int *)uVar9;
  uStack_a6 = 0x5360;
  puStack_88 = &UNK_81145368;
  pcVar3 = *(code **)(iVar6 + 0x44);
  iStack_78 = iVar5;
  ppuStack_74 = &puStack_68;
  uStack_6c = uVar7;
  (*pcVar3)((int *)uVar9,&puStack_88);
  uStack_a7 = SUB41(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_7c) {
    return;
  }
  uVar7 = 0x8106ec1f;
  piVar1 = (int *)func_0x811185a0();
  puStack_90 = &UNK_8111a5b0;
  iStack_a0 = _UNK_8111a5b0;
  uStack_ac = 0x8000000a;
  iVar5 = *piVar1;
  uStack_ce = 0x538c;
  uStack_a4 = SUB42(puStack_88,0);
  puStack_b0 = &UNK_8114538c;
  pcVar3 = *(code **)(iVar5 + 0x44);
  uStack_a8 = extraout_r1_01;
  iStack_98 = iVar6;
  ppuStack_94 = &puStack_88;
  uStack_8c = uVar7;
  (*pcVar3)(piVar1,&puStack_b0);
  uStack_cf = SUB41(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_a0) {
    return;
  }
  uVar7 = 0x8106ec71;
  piVar1 = (int *)func_0x811185a0();
  puStack_b8 = &UNK_8111a5b0;
  puStack_c0 = &UNK_81145384;
  iStack_c8 = _UNK_8111a5b0;
  uStack_d4 = 0x8000000b;
  iVar6 = *piVar1;
  uStack_cc = SUB42(puStack_b0,0);
  puStack_d8 = &UNK_811453b0;
  pcVar3 = *(code **)(iVar6 + 0x44);
  uStack_d0 = extraout_r1_02;
  iStack_bc = iVar5;
  uStack_b4 = uVar7;
  (*pcVar3)(piVar1,&puStack_d8);
  uStack_ee = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_c8) {
    return;
  }
  uVar7 = 0x8106ecc3;
  uVar9 = func_0x811185a0();
  uStack_f0 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_e0 = &UNK_8111a5b0;
  puStack_e8 = &UNK_811453a8;
  iStack_ec = _UNK_8111a5b0;
  uStack_f4 = 0x8000000c;
  iVar5 = *(int *)uVar9;
  puStack_f8 = &UNK_811453d4;
  pcVar3 = *(code **)(iVar5 + 0x44);
  iStack_e4 = iVar6;
  uStack_dc = uVar7;
  (*pcVar3)((int *)uVar9,&puStack_f8);
  if (_UNK_8111a5b0 == iStack_ec) {
    return;
  }
  uVar7 = 0x8106ed0d;
  uVar8 = func_0x811185a0();
  uStack_118 = (undefined4)((ulonglong)uVar8 >> 0x20);
  puStack_100 = &UNK_8111a5b0;
  iStack_110 = _UNK_8111a5b0;
  uStack_11c = 0x80000000;
  iVar6 = *(int *)uVar8;
  puStack_120 = &UNK_81144c84;
  pcVar4 = *(code **)(iVar6 + 0x44);
  pcStack_114 = pcVar3;
  iStack_108 = iVar5;
  ppuStack_104 = &puStack_f8;
  uStack_fc = uVar7;
  (*pcVar4)((int *)uVar8,&puStack_120);
  if (_UNK_8111a5b0 == iStack_110) {
    return;
  }
  iVar5 = func_0x811185a0();
  puStack_12c = &UNK_8111a5b0;
  iStack_13c = _UNK_8111a5b0;
  puStack_148 = &UNK_81145588;
  pcStack_144 = pcVar4;
  iStack_140 = iVar5;
  iStack_134 = iVar6;
  ppuStack_130 = &puStack_120;
  func_0x810809d4(iVar5 + 0xc,&puStack_148);
  piVar1 = *(int **)(iVar5 + 0x24);
  if (piVar1 != (int *)0x0) {
    puStack_148 = &UNK_81145498;
    (**(code **)(*piVar1 + 8))(piVar1,iVar5,pcVar4);
  }
  if (_UNK_8111a5b0 == iStack_13c) {
    return;
  }
  uVar7 = 0x8106edad;
  piVar1 = (int *)func_0x811185a0();
  iStack_158 = _UNK_8111a5b0;
  uStack_15c = 0x80000001;
  puStack_160 = &UNK_81145254;
  pcStack_150 = pcVar4;
  uStack_14c = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_160);
  if (_UNK_8111a5b0 == iStack_158) {
    return;
  }
  uVar7 = 0x8106edeb;
  piVar1 = (int *)func_0x811185a0();
  puStack_168 = &UNK_81145498;
  puStack_170 = &UNK_8111a5b0;
  iStack_174 = _UNK_8111a5b0;
  uStack_184 = 0x80000002;
  puStack_188 = &UNK_81145278;
  iStack_16c = iVar5;
  uStack_164 = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_188);
  piVar2 = (int *)piVar1[0xe];
  if (piVar2 != (int *)0x0) {
    uStack_17c = 0x80000007;
    puStack_180 = &UNK_8114531c;
    puStack_188 = &UNK_81143e70;
    piStack_178 = piVar1;
    (**(code **)(*piVar2 + 0xac))(piVar2,piVar1,&puStack_180);
  }
  if (_UNK_8111a5b0 == iStack_174) {
    return;
  }
  iVar5 = func_0x811185a0();
  if (*(int **)(iVar5 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar5 + 0x24) + 0xc))();
  }
  return;
}

