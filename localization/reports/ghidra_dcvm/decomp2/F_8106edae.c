
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106edae(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined *puStack_40;
  undefined4 uStack_3c;
  undefined *puStack_38;
  undefined4 uStack_34;
  int *piStack_30;
  int iStack_2c;
  undefined *puStack_28;
  undefined *puStack_18;
  undefined4 uStack_14;
  int iStack_10;
  
  iStack_10 = _UNK_8111a5b0;
  uStack_14 = 0x80000001;
  puStack_18 = &UNK_81145254;
  (**(code **)(*param_1 + 0x44))(param_1,&puStack_18);
  if (_UNK_8111a5b0 == iStack_10) {
    return;
  }
  piVar1 = (int *)func_0x811185a0();
  puStack_28 = &UNK_8111a5b0;
  iStack_2c = _UNK_8111a5b0;
  uStack_3c = 0x80000002;
  puStack_40 = &UNK_81145278;
  (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_40);
  piVar2 = (int *)piVar1[0xe];
  if (piVar2 != (int *)0x0) {
    uStack_34 = 0x80000007;
    puStack_38 = &UNK_8114531c;
    puStack_40 = &UNK_81143e70;
    piStack_30 = piVar1;
    (**(code **)(*piVar2 + 0xac))(piVar2,piVar1,&puStack_38);
  }
  if (_UNK_8111a5b0 == iStack_2c) {
    return;
  }
  iVar3 = func_0x811185a0();
  if (*(int **)(iVar3 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar3 + 0x24) + 0xc))();
  }
  return;
}

