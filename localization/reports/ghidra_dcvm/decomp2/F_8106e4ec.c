
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106e4ec(short *param_1,int param_2)

{
  int *piVar1;
  undefined extraout_r1;
  int iVar2;
  code *pcVar3;
  short sVar4;
  short sVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined6 uVar8;
  short sStack_70;
  short sStack_6e;
  int iStack_6c;
  undefined8 uStack_64;
  int iStack_5c;
  undefined2 *puStack_58;
  undefined4 uStack_54;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  undefined *puStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined2 uStack_3e;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined2 uStack_36;
  int iStack_34;
  int iStack_30;
  short *psStack_2c;
  undefined *puStack_28;
  short sStack_18;
  short sStack_16;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  if (*(int *)(param_2 + 0x38) == 0) {
    sStack_18 = 0;
    *param_1 = 0;
    sStack_16 = 0;
    param_1[1] = 0;
    sVar4 = *(short *)(param_2 + 0x3c);
  }
  else {
    FUN_8106e4ec(&sStack_18);
    *param_1 = sStack_18;
    param_1[1] = sStack_16;
    sVar4 = *(short *)(param_2 + 0x3c);
  }
  iVar2 = (int)sVar4;
  *param_1 = sStack_18 + sVar4;
  param_1[1] = *(short *)(param_2 + 0x3e) + sStack_16;
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  uVar7 = func_0x811185a0();
  piVar1 = (int *)uVar7;
  puStack_28 = &UNK_8111a5b0;
  iStack_34 = _UNK_8111a5b0;
  uStack_38 = *(undefined2 *)(piVar1 + 0xf);
  uStack_36 = *(undefined2 *)((int)piVar1 + 0x3e);
  uStack_48 = 0x80000013;
  puStack_4c = &UNK_81145470;
  iStack_30 = param_2;
  psStack_2c = param_1;
  FUN_8106e4ec(&uStack_50,piVar1);
  uStack_3c = uStack_50;
  uStack_3a = uStack_4e;
  uStack_40 = (undefined2)((ulonglong)uVar7 >> 0x20);
  *(undefined2 *)(piVar1 + 0xf) = uStack_40;
  uStack_3e = (undefined2)iVar2;
  *(undefined2 *)((int)piVar1 + 0x3e) = uStack_3e;
  *(byte *)(piVar1 + 0x11) = *(byte *)(piVar1 + 0x11) | 0x10;
  FUN_8106e4ec(&uStack_50,piVar1);
  uStack_44 = uStack_50;
  uStack_42 = uStack_4e;
  pcVar3 = *(code **)(*piVar1 + 0x44);
  (*pcVar3)(piVar1,&puStack_4c);
  sVar4 = (short)pcVar3;
  if (_UNK_8111a5b0 == iStack_34) {
    return;
  }
  uVar6 = 0x8106e5f1;
  uVar8 = func_0x811185a0();
  sVar5 = (short)((uint6)uVar8 >> 0x20);
  piVar1 = (int *)uVar8;
  iStack_6c = _UNK_8111a5b0;
  iStack_5c = iVar2;
  uStack_54 = uVar6;
  if (piVar1[0xe] == 0) {
    pcVar3 = *(code **)(*piVar1 + 0x10);
    puStack_58 = &uStack_50;
  }
  else {
    puStack_58 = &uStack_50;
    uStack_64 = uVar7;
    FUN_8106e4ec(&sStack_70);
    sVar5 = sVar5 - sStack_70;
    sVar4 = sVar4 - sStack_6e;
    pcVar3 = *(code **)(*piVar1 + 0x10);
    uVar7 = uStack_64;
  }
  uStack_64 = uVar7;
  (*pcVar3)(piVar1,(int)sVar5,(int)sVar4);
  if (_UNK_8111a5b0 == iStack_6c) {
    return;
  }
  piVar1 = (int *)func_0x811185a0();
  iVar2 = (**(code **)(*piVar1 + 0x8c))(piVar1,extraout_r1);
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x50))(piVar1,extraout_r1);
  }
  return;
}

