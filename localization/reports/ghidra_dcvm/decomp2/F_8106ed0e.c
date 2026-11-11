
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106ed0e(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puStack_90;
  undefined4 uStack_8c;
  undefined *puStack_88;
  undefined4 uStack_84;
  int *piStack_80;
  int iStack_7c;
  undefined *puStack_78;
  int iStack_74;
  undefined *puStack_70;
  undefined4 uStack_6c;
  undefined *puStack_68;
  undefined4 uStack_64;
  int iStack_60;
  code *pcStack_58;
  undefined4 uStack_54;
  undefined *puStack_50;
  code *pcStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_3c;
  undefined **ppuStack_38;
  undefined *puStack_34;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  uStack_24 = 0x80000000;
  iVar5 = *param_1;
  puStack_28 = &UNK_81144c84;
  pcVar4 = *(code **)(iVar5 + 0x44);
  uStack_20 = param_2;
  uStack_1c = param_3;
  (*pcVar4)(param_1,&puStack_28);
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  iVar1 = func_0x811185a0();
  puStack_34 = &UNK_8111a5b0;
  iStack_44 = _UNK_8111a5b0;
  puStack_50 = &UNK_81145588;
  pcStack_4c = pcVar4;
  iStack_48 = iVar1;
  iStack_3c = iVar5;
  ppuStack_38 = &puStack_28;
  func_0x810809d4(iVar1 + 0xc,&puStack_50);
  piVar2 = *(int **)(iVar1 + 0x24);
  if (piVar2 != (int *)0x0) {
    puStack_50 = &UNK_81145498;
    (**(code **)(*piVar2 + 8))(piVar2,iVar1,pcVar4);
  }
  if (_UNK_8111a5b0 == iStack_44) {
    return;
  }
  uVar6 = 0x8106edad;
  piVar2 = (int *)func_0x811185a0();
  iStack_60 = _UNK_8111a5b0;
  uStack_64 = 0x80000001;
  puStack_68 = &UNK_81145254;
  pcStack_58 = pcVar4;
  uStack_54 = uVar6;
  (**(code **)(*piVar2 + 0x44))(piVar2,&puStack_68);
  if (_UNK_8111a5b0 == iStack_60) {
    return;
  }
  uVar6 = 0x8106edeb;
  piVar2 = (int *)func_0x811185a0();
  puStack_70 = &UNK_81145498;
  puStack_78 = &UNK_8111a5b0;
  iStack_7c = _UNK_8111a5b0;
  uStack_8c = 0x80000002;
  puStack_90 = &UNK_81145278;
  iStack_74 = iVar1;
  uStack_6c = uVar6;
  (**(code **)(*piVar2 + 0x44))(piVar2,&puStack_90);
  piVar3 = (int *)piVar2[0xe];
  if (piVar3 != (int *)0x0) {
    uStack_84 = 0x80000007;
    puStack_88 = &UNK_8114531c;
    puStack_90 = &UNK_81143e70;
    piStack_80 = piVar2;
    (**(code **)(*piVar3 + 0xac))(piVar3,piVar2,&puStack_88);
  }
  if (_UNK_8111a5b0 == iStack_7c) {
    return;
  }
  iVar5 = func_0x811185a0();
  if (*(int **)(iVar5 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar5 + 0x24) + 0xc))();
  }
  return;
}

