
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8109249e(int param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uStack_390;
  undefined4 uStack_38c;
  undefined *puStack_388;
  undefined4 uStack_384;
  undefined4 uStack_380;
  undefined4 uStack_37c;
  undefined4 uStack_378;
  undefined4 uStack_374;
  undefined4 uStack_370;
  undefined4 uStack_36c;
  undefined4 uStack_368;
  undefined auStack_364 [844];
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  puStack_388 = (undefined *)0x0;
  uStack_384 = 0;
  uStack_380 = 0;
  uStack_37c = 0;
  uStack_38c = 0;
  uStack_378 = 0;
  uStack_374 = 0;
  uStack_370 = 0;
  uStack_36c = 0;
  uStack_368 = 0;
  func_0x811182b0(auStack_364,*(undefined4 *)(param_1 + 0x48),0x34c);
  uStack_38c = *(undefined4 *)(param_1 + 0x44);
  puStack_388 = auStack_364;
  uVar1 = func_0x81117270(&uStack_38c,*(undefined4 *)(param_1 + 0x4c),
                          *(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x30),
                          &uStack_390);
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  if (*(int *)(param_1 + 0x54) != 0) {
    **(undefined4 **)(param_1 + 0x54) = uStack_390;
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar1 = 0x81092511;
  uVar2 = func_0x811185a0();
  func_0x811182c0((int)uVar2,&UNK_811380dc,(int)((ulonglong)uVar2 >> 0x20),0x80dc,param_1,uVar1);
  return;
}

