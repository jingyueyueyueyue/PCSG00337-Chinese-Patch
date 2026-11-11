
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106eb8c(int *param_1,undefined2 param_2,undefined2 param_3)

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
  undefined *puStack_140;
  undefined4 uStack_13c;
  undefined *puStack_138;
  undefined4 uStack_134;
  int *piStack_130;
  int iStack_12c;
  undefined *puStack_128;
  int iStack_124;
  undefined *puStack_120;
  undefined4 uStack_11c;
  undefined *puStack_118;
  undefined4 uStack_114;
  int iStack_110;
  code *pcStack_108;
  undefined4 uStack_104;
  undefined *puStack_100;
  code *pcStack_fc;
  int iStack_f8;
  int iStack_f4;
  int iStack_ec;
  undefined **ppuStack_e8;
  undefined *puStack_e4;
  undefined *puStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  code *pcStack_cc;
  int iStack_c8;
  int iStack_c0;
  undefined **ppuStack_bc;
  undefined *puStack_b8;
  undefined4 uStack_b4;
  undefined *puStack_b0;
  undefined4 uStack_ac;
  undefined2 uStack_a8;
  undefined2 uStack_a6;
  int iStack_a4;
  undefined *puStack_a0;
  int iStack_9c;
  undefined *puStack_98;
  undefined4 uStack_94;
  undefined *puStack_90;
  undefined4 uStack_8c;
  undefined uStack_88;
  undefined uStack_87;
  undefined2 uStack_86;
  undefined2 uStack_84;
  int iStack_80;
  undefined *puStack_78;
  int iStack_74;
  undefined *puStack_70;
  undefined4 uStack_6c;
  undefined *puStack_68;
  undefined4 uStack_64;
  undefined uStack_60;
  undefined uStack_5f;
  undefined2 uStack_5e;
  undefined2 uStack_5c;
  int iStack_58;
  int iStack_50;
  undefined **ppuStack_4c;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined *puStack_40;
  undefined4 uStack_3c;
  undefined2 uStack_38;
  undefined2 uStack_36;
  int iStack_34;
  int iStack_30;
  undefined **ppuStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined *puStack_20;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  undefined2 uStack_16;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  uStack_1c = 0x80000008;
  iVar5 = *param_1;
  puStack_20 = &UNK_81145344;
  pcVar3 = *(code **)(iVar5 + 0x44);
  uStack_18 = param_2;
  uStack_16 = param_3;
  (*pcVar3)(param_1,&puStack_20);
  uStack_36 = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  uVar7 = 0x8106ebd5;
  uVar9 = func_0x811185a0();
  uStack_38 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_28 = &UNK_8111a5b0;
  iStack_34 = _UNK_8111a5b0;
  uStack_3c = 0x80000009;
  iVar6 = *(int *)uVar9;
  uStack_5e = 0x5360;
  puStack_40 = &UNK_81145368;
  pcVar3 = *(code **)(iVar6 + 0x44);
  iStack_30 = iVar5;
  ppuStack_2c = &puStack_20;
  uStack_24 = uVar7;
  (*pcVar3)((int *)uVar9,&puStack_40);
  uStack_5f = SUB41(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_34) {
    return;
  }
  uVar7 = 0x8106ec1f;
  piVar1 = (int *)func_0x811185a0();
  puStack_48 = &UNK_8111a5b0;
  iStack_58 = _UNK_8111a5b0;
  uStack_64 = 0x8000000a;
  iVar5 = *piVar1;
  uStack_86 = 0x538c;
  uStack_5c = SUB42(puStack_40,0);
  puStack_68 = &UNK_8114538c;
  pcVar3 = *(code **)(iVar5 + 0x44);
  uStack_60 = extraout_r1;
  iStack_50 = iVar6;
  ppuStack_4c = &puStack_40;
  uStack_44 = uVar7;
  (*pcVar3)(piVar1,&puStack_68);
  uStack_87 = SUB41(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_58) {
    return;
  }
  uVar7 = 0x8106ec71;
  piVar1 = (int *)func_0x811185a0();
  puStack_70 = &UNK_8111a5b0;
  puStack_78 = &UNK_81145384;
  iStack_80 = _UNK_8111a5b0;
  uStack_8c = 0x8000000b;
  iVar6 = *piVar1;
  uStack_84 = SUB42(puStack_68,0);
  puStack_90 = &UNK_811453b0;
  pcVar3 = *(code **)(iVar6 + 0x44);
  uStack_88 = extraout_r1_00;
  iStack_74 = iVar5;
  uStack_6c = uVar7;
  (*pcVar3)(piVar1,&puStack_90);
  uStack_a6 = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_80) {
    return;
  }
  uVar7 = 0x8106ecc3;
  uVar9 = func_0x811185a0();
  uStack_a8 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_98 = &UNK_8111a5b0;
  puStack_a0 = &UNK_811453a8;
  iStack_a4 = _UNK_8111a5b0;
  uStack_ac = 0x8000000c;
  iVar5 = *(int *)uVar9;
  puStack_b0 = &UNK_811453d4;
  pcVar3 = *(code **)(iVar5 + 0x44);
  iStack_9c = iVar6;
  uStack_94 = uVar7;
  (*pcVar3)((int *)uVar9,&puStack_b0);
  if (_UNK_8111a5b0 == iStack_a4) {
    return;
  }
  uVar7 = 0x8106ed0d;
  uVar8 = func_0x811185a0();
  uStack_d0 = (undefined4)((ulonglong)uVar8 >> 0x20);
  puStack_b8 = &UNK_8111a5b0;
  iStack_c8 = _UNK_8111a5b0;
  uStack_d4 = 0x80000000;
  iVar6 = *(int *)uVar8;
  puStack_d8 = &UNK_81144c84;
  pcVar4 = *(code **)(iVar6 + 0x44);
  pcStack_cc = pcVar3;
  iStack_c0 = iVar5;
  ppuStack_bc = &puStack_b0;
  uStack_b4 = uVar7;
  (*pcVar4)((int *)uVar8,&puStack_d8);
  if (_UNK_8111a5b0 == iStack_c8) {
    return;
  }
  iVar5 = func_0x811185a0();
  puStack_e4 = &UNK_8111a5b0;
  iStack_f4 = _UNK_8111a5b0;
  puStack_100 = &UNK_81145588;
  pcStack_fc = pcVar4;
  iStack_f8 = iVar5;
  iStack_ec = iVar6;
  ppuStack_e8 = &puStack_d8;
  func_0x810809d4(iVar5 + 0xc,&puStack_100);
  piVar1 = *(int **)(iVar5 + 0x24);
  if (piVar1 != (int *)0x0) {
    puStack_100 = &UNK_81145498;
    (**(code **)(*piVar1 + 8))(piVar1,iVar5,pcVar4);
  }
  if (_UNK_8111a5b0 == iStack_f4) {
    return;
  }
  uVar7 = 0x8106edad;
  piVar1 = (int *)func_0x811185a0();
  iStack_110 = _UNK_8111a5b0;
  uStack_114 = 0x80000001;
  puStack_118 = &UNK_81145254;
  pcStack_108 = pcVar4;
  uStack_104 = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_118);
  if (_UNK_8111a5b0 == iStack_110) {
    return;
  }
  uVar7 = 0x8106edeb;
  piVar1 = (int *)func_0x811185a0();
  puStack_120 = &UNK_81145498;
  puStack_128 = &UNK_8111a5b0;
  iStack_12c = _UNK_8111a5b0;
  uStack_13c = 0x80000002;
  puStack_140 = &UNK_81145278;
  iStack_124 = iVar5;
  uStack_11c = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_140);
  piVar2 = (int *)piVar1[0xe];
  if (piVar2 != (int *)0x0) {
    uStack_134 = 0x80000007;
    puStack_138 = &UNK_8114531c;
    puStack_140 = &UNK_81143e70;
    piStack_130 = piVar1;
    (**(code **)(*piVar2 + 0xac))(piVar2,piVar1,&puStack_138);
  }
  if (_UNK_8111a5b0 == iStack_12c) {
    return;
  }
  iVar5 = func_0x811185a0();
  if (*(int **)(iVar5 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar5 + 0x24) + 0xc))();
  }
  return;
}

