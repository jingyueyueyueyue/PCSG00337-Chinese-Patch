
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_81082c7e(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 *puStack_10;
  
  puStack_10 = _UNK_8111a5b0;
  uStack_18 = func_0x81116a40();
  uStack_14 = 0;
  iVar1 = func_0x81116840(*(undefined4 *)(**(int **)(*(int *)(param_1 + 0x14) + 4) + 4),0,0,
                          &uStack_18);
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
  if (_UNK_8111a5b0 == puStack_10) {
    return _UNK_8111a5b0;
  }
  puVar2 = (undefined4 *)func_0x811185a0();
  puRam811ae690 = puVar2;
  *puVar2 = &UNK_811462c8;
  uVar3 = 0;
  iVar1 = func_0x81005a98(0x68);
  if (iVar1 != 0) {
    uVar3 = func_0x81082642();
  }
  puVar2[1] = uVar3;
  puVar2[2] = 0;
  func_0x8109d86c(puVar2);
  *puVar2 = &UNK_81146304;
  return puVar2;
}

