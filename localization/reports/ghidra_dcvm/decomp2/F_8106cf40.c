
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_8106cf40(int param_1,undefined2 param_2,undefined2 param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  byte extraout_r1;
  byte extraout_r1_00;
  char extraout_r1_01;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  undefined4 uVar11;
  undefined *puStack_a8;
  undefined4 uStack_a4;
  int *piStack_a0;
  int iStack_9c;
  char cStack_98;
  undefined4 *puStack_94;
  uint uStack_90;
  undefined *puStack_8c;
  undefined *puStack_88;
  undefined4 uStack_84;
  undefined *puStack_80;
  undefined4 uStack_7c;
  uint *puStack_78;
  int iStack_74;
  byte bStack_70;
  undefined4 *puStack_6c;
  uint uStack_68;
  undefined *puStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined *puStack_58;
  undefined4 uStack_54;
  uint *puStack_50;
  int iStack_4c;
  byte bStack_48;
  undefined4 *puStack_44;
  uint uStack_3c;
  undefined *puStack_38;
  undefined4 uStack_34;
  undefined *puStack_30;
  undefined4 uStack_2c;
  int *piStack_28;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  ushort uStack_1c;
  undefined2 uStack_1a;
  undefined4 *puStack_18;
  
  puStack_18 = _UNK_8111a5b0;
  uVar1 = *(ushort *)(param_1 + 0xc);
  uVar7 = (uint)uVar1;
  piVar3 = *(int **)(param_1 + 0x14);
  uVar2 = *(undefined2 *)(param_1 + 0xe);
  *(undefined2 *)(param_1 + 0xc) = param_2;
  *(undefined2 *)(param_1 + 0xe) = param_3;
  if (piVar3 != (int *)0x0) {
    puStack_30 = &UNK_81145054;
    uStack_2c = 0x80000024;
    piStack_28 = piVar3;
    uStack_20 = param_2;
    uStack_1e = param_3;
    uStack_1c = uVar1;
    uStack_1a = uVar2;
    (**(code **)(*piVar3 + 8))(piVar3,&puStack_30);
  }
  if (_UNK_8111a5b0 == puStack_18) {
    return _UNK_8111a5b0;
  }
  uVar11 = 0x8106cfa3;
  iVar4 = func_0x811185a0();
  puStack_38 = &UNK_81145054;
  puVar10 = &UNK_8111a5b0;
  puStack_44 = _UNK_8111a5b0;
  uVar8 = *(ushort *)(iVar4 + 0x10) & 1;
  uStack_3c = uVar7;
  uStack_34 = uVar11;
  if (uVar8 != extraout_r1) {
    uVar8 = 0xfffe;
    puVar6 = *(uint **)(iVar4 + 0x14);
    uVar1 = *(ushort *)(iVar4 + 0x10) & 0xfffe;
    *(ushort *)(iVar4 + 0x10) = uVar1;
    if (extraout_r1 != 0) {
      *(ushort *)(iVar4 + 0x10) = uVar1 | 1;
    }
    if (puVar6 != (uint *)0x0) {
      uStack_54 = 0x80000023;
      puStack_58 = &UNK_8114500c;
      uVar8 = *puVar6;
      puStack_50 = puVar6;
      iStack_4c = iVar4;
      bStack_48 = extraout_r1;
      (**(code **)(uVar8 + 8))(puVar6,&puStack_58);
    }
  }
  if (_UNK_8111a5b0 != puStack_44) {
    uVar11 = 0x8106d00f;
    iVar4 = func_0x811185a0();
    uStack_60 = 0x80000024;
    puStack_64 = &UNK_8111a5b0;
    puStack_6c = _UNK_8111a5b0;
    uVar7 = (uint)extraout_r1_00;
    uVar1 = *(ushort *)(iVar4 + 0x10);
    uVar9 = (uint)((uVar1 & 2) != 0);
    uStack_68 = uVar8;
    uStack_5c = uVar11;
    if (uVar7 != uVar9) {
      puVar6 = *(uint **)(iVar4 + 0x14);
      puVar10 = (undefined *)(uVar1 & 0xfffffffd);
      *(short *)(iVar4 + 0x10) = (short)puVar10;
      if (uVar7 != 0) {
        *(ushort *)(iVar4 + 0x10) = uVar1 & 0xfffd | 2;
      }
      uVar9 = (uint)(uVar7 != 0);
      if (puVar6 != (uint *)0x0) {
        uStack_7c = 0x80000026;
        puStack_80 = &UNK_81145078;
        uVar9 = *puVar6;
        puStack_78 = puVar6;
        iStack_74 = iVar4;
        bStack_70 = extraout_r1_00;
        (**(code **)(uVar9 + 8))(puVar6,&puStack_80);
      }
    }
    if (_UNK_8111a5b0 != puStack_6c) {
      uVar11 = 0x8106d08d;
      iVar4 = func_0x811185a0();
      puStack_88 = &UNK_8111a5b0;
      puStack_94 = _UNK_8111a5b0;
      uVar1 = *(ushort *)(iVar4 + 0x10);
      uStack_90 = uVar9;
      puStack_8c = puVar10;
      uStack_84 = uVar11;
      if ((bool)extraout_r1_01 != ((uVar1 & 4) == 0)) {
        *(ushort *)(iVar4 + 0x10) = uVar1 & 0xfffb;
        if (extraout_r1_01 == '\0') {
          *(ushort *)(iVar4 + 0x10) = uVar1 & 0xfffb | 4;
          FUN_8106cfa4(iVar4,0);
          FUN_8106d010(iVar4,0);
        }
        piVar3 = *(int **)(iVar4 + 0x14);
        if (piVar3 != (int *)0x0) {
          puStack_a8 = &UNK_81145030;
          uStack_a4 = 0x80000027;
          piStack_a0 = piVar3;
          iStack_9c = iVar4;
          cStack_98 = extraout_r1_01;
          (**(code **)(*piVar3 + 8))(piVar3,&puStack_a8);
        }
      }
      if (_UNK_8111a5b0 == puStack_94) {
        return _UNK_8111a5b0;
      }
      uVar11 = 0x8106d113;
      puVar5 = (undefined4 *)func_0x811185a0();
      *(undefined *)(puVar5 + 0xd) = 1;
      puVar5[3] = 0;
      puVar5[4] = 0;
      puVar5[1] = 0;
      puVar5[2] = 0;
      *puVar5 = &UNK_81145128;
      func_0x8108d650(puVar5 + 5,0,0x20,&UNK_81145128,iVar4,extraout_r1_01,&UNK_8111a5b0,uVar11);
      *(undefined *)(puVar5 + 0xd) = 0;
      return puVar5;
    }
    return _UNK_8111a5b0;
  }
  return _UNK_8111a5b0;
}

