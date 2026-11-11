
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81094306(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  
  iStack_10 = _UNK_8111a5b0;
  uStack_18 = param_1[1];
  uStack_14 = param_2;
  iVar1 = func_0x81118750(*param_1,8,&uStack_18);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_10) {
    return;
  }
  piVar2 = (int *)func_0x811185a0();
  if (-1 < *piVar2) {
    func_0x81118700(*piVar2,0,0);
    *piVar2 = -1;
  }
  return;
}

