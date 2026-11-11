
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810940b0(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined uStack_414;
  undefined auStack_413 [1023];
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  uRam8114a6e4 = 0;
  iVar2 = func_0x81118110();
  uVar1 = uRam81191df4;
  uVar4 = uRam81191df0;
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  uRam81191df0 = 0x3bf;
  uRam81191df4 = 0x21f;
  uRam8114a6e4 = 1;
  iVar2 = func_0x81118110();
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  iVar2 = func_0x81118100(0x81191dc4);
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (iRam81191de8 != 0) {
    uVar3 = 0x81191dd8;
    if (0xf < uRam81191dec) {
      uVar3 = uRam81191dd8;
    }
    iVar2 = func_0x81118120(uVar3,uRam81191df0,uRam81191df4);
    if (iVar2 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
  }
  iVar2 = func_0x81118130();
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  uStack_414 = 0;
  func_0x811182a0(auStack_413,0,0x3ff);
  func_0x81118140(1,&uStack_414,0,0);
  uRam8114a6e4 = 1;
  uRam81191df0 = uVar4;
  uRam81191df4 = uVar1;
  iVar2 = func_0x81118110();
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  iVar2 = func_0x81118100(0x81191dc4);
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (iRam81191de8 != 0) {
    uVar3 = 0x81191dd8;
    if (0xf < uRam81191dec) {
      uVar3 = uRam81191dd8;
    }
    iVar2 = func_0x81118120(uVar3,uRam81191df0,uRam81191df4);
    if (iVar2 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
  }
  iVar2 = func_0x81118130();
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  uVar4 = 0x81094281;
  func_0x811185a0();
  uRam81191dd8 = uRam81191dd8 & 0xffffff00;
  iRam81191de8 = 0;
  uRam81191dec = 0xf;
  func_0x81118450(0x81191dd4,&UNK_810fe98d,0x811ae7e8,0xf,uVar1,uVar4);
  return;
}

