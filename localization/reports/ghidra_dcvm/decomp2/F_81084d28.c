
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81084d28(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  func_0x810761d4();
  puVar2 = *(undefined4 **)(param_1 + 4);
  uStack_20 = 0;
  uStack_1c = 0;
  if (puVar2 != &uStack_20) {
    FUN_8107db94(puVar2);
    puVar2[1] = uStack_1c;
    *puVar2 = uStack_20;
  }
  uStack_1c = 0;
  uStack_20 = 0;
  FUN_8107db94(&uStack_20);
  iVar1 = *(int *)(param_1 + 4);
  uStack_20 = 0;
  uStack_1c = 0;
  if ((undefined4 *)(iVar1 + 8) != &uStack_20) {
    FUN_8107db94();
    *(undefined4 *)(iVar1 + 0xc) = uStack_1c;
    *(undefined4 *)(iVar1 + 8) = uStack_20;
  }
  uStack_1c = 0;
  uStack_20 = 0;
  FUN_8107db94(&uStack_20);
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  func_0x811185a0();
  return;
}

