
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_8106d010(int param_1,byte param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  char extraout_r1;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint unaff_r5;
  undefined4 uVar8;
  undefined *puStack_50;
  undefined4 uStack_4c;
  int *piStack_48;
  int iStack_44;
  char cStack_40;
  undefined4 *puStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined *puStack_30;
  undefined4 uStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  uint *puStack_20;
  int iStack_1c;
  byte bStack_18;
  undefined4 *puStack_14;
  
  puStack_14 = _UNK_8111a5b0;
  uVar6 = (uint)param_2;
  uVar1 = *(ushort *)(param_1 + 0x10);
  uVar7 = (uint)((uVar1 & 2) != 0);
  if (uVar6 != uVar7) {
    puVar5 = *(uint **)(param_1 + 0x14);
    unaff_r5 = uVar1 & 0xfffffffd;
    *(short *)(param_1 + 0x10) = (short)unaff_r5;
    if (uVar6 != 0) {
      *(ushort *)(param_1 + 0x10) = uVar1 & 0xfffd | 2;
    }
    uVar7 = (uint)(uVar6 != 0);
    if (puVar5 != (uint *)0x0) {
      uStack_24 = 0x80000026;
      puStack_28 = &UNK_81145078;
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
  uVar8 = 0x8106d08d;
  iVar2 = func_0x811185a0();
  puStack_30 = &UNK_8111a5b0;
  puStack_3c = _UNK_8111a5b0;
  uVar1 = *(ushort *)(iVar2 + 0x10);
  uStack_38 = uVar7;
  uStack_34 = unaff_r5;
  uStack_2c = uVar8;
  if ((bool)extraout_r1 != ((uVar1 & 4) == 0)) {
    *(ushort *)(iVar2 + 0x10) = uVar1 & 0xfffb;
    if (extraout_r1 == '\0') {
      *(ushort *)(iVar2 + 0x10) = uVar1 & 0xfffb | 4;
      FUN_8106cfa4(iVar2,0);
      FUN_8106d010(iVar2,0);
    }
    piVar3 = *(int **)(iVar2 + 0x14);
    if (piVar3 != (int *)0x0) {
      puStack_50 = &UNK_81145030;
      uStack_4c = 0x80000027;
      piStack_48 = piVar3;
      iStack_44 = iVar2;
      cStack_40 = extraout_r1;
      (**(code **)(*piVar3 + 8))(piVar3,&puStack_50);
    }
  }
  if (_UNK_8111a5b0 == puStack_3c) {
    return _UNK_8111a5b0;
  }
  uVar8 = 0x8106d113;
  puVar4 = (undefined4 *)func_0x811185a0();
  *(undefined *)(puVar4 + 0xd) = 1;
  puVar4[3] = 0;
  puVar4[4] = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  *puVar4 = &UNK_81145128;
  func_0x8108d650(puVar4 + 5,0,0x20,&UNK_81145128,iVar2,extraout_r1,&UNK_8111a5b0,uVar8);
  *(undefined *)(puVar4 + 0xd) = 0;
  return puVar4;
}

