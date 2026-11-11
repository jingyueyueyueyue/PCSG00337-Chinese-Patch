
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106ebd6(int *param_1,undefined2 param_2,undefined2 param_3)

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
  undefined *puStack_120;
  undefined4 uStack_11c;
  undefined *puStack_118;
  undefined4 uStack_114;
  int *piStack_110;
  int iStack_10c;
  undefined *puStack_108;
  int iStack_104;
  undefined *puStack_100;
  undefined4 uStack_fc;
  undefined *puStack_f8;
  undefined4 uStack_f4;
  int iStack_f0;
  code *pcStack_e8;
  undefined4 uStack_e4;
  undefined *puStack_e0;
  code *pcStack_dc;
  int iStack_d8;
  int iStack_d4;
  int iStack_cc;
  undefined **ppuStack_c8;
  undefined *puStack_c4;
  undefined *puStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  code *pcStack_ac;
  int iStack_a8;
  int iStack_a0;
  undefined **ppuStack_9c;
  undefined *puStack_98;
  undefined4 uStack_94;
  undefined *puStack_90;
  undefined4 uStack_8c;
  undefined2 uStack_88;
  undefined2 uStack_86;
  int iStack_84;
  undefined *puStack_80;
  int iStack_7c;
  undefined *puStack_78;
  undefined4 uStack_74;
  undefined *puStack_70;
  undefined4 uStack_6c;
  undefined uStack_68;
  undefined uStack_67;
  undefined2 uStack_66;
  undefined2 uStack_64;
  int iStack_60;
  undefined *puStack_58;
  int iStack_54;
  undefined *puStack_50;
  undefined4 uStack_4c;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined uStack_40;
  undefined uStack_3f;
  undefined2 uStack_3e;
  undefined2 uStack_3c;
  int iStack_38;
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
  uStack_1c = 0x80000009;
  iVar5 = *param_1;
  uStack_3e = 0x5360;
  puStack_20 = &UNK_81145368;
  pcVar3 = *(code **)(iVar5 + 0x44);
  uStack_18 = param_2;
  uStack_16 = param_3;
  (*pcVar3)(param_1,&puStack_20);
  uStack_3f = SUB41(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  uVar7 = 0x8106ec1f;
  piVar1 = (int *)func_0x811185a0();
  puStack_28 = &UNK_8111a5b0;
  iStack_38 = _UNK_8111a5b0;
  uStack_44 = 0x8000000a;
  iVar6 = *piVar1;
  uStack_66 = 0x538c;
  uStack_3c = SUB42(puStack_20,0);
  puStack_48 = &UNK_8114538c;
  pcVar3 = *(code **)(iVar6 + 0x44);
  uStack_40 = extraout_r1;
  iStack_30 = iVar5;
  ppuStack_2c = &puStack_20;
  uStack_24 = uVar7;
  (*pcVar3)(piVar1,&puStack_48);
  uStack_67 = SUB41(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_38) {
    return;
  }
  uVar7 = 0x8106ec71;
  piVar1 = (int *)func_0x811185a0();
  puStack_50 = &UNK_8111a5b0;
  puStack_58 = &UNK_81145384;
  iStack_60 = _UNK_8111a5b0;
  uStack_6c = 0x8000000b;
  iVar5 = *piVar1;
  uStack_64 = SUB42(puStack_48,0);
  puStack_70 = &UNK_811453b0;
  pcVar3 = *(code **)(iVar5 + 0x44);
  uStack_68 = extraout_r1_00;
  iStack_54 = iVar6;
  uStack_4c = uVar7;
  (*pcVar3)(piVar1,&puStack_70);
  uStack_86 = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_60) {
    return;
  }
  uVar7 = 0x8106ecc3;
  uVar9 = func_0x811185a0();
  uStack_88 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_78 = &UNK_8111a5b0;
  puStack_80 = &UNK_811453a8;
  iStack_84 = _UNK_8111a5b0;
  uStack_8c = 0x8000000c;
  iVar6 = *(int *)uVar9;
  puStack_90 = &UNK_811453d4;
  pcVar3 = *(code **)(iVar6 + 0x44);
  iStack_7c = iVar5;
  uStack_74 = uVar7;
  (*pcVar3)((int *)uVar9,&puStack_90);
  if (_UNK_8111a5b0 == iStack_84) {
    return;
  }
  uVar7 = 0x8106ed0d;
  uVar8 = func_0x811185a0();
  uStack_b0 = (undefined4)((ulonglong)uVar8 >> 0x20);
  puStack_98 = &UNK_8111a5b0;
  iStack_a8 = _UNK_8111a5b0;
  uStack_b4 = 0x80000000;
  iVar5 = *(int *)uVar8;
  puStack_b8 = &UNK_81144c84;
  pcVar4 = *(code **)(iVar5 + 0x44);
  pcStack_ac = pcVar3;
  iStack_a0 = iVar6;
  ppuStack_9c = &puStack_90;
  uStack_94 = uVar7;
  (*pcVar4)((int *)uVar8,&puStack_b8);
  if (_UNK_8111a5b0 == iStack_a8) {
    return;
  }
  iVar6 = func_0x811185a0();
  puStack_c4 = &UNK_8111a5b0;
  iStack_d4 = _UNK_8111a5b0;
  puStack_e0 = &UNK_81145588;
  pcStack_dc = pcVar4;
  iStack_d8 = iVar6;
  iStack_cc = iVar5;
  ppuStack_c8 = &puStack_b8;
  func_0x810809d4(iVar6 + 0xc,&puStack_e0);
  piVar1 = *(int **)(iVar6 + 0x24);
  if (piVar1 != (int *)0x0) {
    puStack_e0 = &UNK_81145498;
    (**(code **)(*piVar1 + 8))(piVar1,iVar6,pcVar4);
  }
  if (_UNK_8111a5b0 == iStack_d4) {
    return;
  }
  uVar7 = 0x8106edad;
  piVar1 = (int *)func_0x811185a0();
  iStack_f0 = _UNK_8111a5b0;
  uStack_f4 = 0x80000001;
  puStack_f8 = &UNK_81145254;
  pcStack_e8 = pcVar4;
  uStack_e4 = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_f8);
  if (_UNK_8111a5b0 == iStack_f0) {
    return;
  }
  uVar7 = 0x8106edeb;
  piVar1 = (int *)func_0x811185a0();
  puStack_100 = &UNK_81145498;
  puStack_108 = &UNK_8111a5b0;
  iStack_10c = _UNK_8111a5b0;
  uStack_11c = 0x80000002;
  puStack_120 = &UNK_81145278;
  iStack_104 = iVar6;
  uStack_fc = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_120);
  piVar2 = (int *)piVar1[0xe];
  if (piVar2 != (int *)0x0) {
    uStack_114 = 0x80000007;
    puStack_118 = &UNK_8114531c;
    puStack_120 = &UNK_81143e70;
    piStack_110 = piVar1;
    (**(code **)(*piVar2 + 0xac))(piVar2,piVar1,&puStack_118);
  }
  if (_UNK_8111a5b0 == iStack_10c) {
    return;
  }
  iVar5 = func_0x811185a0();
  if (*(int **)(iVar5 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar5 + 0x24) + 0xc))();
  }
  return;
}

