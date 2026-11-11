
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108acde(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined auStack_118 [256];
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  func_0x81118320(auStack_118,&UNK_81137ae0);
  func_0x81118190(auStack_118,param_2);
  func_0x81081b02(auStack_118,&UNK_81137ae8,&UNK_81137aec,0);
  uVar1 = func_0x8108c676(auStack_118);
  func_0x8108c67e(auStack_118,param_1,uVar1,0);
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  func_0x811185a0();
  return;
}

