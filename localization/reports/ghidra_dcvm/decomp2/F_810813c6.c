
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_810813c6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint **ppuVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint in_fpscr;
  uint extraout_s0;
  uint uVar8;
  undefined4 extraout_s0_00;
  undefined8 uVar9;
  int iStack_58;
  uint **ppuStack_54;
  uint *puStack_48;
  undefined *puStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint **ppuStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  uint **ppuStack_1c;
  
  ppuStack_1c = _UNK_8111a5b0;
  iVar1 = FUN_810812b0(param_1,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = 1;
    uVar2 = 0;
  }
  else {
    iStack_20 = iVar1;
    uVar2 = FUN_81081376(param_1,param_2,&iStack_20,param_4);
  }
  if (_UNK_8111a5b0 == ppuStack_1c) {
    return uVar2;
  }
  uVar7 = 0x8108140d;
  ppuVar4 = ppuStack_1c;
  uVar9 = func_0x811185a0(uVar2);
  puVar5 = (uint *)((ulonglong)uVar9 >> 0x20);
  ppuStack_34 = _UNK_8111a5b0;
  *puVar5 = extraout_s0;
  puVar6 = *ppuVar4;
  *(undefined4 *)((int)uVar9 + 8) = 0;
  uStack_2c = param_4;
  uStack_28 = param_2;
  uStack_24 = uVar7;
  if (puVar6 != (uint *)0x0) {
    if ((*puVar6 & 0xf) == 1) {
      uVar2 = 1;
      *puVar5 = puVar6[1];
      goto LAB_81081470;
    }
    if ((*puVar6 & 0xf) == 0) {
      func_0x8108d65a(&uStack_38,puVar6 + 1,4);
      uVar2 = 1;
      uVar8 = VectorSignedToFloat(uStack_38,(byte)(in_fpscr >> 0x15) & 3);
      *puVar5 = uVar8;
      goto LAB_81081470;
    }
  }
  *(undefined4 *)((int)uVar9 + 8) = 3;
  uVar2 = 0;
LAB_81081470:
  if (_UNK_8111a5b0 == ppuStack_34) {
    return uVar2;
  }
  uVar7 = 0x81081481;
  ppuVar4 = ppuStack_34;
  uVar9 = func_0x811185a0(uVar2);
  iVar1 = (int)uVar9;
  puStack_44 = &UNK_8111a5b0;
  ppuStack_54 = _UNK_8111a5b0;
  puStack_48 = puVar5;
  iStack_40 = param_1;
  uStack_3c = uVar7;
  iVar3 = FUN_810812b0(iVar1,ppuVar4);
  if (iVar3 == 0) {
    *(undefined4 *)(iVar1 + 8) = 1;
    uVar2 = 0;
  }
  else {
    iStack_58 = iVar3;
    uVar2 = FUN_8108140e(extraout_s0_00,iVar1,(int)((ulonglong)uVar9 >> 0x20),&iStack_58);
  }
  if (_UNK_8111a5b0 == ppuStack_54) {
    return uVar2;
  }
  ppuVar4 = (uint **)func_0x811185a0(uVar2);
  if (*ppuVar4 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if ((**ppuVar4 & 0xf) == 2) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

