
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_810803a4(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int extraout_r1;
  undefined *puStack_18;
  undefined4 uStack_14;
  int iStack_10;
  
  iStack_10 = _UNK_8111a5b0;
  iVar2 = **(int **)(param_2 + 0xc);
  pcVar1 = *(code **)(iVar2 + 8);
  if (pcVar1 != (code *)0x0) {
    puStack_18 = &UNK_811460bc;
    uStack_14 = 0x27c;
    (*pcVar1)(*(undefined *)(*(int **)(param_2 + 0xc) + 8),&puStack_18,*(undefined4 *)(iVar2 + 4));
  }
  if (_UNK_8111a5b0 == iStack_10) {
    return _UNK_8111a5b0;
  }
  func_0x811185a0();
  *(undefined4 *)(extraout_r1 + 8) = 2;
  return 1;
}

