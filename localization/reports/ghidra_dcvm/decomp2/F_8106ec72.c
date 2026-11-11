
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106ec72(int *param_1,undefined param_2,undefined param_3,undefined2 param_4,
                 undefined2 param_5)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined6 uVar9;
  undefined *puStack_d8;
  undefined4 uStack_d4;
  undefined *puStack_d0;
  undefined4 uStack_cc;
  int *piStack_c8;
  int iStack_c4;
  undefined *puStack_c0;
  int iStack_bc;
  undefined *puStack_b8;
  undefined4 uStack_b4;
  undefined *puStack_b0;
  undefined4 uStack_ac;
  int iStack_a8;
  code *pcStack_a0;
  undefined4 uStack_9c;
  undefined *puStack_98;
  code *pcStack_94;
  int iStack_90;
  int iStack_8c;
  int iStack_84;
  undefined **ppuStack_80;
  undefined *puStack_7c;
  undefined *puStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  code *pcStack_64;
  int iStack_60;
  int iStack_58;
  undefined **ppuStack_54;
  undefined *puStack_50;
  undefined4 uStack_4c;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined2 uStack_40;
  undefined2 uStack_3e;
  int iStack_3c;
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
  uStack_24 = 0x8000000b;
  iVar6 = *param_1;
  uStack_1c = param_5;
  puStack_28 = &UNK_811453b0;
  pcVar3 = *(code **)(iVar6 + 0x44);
  uStack_20 = param_2;
  uStack_1f = param_3;
  uStack_1e = param_4;
  (*pcVar3)(param_1,&puStack_28);
  uStack_3e = SUB42(pcVar3,0);
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar7 = 0x8106ecc3;
  uVar9 = func_0x811185a0();
  uStack_40 = (undefined2)((uint6)uVar9 >> 0x20);
  puStack_30 = &UNK_8111a5b0;
  puStack_38 = &UNK_811453a8;
  iStack_3c = _UNK_8111a5b0;
  uStack_44 = 0x8000000c;
  iVar5 = *(int *)uVar9;
  puStack_48 = &UNK_811453d4;
  pcVar3 = *(code **)(iVar5 + 0x44);
  iStack_34 = iVar6;
  uStack_2c = uVar7;
  (*pcVar3)((int *)uVar9,&puStack_48);
  if (_UNK_8111a5b0 == iStack_3c) {
    return;
  }
  uVar7 = 0x8106ed0d;
  uVar8 = func_0x811185a0();
  uStack_68 = (undefined4)((ulonglong)uVar8 >> 0x20);
  puStack_50 = &UNK_8111a5b0;
  iStack_60 = _UNK_8111a5b0;
  uStack_6c = 0x80000000;
  iVar6 = *(int *)uVar8;
  puStack_70 = &UNK_81144c84;
  pcVar4 = *(code **)(iVar6 + 0x44);
  pcStack_64 = pcVar3;
  iStack_58 = iVar5;
  ppuStack_54 = &puStack_48;
  uStack_4c = uVar7;
  (*pcVar4)((int *)uVar8,&puStack_70);
  if (_UNK_8111a5b0 == iStack_60) {
    return;
  }
  iVar5 = func_0x811185a0();
  puStack_7c = &UNK_8111a5b0;
  iStack_8c = _UNK_8111a5b0;
  puStack_98 = &UNK_81145588;
  pcStack_94 = pcVar4;
  iStack_90 = iVar5;
  iStack_84 = iVar6;
  ppuStack_80 = &puStack_70;
  func_0x810809d4(iVar5 + 0xc,&puStack_98);
  piVar1 = *(int **)(iVar5 + 0x24);
  if (piVar1 != (int *)0x0) {
    puStack_98 = &UNK_81145498;
    (**(code **)(*piVar1 + 8))(piVar1,iVar5,pcVar4);
  }
  if (_UNK_8111a5b0 == iStack_8c) {
    return;
  }
  uVar7 = 0x8106edad;
  piVar1 = (int *)func_0x811185a0();
  iStack_a8 = _UNK_8111a5b0;
  uStack_ac = 0x80000001;
  puStack_b0 = &UNK_81145254;
  pcStack_a0 = pcVar4;
  uStack_9c = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_b0);
  if (_UNK_8111a5b0 == iStack_a8) {
    return;
  }
  uVar7 = 0x8106edeb;
  piVar1 = (int *)func_0x811185a0();
  puStack_b8 = &UNK_81145498;
  puStack_c0 = &UNK_8111a5b0;
  iStack_c4 = _UNK_8111a5b0;
  uStack_d4 = 0x80000002;
  puStack_d8 = &UNK_81145278;
  iStack_bc = iVar5;
  uStack_b4 = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_d8);
  piVar2 = (int *)piVar1[0xe];
  if (piVar2 != (int *)0x0) {
    uStack_cc = 0x80000007;
    puStack_d0 = &UNK_8114531c;
    puStack_d8 = &UNK_81143e70;
    piStack_c8 = piVar1;
    (**(code **)(*piVar2 + 0xac))(piVar2,piVar1,&puStack_d0);
  }
  if (_UNK_8111a5b0 == iStack_c4) {
    return;
  }
  iVar6 = func_0x811185a0();
  if (*(int **)(iVar6 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar6 + 0x24) + 0xc))();
  }
  return;
}

