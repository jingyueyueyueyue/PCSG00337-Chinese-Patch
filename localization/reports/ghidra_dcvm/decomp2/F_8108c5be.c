
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8108c5be(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined auStack_38 [32];
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  uStack_48 = 0x10;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  func_0x811187c0(&uStack_48);
  func_0x81118340(uRam811913d8,auStack_38);
  if (iRam811913e8 != 0) {
    func_0x81118340(iRam811913e8,auStack_38);
  }
  if (iRam811913f8 != 0) {
    func_0x81118340(iRam811913f8,auStack_38);
  }
  if (piRam811ae7c8 != (int *)0x0) {
    (**(code **)(*piRam811ae7c8 + 4))();
  }
  if (iRam811ae7cc != 0) {
    FUN_8108ea2c();
  }
  func_0x810945b8();
  puVar2 = (uint *)&UNK_81137b54;
  iVar3 = 1;
  do {
    iVar1 = func_0x81116d40(*puVar2 & 0xffff);
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    iVar3 = iVar3 + -1;
    puVar2 = puVar2 + -1;
  } while (-1 < iVar3);
  if (_UNK_8111a5b0 == iStack_18) {
    return _UNK_8111a5b0;
  }
  func_0x811185a0();
  return 0;
}

