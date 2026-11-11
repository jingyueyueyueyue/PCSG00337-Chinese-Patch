
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108cc94(undefined4 *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  int iStack_10;
  
  iStack_10 = _UNK_8111a5b0;
  iStack_50 = 0;
  iStack_4c = 0;
  if (param_2 == 0) {
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    iStack_18 = 0;
    uStack_14 = 0;
    uStack_48 = 0x38;
    iVar2 = func_0x81118650(*(undefined4 *)*param_1,&uStack_48);
    if (iVar2 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    bVar1 = iStack_18 != 0;
  }
  else {
    if (param_2 != 0x7fffffff) {
      iStack_4c = param_2 * 1000;
    }
    piVar4 = (int *)0x0;
    if (param_2 != 0x7fffffff) {
      piVar4 = &iStack_4c;
    }
    iVar2 = func_0x81118730(*(undefined4 *)*param_1,1,1,&iStack_50,piVar4);
    if ((((iVar2 != -0x7ffd7ff9) && (iVar2 != -0x7ffd7ffa)) && (iVar2 != -0x7ffd7ffb)) &&
       (iVar2 != 0)) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    bVar1 = false;
    if (iStack_50 != 0) {
      bVar1 = true;
    }
  }
  if (_UNK_8111a5b0 != iStack_10) {
    puVar3 = (undefined4 *)func_0x811185a0(bVar1);
    *puVar3 = 0xffffffff;
    return;
  }
  return;
}

