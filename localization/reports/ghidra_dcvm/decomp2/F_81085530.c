
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81085530(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uStack_20;
  int iStack_1c;
  
  iStack_1c = _UNK_8111a5b0;
  uStack_20 = 0;
  uVar2 = *(undefined4 *)(**(int **)(param_2 + 4) + 4);
  func_0x81116870(uVar2,*(undefined4 *)(*(int *)(param_1 + 8) + 0xc));
  func_0x81116a70(uVar2,&uStack_20);
  if (*(int *)(param_1 + 4) != 0) {
    func_0x81116b60(uVar2,0);
  }
  if (_UNK_8111a5b0 == iStack_1c) {
    return;
  }
  puVar1 = (undefined4 *)func_0x811185a0();
  *puVar1 = &UNK_81146390;
  return;
}

