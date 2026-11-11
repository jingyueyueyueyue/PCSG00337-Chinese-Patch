
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8108140e(uint param_1,int param_2,uint *param_3,uint **param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint **ppuVar4;
  uint *puVar5;
  uint in_fpscr;
  uint uVar6;
  undefined4 extraout_s0;
  undefined8 uVar7;
  int iStack_38;
  int iStack_34;
  uint *puStack_28;
  undefined *puStack_24;
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  *param_3 = param_1;
  puVar5 = *param_4;
  *(undefined4 *)(param_2 + 8) = 0;
  if (puVar5 != (uint *)0x0) {
    if ((*puVar5 & 0xf) == 1) {
      uVar1 = 1;
      *param_3 = puVar5[1];
      goto LAB_81081470;
    }
    if ((*puVar5 & 0xf) == 0) {
      func_0x8108d65a(&uStack_18,puVar5 + 1,4);
      uVar1 = 1;
      uVar6 = VectorSignedToFloat(uStack_18,(byte)(in_fpscr >> 0x15) & 3);
      *param_3 = uVar6;
      goto LAB_81081470;
    }
  }
  *(undefined4 *)(param_2 + 8) = 3;
  uVar1 = 0;
LAB_81081470:
  if (_UNK_8111a5b0 == iStack_14) {
    return uVar1;
  }
  iVar3 = iStack_14;
  uVar7 = func_0x811185a0(uVar1);
  iVar2 = (int)uVar7;
  puStack_24 = &UNK_8111a5b0;
  iStack_34 = _UNK_8111a5b0;
  puStack_28 = param_3;
  iVar3 = FUN_810812b0(iVar2,iVar3);
  if (iVar3 == 0) {
    *(undefined4 *)(iVar2 + 8) = 1;
    uVar1 = 0;
  }
  else {
    iStack_38 = iVar3;
    uVar1 = FUN_8108140e(extraout_s0,iVar2,(int)((ulonglong)uVar7 >> 0x20),&iStack_38);
  }
  if (_UNK_8111a5b0 == iStack_34) {
    return uVar1;
  }
  ppuVar4 = (uint **)func_0x811185a0(uVar1);
  if (*ppuVar4 == (uint *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if ((**ppuVar4 & 0xf) == 2) {
      uVar1 = 1;
    }
  }
  return uVar1;
}

