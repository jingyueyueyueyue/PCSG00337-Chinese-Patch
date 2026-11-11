
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106da06(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined *puStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  *(undefined4 *)(param_1 + 4) = 0;
  func_0x8106d180(param_1);
  piVar1 = *(int **)(param_1 + 0x10);
  uStack_1c = 0x80000022;
  iStack_18 = param_1;
  if (piVar1 != (int *)0x0) {
    puStack_20 = &UNK_811450ec;
    (**(code **)(*piVar1 + 0x44))(piVar1,&puStack_20);
  }
  if (*(char *)(param_1 + 0x34) != '\0') {
    puStack_20 = &UNK_81143e70;
    func_0x8108d650(param_1 + 0x14,0,0x20);
  }
  *(undefined *)(param_1 + 0x34) = 0;
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  iVar2 = func_0x811185a0();
  (**(code **)(**(int **)(iVar2 + 0x10) + 0x44))();
  return;
}

