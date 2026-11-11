
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81068356(undefined4 param_1)

{
  undefined4 ***pppuVar1;
  int iVar2;
  undefined auStack_28 [4];
  undefined4 ***apppuStack_24 [4];
  int iStack_14;
  uint uStack_10;
  int iStack_c;
  
  iStack_c = _UNK_8111a5b0;
  func_0x8106827e(auStack_28,param_1);
  if (iStack_14 != 0) {
    pppuVar1 = apppuStack_24;
    if (0xf < uStack_10) {
      pppuVar1 = apppuStack_24[0];
    }
    FUN_81065c5c(pppuVar1,0xffffffff,0);
  }
  if (0xf < uStack_10) {
    func_0x81005af0(apppuStack_24[0]);
  }
  if (_UNK_8111a5b0 == iStack_c) {
    return;
  }
  func_0x811185a0();
  iVar2 = func_0x8106037e(uRam811ae688);
  func_0x8105d8b0(*(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x178) + 8),0);
  return;
}

