
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106edec(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined *puStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  uStack_24 = 0x80000002;
  puStack_28 = &UNK_81145278;
  (**(code **)(*param_1 + 0x44))(param_1,&puStack_28);
  piVar1 = (int *)param_1[0xe];
  if (piVar1 != (int *)0x0) {
    uStack_1c = 0x80000007;
    puStack_20 = &UNK_8114531c;
    puStack_28 = &UNK_81143e70;
    piStack_18 = param_1;
    (**(code **)(*piVar1 + 0xac))(piVar1,param_1,&puStack_20);
  }
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  iVar2 = func_0x811185a0();
  if (*(int **)(iVar2 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar2 + 0x24) + 0xc))();
  }
  return;
}

