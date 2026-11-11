
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810838fa(void)

{
  int iVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  
  iStack_10 = _UNK_8111a5b0;
  iVar1 = *(int *)(iRam811ae690 + 4);
  uStack_18 = func_0x81116a40();
  uStack_14 = 0;
  iVar1 = func_0x81116840(*(undefined4 *)(**(int **)(*(int *)(iVar1 + 0x14) + 4) + 4),0,0,&uStack_18
                         );
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  iVar1 = func_0x81116a80(&uStack_18);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  func_0x81087208();
  if (_UNK_8111a5b0 == iStack_10) {
    return;
  }
  func_0x811185a0();
  return;
}

