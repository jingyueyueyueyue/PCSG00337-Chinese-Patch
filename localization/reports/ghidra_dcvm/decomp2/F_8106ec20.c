
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106ec20(int *param_1,undefined param_2,undefined param_3,undefined2 param_4,
                 undefined2 param_5)

{
  int *piVar1;
  int *piVar2;
  undefined extraout_r1;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined6 uVar9;
  undefined *puStack_100;
  undefined4 uStack_fc;
  undefined *puStack_f8;
  undefined4 uStack_f4;
  int *piStack_f0;
  int iStack_ec;
  undefined *puStack_e8;
  int iStack_e4;
  undefined *puStack_e0;
  undefined4 uStack_dc;
  undefined *puStack_d8;
  undefined4 uStack_d4;
  int iStack_d0;
  code *pcStack_c8;
  undefined4 uStack_c4;
  undefined *puStack_c0;
  code *pcStack_bc;
  int iStack_b8;
  int iStack_b4;
  int iStack_ac;
  undefined **ppuStack_a8;
  undefined *puStack_a4;
  undefined *puStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  code *pcStack_8c;
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
  undefined *puStack_60;
  int iStack_5c;
  undefined *puStack_58;
  undefined4 uStack_54;
  undefined *puStack_50;
  undefined4 uStack_4c;
  undefined uStack_48;
  undefined uStack_47;
  undefined2 uStack_46;
  undefined2 uStack_44;
  int iStack_40;
  undefined *puStack_38;
  int iStack_34;
  undefined *puStack_30;
  undefined4 uStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined uStack_20;
  undefined uStack_1f;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  uStack_24 = 0x8000000a;
  iVar5 = *param_1;
  uStack_46 = 0x538c;
  uStack_1c = param_5;
  puStack_28 = &UNK_8114538c;
  pcVar3 = *(code **)(iVar5 + 0x44);
  uStack_20 = param_2;
  uStack_1f = param_3;
  uStack_1e = param_4;
  (*pcVar3)(param_1,&puStack_28);
  uStack_47 = SUB41(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar7 = 0x8106ec71;
  piVar1 = (int *)func_0x811185a0();
  puStack_30 = &UNK_8111a5b0;
  puStack_38 = &UNK_81145384;
  iStack_40 = _UNK_8111a5b0;
  uStack_4c = 0x8000000b;
  iVar6 = *piVar1;
  uStack_44 = SUB42(puStack_28,0);
  puStack_50 = &UNK_811453b0;
  pcVar3 = *(code **)(iVar6 + 0x44);
  uStack_48 = extraout_r1;
  iStack_34 = iVar5;
  uStack_2c = uVar7;
  (*pcVar3)(piVar1,&puStack_50);
  uStack_66 = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_40) {
    return;
  }
  uVar7 = 0x8106ecc3;
  uVar9 = func_0x811185a0();
  uStack_68 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_58 = &UNK_8111a5b0;
  puStack_60 = &UNK_811453a8;
  iStack_64 = _UNK_8111a5b0;
  uStack_6c = 0x8000000c;
  iVar5 = *(int *)uVar9;
  puStack_70 = &UNK_811453d4;
  pcVar3 = *(code **)(iVar5 + 0x44);
  iStack_5c = iVar6;
  uStack_54 = uVar7;
  (*pcVar3)((int *)uVar9,&puStack_70);
  if (_UNK_8111a5b0 == iStack_64) {
    return;
  }
  uVar7 = 0x8106ed0d;
  uVar8 = func_0x811185a0();
  uStack_90 = (undefined4)((ulonglong)uVar8 >> 0x20);
  puStack_78 = &UNK_8111a5b0;
  iStack_88 = _UNK_8111a5b0;
  uStack_94 = 0x80000000;
  iVar6 = *(int *)uVar8;
  puStack_98 = &UNK_81144c84;
  pcVar4 = *(code **)(iVar6 + 0x44);
  pcStack_8c = pcVar3;
  iStack_80 = iVar5;
  ppuStack_7c = &puStack_70;
  uStack_74 = uVar7;
  (*pcVar4)((int *)uVar8,&puStack_98);
  if (_UNK_8111a5b0 == iStack_88) {
    return;
  }
  iVar5 = func_0x811185a0();
  puStack_a4 = &UNK_8111a5b0;
  iStack_b4 = _UNK_8111a5b0;
  puStack_c0 = &UNK_81145588;
  pcStack_bc = pcVar4;
  iStack_b8 = iVar5;
  iStack_ac = iVar6;
  ppuStack_a8 = &puStack_98;
  func_0x810809d4(iVar5 + 0xc,&puStack_c0);
  piVar1 = *(int **)(iVar5 + 0x24);
  if (piVar1 != (int *)0x0) {
    puStack_c0 = &UNK_81145498;
    (**(code **)(*piVar1 + 8))(piVar1,iVar5,pcVar4);
  }
  if (_UNK_8111a5b0 == iStack_b4) {
    return;
  }
  uVar7 = 0x8106edad;
  piVar1 = (int *)func_0x811185a0();
  iStack_d0 = _UNK_8111a5b0;
  uStack_d4 = 0x80000001;
  puStack_d8 = &UNK_81145254;
  pcStack_c8 = pcVar4;
  uStack_c4 = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_d8);
  if (_UNK_8111a5b0 == iStack_d0) {
    return;
  }
  uVar7 = 0x8106edeb;
  piVar1 = (int *)func_0x811185a0();
  puStack_e0 = &UNK_81145498;
  puStack_e8 = &UNK_8111a5b0;
  iStack_ec = _UNK_8111a5b0;
  uStack_fc = 0x80000002;
  puStack_100 = &UNK_81145278;
  iStack_e4 = iVar5;
  uStack_dc = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_100);
  piVar2 = (int *)piVar1[0xe];
  if (piVar2 != (int *)0x0) {
    uStack_f4 = 0x80000007;
    puStack_f8 = &UNK_8114531c;
    puStack_100 = &UNK_81143e70;
    piStack_f0 = piVar1;
    (**(code **)(*piVar2 + 0xac))(piVar2,piVar1,&puStack_f8);
  }
  if (_UNK_8111a5b0 == iStack_ec) {
    return;
  }
  iVar5 = func_0x811185a0();
  if (*(int **)(iVar5 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar5 + 0x24) + 0xc))();
  }
  return;
}

