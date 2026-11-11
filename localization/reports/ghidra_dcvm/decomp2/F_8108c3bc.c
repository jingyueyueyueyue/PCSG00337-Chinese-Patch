
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108c3bc(void)

{
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined auStack_30 [32];
  int iStack_10;
  
  iStack_10 = _UNK_8111a5b0;
  uStack_40 = 0x10;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  func_0x811187c0(&uStack_40);
  func_0x81118340(uRam811913d8,auStack_30);
  if (iRam811913e8 != 0) {
    func_0x81118340(iRam811913e8,auStack_30);
  }
  if (iRam811913f8 != 0) {
    func_0x81118340(iRam811913f8,auStack_30);
  }
  if (_UNK_8111a5b0 == iStack_10) {
    return;
  }
  func_0x811185a0();
  FUN_8108d0da();
  FUN_8108d024(0x2d);
  return;
}

