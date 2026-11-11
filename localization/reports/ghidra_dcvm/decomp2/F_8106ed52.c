
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106ed52(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puStack_68;
  undefined4 uStack_64;
  undefined *puStack_60;
  undefined4 uStack_5c;
  int *piStack_58;
  int iStack_54;
  undefined *puStack_50;
  int iStack_4c;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined *puStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  
  iStack_1c = _UNK_8111a5b0;
  puStack_28 = &UNK_81145588;
  uStack_24 = param_3;
  iStack_20 = param_1;
  func_0x810809d4(param_1 + 0xc,&puStack_28);
  piVar1 = *(int **)(param_1 + 0x24);
  if (piVar1 != (int *)0x0) {
    puStack_28 = &UNK_81145498;
    (**(code **)(*piVar1 + 8))(piVar1,param_1,param_3);
  }
  if (_UNK_8111a5b0 == iStack_1c) {
    return;
  }
  uVar4 = 0x8106edad;
  piVar1 = (int *)func_0x811185a0();
  iStack_38 = _UNK_8111a5b0;
  uStack_3c = 0x80000001;
  puStack_40 = &UNK_81145254;
  uStack_30 = param_3;
  uStack_2c = uVar4;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_40);
  if (_UNK_8111a5b0 == iStack_38) {
    return;
  }
  uVar4 = 0x8106edeb;
  piVar1 = (int *)func_0x811185a0();
  puStack_48 = &UNK_81145498;
  puStack_50 = &UNK_8111a5b0;
  iStack_54 = _UNK_8111a5b0;
  uStack_64 = 0x80000002;
  puStack_68 = &UNK_81145278;
  iStack_4c = param_1;
  uStack_44 = uVar4;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_68);
  piVar2 = (int *)piVar1[0xe];
  if (piVar2 != (int *)0x0) {
    uStack_5c = 0x80000007;
    puStack_60 = &UNK_8114531c;
    puStack_68 = &UNK_81143e70;
    piStack_58 = piVar1;
    (**(code **)(*piVar2 + 0xac))(piVar2,piVar1,&puStack_60);
  }
  if (_UNK_8111a5b0 == iStack_54) {
    return;
  }
  iVar3 = func_0x811185a0();
  if (*(int **)(iVar3 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar3 + 0x24) + 0xc))();
  }
  return;
}

