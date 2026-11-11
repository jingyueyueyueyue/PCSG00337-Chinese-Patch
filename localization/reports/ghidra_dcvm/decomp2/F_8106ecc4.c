
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106ecc4(int *param_1,undefined2 param_2,undefined2 param_3)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined *puStack_b0;
  undefined4 uStack_ac;
  undefined *puStack_a8;
  undefined4 uStack_a4;
  int *piStack_a0;
  int iStack_9c;
  undefined *puStack_98;
  int iStack_94;
  undefined *puStack_90;
  undefined4 uStack_8c;
  undefined *puStack_88;
  undefined4 uStack_84;
  int iStack_80;
  code *pcStack_78;
  undefined4 uStack_74;
  undefined *puStack_70;
  code *pcStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_5c;
  undefined **ppuStack_58;
  undefined *puStack_54;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  code *pcStack_3c;
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
  uStack_1c = 0x8000000c;
  iVar5 = *param_1;
  puStack_20 = &UNK_811453d4;
  pcVar3 = *(code **)(iVar5 + 0x44);
  uStack_18 = param_2;
  uStack_16 = param_3;
  (*pcVar3)(param_1,&puStack_20);
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  uVar7 = 0x8106ed0d;
  uVar8 = func_0x811185a0();
  uStack_40 = (undefined4)((ulonglong)uVar8 >> 0x20);
  puStack_28 = &UNK_8111a5b0;
  iStack_38 = _UNK_8111a5b0;
  uStack_44 = 0x80000000;
  iVar6 = *(int *)uVar8;
  puStack_48 = &UNK_81144c84;
  pcVar4 = *(code **)(iVar6 + 0x44);
  pcStack_3c = pcVar3;
  iStack_30 = iVar5;
  ppuStack_2c = &puStack_20;
  uStack_24 = uVar7;
  (*pcVar4)((int *)uVar8,&puStack_48);
  if (_UNK_8111a5b0 == iStack_38) {
    return;
  }
  iVar5 = func_0x811185a0();
  puStack_54 = &UNK_8111a5b0;
  iStack_64 = _UNK_8111a5b0;
  puStack_70 = &UNK_81145588;
  pcStack_6c = pcVar4;
  iStack_68 = iVar5;
  iStack_5c = iVar6;
  ppuStack_58 = &puStack_48;
  func_0x810809d4(iVar5 + 0xc,&puStack_70);
  piVar1 = *(int **)(iVar5 + 0x24);
  if (piVar1 != (int *)0x0) {
    puStack_70 = &UNK_81145498;
    (**(code **)(*piVar1 + 8))(piVar1,iVar5,pcVar4);
  }
  if (_UNK_8111a5b0 == iStack_64) {
    return;
  }
  uVar7 = 0x8106edad;
  piVar1 = (int *)func_0x811185a0();
  iStack_80 = _UNK_8111a5b0;
  uStack_84 = 0x80000001;
  puStack_88 = &UNK_81145254;
  pcStack_78 = pcVar4;
  uStack_74 = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_88);
  if (_UNK_8111a5b0 == iStack_80) {
    return;
  }
  uVar7 = 0x8106edeb;
  piVar1 = (int *)func_0x811185a0();
  puStack_90 = &UNK_81145498;
  puStack_98 = &UNK_8111a5b0;
  iStack_9c = _UNK_8111a5b0;
  uStack_ac = 0x80000002;
  puStack_b0 = &UNK_81145278;
  iStack_94 = iVar5;
  uStack_8c = uVar7;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_b0);
  piVar2 = (int *)piVar1[0xe];
  if (piVar2 != (int *)0x0) {
    uStack_a4 = 0x80000007;
    puStack_a8 = &UNK_8114531c;
    puStack_b0 = &UNK_81143e70;
    piStack_a0 = piVar1;
    (**(code **)(*piVar2 + 0xac))(piVar2,piVar1,&puStack_a8);
  }
  if (_UNK_8111a5b0 == iStack_9c) {
    return;
  }
  iVar5 = func_0x811185a0();
  if (*(int **)(iVar5 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar5 + 0x24) + 0xc))();
  }
  return;
}

