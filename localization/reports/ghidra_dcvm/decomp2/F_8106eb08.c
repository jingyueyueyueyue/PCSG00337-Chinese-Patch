
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106eb08(int *param_1,undefined param_2)

{
  int *piVar1;
  int *piVar2;
  undefined extraout_r1;
  undefined extraout_r1_00;
  undefined extraout_r1_01;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined6 uVar9;
  undefined *puStack_170;
  undefined4 uStack_16c;
  undefined *puStack_168;
  undefined4 uStack_164;
  int *piStack_160;
  int iStack_15c;
  undefined *puStack_158;
  int iStack_154;
  undefined *puStack_150;
  undefined4 uStack_14c;
  undefined *puStack_148;
  undefined4 uStack_144;
  int iStack_140;
  code *pcStack_138;
  undefined4 uStack_134;
  undefined *puStack_130;
  code *pcStack_12c;
  int iStack_128;
  int iStack_124;
  int iStack_11c;
  undefined **ppuStack_118;
  undefined *puStack_114;
  undefined *puStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  code *pcStack_fc;
  int iStack_f8;
  int iStack_f0;
  undefined **ppuStack_ec;
  undefined *puStack_e8;
  undefined4 uStack_e4;
  undefined *puStack_e0;
  undefined4 uStack_dc;
  undefined2 uStack_d8;
  undefined2 uStack_d6;
  int iStack_d4;
  undefined *puStack_d0;
  int iStack_cc;
  undefined *puStack_c8;
  undefined4 uStack_c4;
  undefined *puStack_c0;
  undefined4 uStack_bc;
  undefined uStack_b8;
  undefined uStack_b7;
  undefined2 uStack_b6;
  undefined2 uStack_b4;
  int iStack_b0;
  undefined *puStack_a8;
  int iStack_a4;
  undefined *puStack_a0;
  undefined4 uStack_9c;
  undefined *puStack_98;
  undefined4 uStack_94;
  undefined uStack_90;
  undefined uStack_8f;
  undefined2 uStack_8e;
  undefined2 uStack_8c;
  int iStack_88;
  int iStack_80;
  undefined **ppuStack_7c;
  undefined *puStack_78;
  undefined4 uStack_74;
  undefined *puStack_70;
  undefined4 uStack_6c;
  undefined2 uStack_68;
  undefined2 uStack_66;
  int iStack_64;
  int iStack_60;
  undefined **ppuStack_5c;
  undefined *puStack_58;
  undefined4 uStack_54;
  undefined *puStack_50;
  undefined4 uStack_4c;
  undefined2 uStack_48;
  undefined2 uStack_46;
  int iStack_44;
  undefined *puStack_40;
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
  uStack_14 = 0x80000005;
  puStack_18 = &UNK_811452dc;
  uStack_10 = param_2;
  (**(code **)(*param_1 + 0x44))(param_1,&puStack_18);
  if (_UNK_8111a5b0 == iStack_c) {
    return;
  }
  uVar7 = 0x8106eb49;
  piVar1 = (int *)func_0x811185a0();
  puStack_20 = &UNK_8111a5b0;
  iStack_24 = _UNK_8111a5b0;
  uStack_2c = 0x80000006;
  pcVar3 = *(code **)(*piVar1 + 0x44);
  puStack_30 = &UNK_811452fc;
  uStack_28 = extraout_r1;
  uStack_1c = uVar7;
  (*pcVar3)(piVar1,&puStack_30);
  uStack_46 = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_24) {
    return;
  }
  uVar9 = func_0x811185a0();
  uStack_48 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_40 = &UNK_8111a5b0;
  iStack_44 = _UNK_8111a5b0;
  uStack_4c = 0x80000008;
  iVar5 = *(int *)uVar9;
  puStack_50 = &UNK_81145344;
  pcVar3 = *(code **)(iVar5 + 0x44);
  (*pcVar3)((int *)uVar9,&puStack_50);
  uStack_66 = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_44) {
    return;
  }
  uVar7 = 0x8106ebd5;
  uVar9 = func_0x811185a0();
  uStack_68 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_58 = &UNK_8111a5b0;
  iStack_64 = _UNK_8111a5b0;
  uStack_6c = 0x80000009;
  iVar6 = *(int *)uVar9;
  uStack_8e = 0x5360;
  puStack_70 = &UNK_81145368;
  pcVar3 = *(code **)(iVar6 + 0x44);
  iStack_60 = iVar5;
  ppuStack_5c = &puStack_50;
  uStack_54 = uVar7;
  (*pcVar3)((int *)uVar9,&puStack_70);
  uStack_8f = SUB41(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_64) {
    return;
  }
  uVar7 = 0x8106ec1f;
  piVar1 = (int *)func_0x811185a0();
  puStack_78 = &UNK_8111a5b0;
  iStack_88 = _UNK_8111a5b0;
  uStack_94 = 0x8000000a;
  iVar5 = *piVar1;
  uStack_b6 = 0x538c;
  uStack_8c = SUB42(puStack_70,0);
  puStack_98 = &UNK_8114538c;
  pcVar3 = *(code **)(iVar5 + 0x44);
  uStack_90 = extraout_r1_00;
  iStack_80 = iVar6;
  ppuStack_7c = &puStack_70;
  uStack_74 = uVar7;
  (*pcVar3)(piVar1,&puStack_98);
  uStack_b7 = SUB41(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_88) {
    return;
  }
  uVar7 = 0x8106ec71;
  piVar1 = (int *)func_0x811185a0();
  puStack_a0 = &UNK_8111a5b0;
  puStack_a8 = &UNK_81145384;
  iStack_b0 = _UNK_8111a5b0;
  uStack_bc = 0x8000000b;
  iVar6 = *piVar1;
  uStack_b4 = SUB42(puStack_98,0);
  puStack_c0 = &UNK_811453b0;
  pcVar3 = *(code **)(iVar6 + 0x44);
  uStack_b8 = extraout_r1_01;
  iStack_a4 = iVar5;
  uStack_9c = uVar7;
  (*pcVar3)(piVar1,&puStack_c0);
  uStack_d6 = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_b0) {
    return;
  }
  uVar7 = 0x8106ecc3;
  uVar9 = func_0x811185a0();
  uStack_d8 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_c8 = &UNK_8111a5b0;
  puStack_d0 = &UNK_811453a8;
  iStack_d4 = _UNK_8111a5b0;
  uStack_dc = 0x8000000c;
  iVar5 = *(int *)uVar9;
  puStack_e0 = &UNK_811453d4;
  pcVar3 = *(code **)(iVar5 + 0x44);
  iStack_cc = iVar6;
  uStack_c4 = uVar7;
  (*pcVar3)((int *)uVar9,&puStack_e0);
  if (_UNK_8111a5b0 == iStack_d4) {
    return;
  }
  uVar7 = 0x8106ed0d;
  uVar8 = func_0x811185a0();
  uStack_100 = (undefined4)((ulonglong)uVar8 >> 0x20);
  puStack_e8 = &UNK_8111a5b0;
  iStack_f8 = _UNK_8111a5b0;
  uStack_104 = 0x80000000;
  iVar6 = *(int *)uVar8;
  puStack_108 = &UNK_81144c84;
  pcVar4 = *(code **)(iVar6 + 0x44);
  pcStack_fc = pcVar3;
  iStack_f0 = iVar5;
  ppuStack_ec = &puStack_e0;
  uStack_e4 = uVar7;
  (*pcVar4)((int *)uVar8,&puStack_108);
  if (_UNK_8111a5b0 == iStack_f8) {
    return;
  }
  iVar5 = func_0x811185a0();
  puStack_114 = &UNK_8111a5b0;
  iStack_124 = _UNK_8111a5b0;
  puStack_130 = &UNK_81145588;
  pcStack_12c = pcVar4;
  iStack_128 = iVar5;
  iStack_11c = iVar6;
  ppuStack_118 = &puStack_108;
  func_0x810809d4(iVar5 + 0xc,&puStack_130);
  piVar1 = *(int **)(iVar5 + 0x24);
  if (piVar1 != (int *)0x0) {
    puStack_130 = &UNK_81145498;
    (**(code **)(*piVar1 + 8))(piVar1,iVar5,pcVar4);
  }
  if (_UNK_8111a5b0 == iStack_124) {
    return;
  }
  uVar7 = 0x8106edad;
  piVar1 = (int *)func_0x811185a0();
  iStack_140 = _UNK_8111a5b0;
  uStack_144 = 0x80000001;
  puStack_148 = &UNK_81145254;
  pcStack_138 = pcVar4;
  uStack_134 = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_148);
  if (_UNK_8111a5b0 == iStack_140) {
    return;
  }
  uVar7 = 0x8106edeb;
  piVar1 = (int *)func_0x811185a0();
  puStack_150 = &UNK_81145498;
  puStack_158 = &UNK_8111a5b0;
  iStack_15c = _UNK_8111a5b0;
  uStack_16c = 0x80000002;
  puStack_170 = &UNK_81145278;
  iStack_154 = iVar5;
  uStack_14c = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_170);
  piVar2 = (int *)piVar1[0xe];
  if (piVar2 != (int *)0x0) {
    uStack_164 = 0x80000007;
    puStack_168 = &UNK_8114531c;
    puStack_170 = &UNK_81143e70;
    piStack_160 = piVar1;
    (**(code **)(*piVar2 + 0xac))(piVar2,piVar1,&puStack_168);
  }
  if (_UNK_8111a5b0 == iStack_15c) {
    return;
  }
  iVar5 = func_0x811185a0();
  if (*(int **)(iVar5 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar5 + 0x24) + 0xc))();
  }
  return;
}

