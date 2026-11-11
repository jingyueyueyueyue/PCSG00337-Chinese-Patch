
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_8106cfa4(int param_1,byte param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  byte extraout_r1;
  char extraout_r1_00;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined *puVar9;
  undefined4 uVar10;
  undefined *puStack_78;
  undefined4 uStack_74;
  int *piStack_70;
  int iStack_6c;
  char cStack_68;
  undefined4 *puStack_64;
  uint uStack_60;
  undefined *puStack_5c;
  undefined *puStack_58;
  undefined4 uStack_54;
  undefined *puStack_50;
  undefined4 uStack_4c;
  uint *puStack_48;
  int iStack_44;
  byte bStack_40;
  undefined4 *puStack_3c;
  uint uStack_38;
  undefined *puStack_34;
  undefined *puStack_28;
  undefined4 uStack_24;
  uint *puStack_20;
  int iStack_1c;
  byte bStack_18;
  undefined4 *puStack_14;
  
  puVar9 = &UNK_8111a5b0;
  puStack_14 = _UNK_8111a5b0;
  uVar7 = *(ushort *)(param_1 + 0x10) & 1;
  if (uVar7 != param_2) {
    uVar7 = 0xfffe;
    puVar5 = *(uint **)(param_1 + 0x14);
    uVar1 = *(ushort *)(param_1 + 0x10) & 0xfffe;
    *(ushort *)(param_1 + 0x10) = uVar1;
    if (param_2 != 0) {
      *(ushort *)(param_1 + 0x10) = uVar1 | 1;
    }
    if (puVar5 != (uint *)0x0) {
      uStack_24 = 0x80000023;
      puStack_28 = &UNK_8114500c;
      uVar7 = *puVar5;
      puStack_20 = puVar5;
      iStack_1c = param_1;
      bStack_18 = param_2;
      (**(code **)(uVar7 + 8))(puVar5,&puStack_28);
    }
  }
  if (_UNK_8111a5b0 == puStack_14) {
    return _UNK_8111a5b0;
  }
  iVar2 = func_0x811185a0();
  puStack_34 = &UNK_8111a5b0;
  puStack_3c = _UNK_8111a5b0;
  uVar6 = (uint)extraout_r1;
  uVar1 = *(ushort *)(iVar2 + 0x10);
  uVar8 = (uint)((uVar1 & 2) != 0);
  uStack_38 = uVar7;
  if (uVar6 != uVar8) {
    puVar5 = *(uint **)(iVar2 + 0x14);
    puVar9 = (undefined *)(uVar1 & 0xfffffffd);
    *(short *)(iVar2 + 0x10) = (short)puVar9;
    if (uVar6 != 0) {
      *(ushort *)(iVar2 + 0x10) = uVar1 & 0xfffd | 2;
    }
    uVar8 = (uint)(uVar6 != 0);
    if (puVar5 != (uint *)0x0) {
      uStack_4c = 0x80000026;
      puStack_50 = &UNK_81145078;
      uVar8 = *puVar5;
      puStack_48 = puVar5;
      iStack_44 = iVar2;
      bStack_40 = extraout_r1;
      (**(code **)(uVar8 + 8))(puVar5,&puStack_50);
    }
  }
  if (_UNK_8111a5b0 == puStack_3c) {
    return _UNK_8111a5b0;
  }
  uVar10 = 0x8106d08d;
  iVar2 = func_0x811185a0();
  puStack_58 = &UNK_8111a5b0;
  puStack_64 = _UNK_8111a5b0;
  uVar1 = *(ushort *)(iVar2 + 0x10);
  uStack_60 = uVar8;
  puStack_5c = puVar9;
  uStack_54 = uVar10;
  if ((bool)extraout_r1_00 != ((uVar1 & 4) == 0)) {
    *(ushort *)(iVar2 + 0x10) = uVar1 & 0xfffb;
    if (extraout_r1_00 == '\0') {
      *(ushort *)(iVar2 + 0x10) = uVar1 & 0xfffb | 4;
      FUN_8106cfa4(iVar2,0);
      FUN_8106d010(iVar2,0);
    }
    piVar3 = *(int **)(iVar2 + 0x14);
    if (piVar3 != (int *)0x0) {
      puStack_78 = &UNK_81145030;
      uStack_74 = 0x80000027;
      piStack_70 = piVar3;
      iStack_6c = iVar2;
      cStack_68 = extraout_r1_00;
      (**(code **)(*piVar3 + 8))(piVar3,&puStack_78);
    }
  }
  if (_UNK_8111a5b0 == puStack_64) {
    return _UNK_8111a5b0;
  }
  uVar10 = 0x8106d113;
  puVar4 = (undefined4 *)func_0x811185a0();
  *(undefined *)(puVar4 + 0xd) = 1;
  puVar4[3] = 0;
  puVar4[4] = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  *puVar4 = &UNK_81145128;
  func_0x8108d650(puVar4 + 5,0,0x20,&UNK_81145128,iVar2,extraout_r1_00,&UNK_8111a5b0,uVar10);
  *(undefined *)(puVar4 + 0xd) = 0;
  return puVar4;
}

