
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108ac84(undefined4 param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined auStack_230 [256];
  int iStack_130;
  undefined *puStack_12c;
  undefined4 uStack_128;
  undefined *puStack_124;
  undefined auStack_118 [256];
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  func_0x81118320(auStack_118,&UNK_81137ae0);
  func_0x81118190(auStack_118,param_1);
  func_0x81081b02(auStack_118,&UNK_81137ae8,&UNK_81137aec,0);
  func_0x8108c676(auStack_118);
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar2 = func_0x811185a0();
  puStack_124 = &UNK_8111a5b0;
  iStack_130 = _UNK_8111a5b0;
  puStack_12c = auStack_118;
  uStack_128 = param_1;
  func_0x81118320(auStack_230,&UNK_81137ae0);
  func_0x81118190(auStack_230,(int)((ulonglong)uVar2 >> 0x20));
  func_0x81081b02(auStack_230,&UNK_81137ae8,&UNK_81137aec,0);
  uVar1 = func_0x8108c676(auStack_230);
  func_0x8108c67e(auStack_230,(int)uVar2,uVar1,0);
  if (_UNK_8111a5b0 == iStack_130) {
    return;
  }
  func_0x811185a0();
  return;
}

