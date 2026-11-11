
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810896cc(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  int iStack_44;
  undefined *puStack_3c;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  
  iStack_c = _UNK_8111a5b0;
  uStack_20 = 0;
  uStack_1c = 2;
  uStack_18 = 0x81089783;
  uStack_14 = 0x1c;
  uStack_10 = 0x1000000;
  iVar1 = func_0x81116af0(&uStack_20);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_c) {
    return;
  }
  uVar3 = func_0x811185a0();
  puStack_3c = &UNK_8111a5b0;
  iStack_44 = _UNK_8111a5b0;
  uStack_60 = *param_3;
  uStack_5c = param_3[1];
  uStack_58 = param_3[2];
  uStack_54 = param_3[3];
  uStack_50 = param_3[4];
  uStack_4c = param_3[5];
  if (param_4 == 0) {
    param_4 = 1;
  }
  iStack_48 = param_4;
  iVar1 = func_0x81116c40((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),&uStack_60);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_44) {
    return;
  }
  iVar1 = func_0x811185a0();
  iVar2 = func_0x811166a0(iVar1,1);
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  iVar1 = func_0x811166c0(*(undefined4 *)(iVar1 + 0x18));
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  return;
}

