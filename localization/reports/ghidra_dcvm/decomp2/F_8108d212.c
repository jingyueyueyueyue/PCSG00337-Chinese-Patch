
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108d212(undefined *param_1)

{
  int iVar1;
  undefined2 uStack_20;
  undefined uStack_1e;
  undefined uStack_1c;
  undefined uStack_1a;
  undefined uStack_18;
  undefined uStack_16;
  int iStack_10;
  
  iStack_10 = _UNK_8111a5b0;
  iVar1 = func_0x81116680(&uStack_20);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  param_1[4] = uStack_1e;
  param_1[3] = uStack_1c;
  param_1[2] = uStack_1a;
  param_1[1] = uStack_18;
  *param_1 = uStack_16;
  *(undefined2 *)(param_1 + 6) = uStack_20;
  if (_UNK_8111a5b0 == iStack_10) {
    return;
  }
  func_0x811185a0();
  return;
}

