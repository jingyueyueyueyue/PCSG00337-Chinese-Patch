
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_81092e98(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined auStack_80 [16];
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 *puStack_1c;
  
  puVar10 = auStack_80;
  puStack_1c = _UNK_8111a5b0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_70 = *(undefined4 *)(param_1 + 0x44);
  puStack_48 = (undefined *)0x0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  func_0x811182c0(auStack_80,&UNK_811380dc);
  uStack_44 = 0;
  puStack_48 = auStack_80;
  uVar1 = func_0x81117290(&uStack_70,&puStack_48,1,*(undefined4 *)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  if (_UNK_8111a5b0 == puStack_1c) {
    return _UNK_8111a5b0;
  }
  puVar2 = (undefined4 *)func_0x811185a0();
  puVar11 = &UNK_8111a5b0;
  uVar1 = 0;
  *puVar2 = &UNK_811470f4;
  func_0x810942ac(puVar2 + 1);
  puVar4 = puVar2 + 3;
  func_0x810cb5c8(puVar4,&UNK_811380d8);
  *(undefined *)(puVar2 + 10) = 0;
  puVar2[0xb] = 0;
  puVar2[0xc] = puVar2 + 0xd;
  *(undefined *)(puVar2 + 0xd) = uRam8114a6d4;
  *(undefined *)((int)puVar2 + 0x35) = uRam8114a6d5;
  *(undefined *)((int)puVar2 + 0x36) = uRam8114a6d6;
  *(undefined *)((int)puVar2 + 0x37) = uRam8114a6d7;
  *(undefined *)(puVar2 + 0xe) = uRam8114a6d8;
  *(undefined *)((int)puVar2 + 0x39) = uRam8114a6d9;
  *(undefined *)((int)puVar2 + 0x3a) = uRam8114a6da;
  *(undefined *)((int)puVar2 + 0x3b) = uRam8114a6db;
  *(undefined *)(puVar2 + 0xf) = uRam8114a6dc;
  *(undefined *)((int)puVar2 + 0x3d) = uRam8114a6dd;
  *(undefined *)((int)puVar2 + 0x3e) = uRam8114a6de;
  *(undefined *)((int)puVar2 + 0x3f) = uRam8114a6df;
  *(undefined *)(puVar2 + 0x10) = uRam8114a6e0;
  *(undefined *)((int)puVar2 + 0x41) = uRam8114a6e1;
  puVar9 = puVar2 + 4;
  *(undefined *)((int)puVar2 + 0x42) = uRam8114a6e2;
  *(undefined *)((int)puVar2 + 0x43) = uRam8114a6e3;
  uVar3 = puVar2[9];
  *puVar2 = &UNK_8114711c;
  puVar2[0x11] = 0xffffffff;
  puVar5 = puVar9;
  if (0xf < uVar3) {
    puVar5 = (undefined4 *)puVar2[4];
  }
  if (puVar5 < &UNK_811380f5) {
    puVar5 = puVar9;
    if (0xf < uVar3) {
      puVar5 = (undefined4 *)puVar2[4];
    }
    if (&UNK_811380f4 < (undefined *)(puVar2[8] + (int)puVar5)) {
      if (0xf < uVar3) {
        puVar9 = (undefined4 *)puVar2[4];
      }
      func_0x810c8628(puVar4,puVar4,(int)&UNK_811380f4 - (int)puVar9,0xe,uVar1,param_1,puVar10,
                      puVar11);
      return puVar2;
    }
  }
  if (uVar3 < 0xe) {
    iVar7 = puVar2[8];
    uVar8 = 0xf;
    uVar6 = uVar3 >> 1;
    if ((5 < uVar6) && (uVar8 = 0xfffffffe, uVar3 <= -uVar6 - 2)) {
      uVar8 = uVar3 + uVar6;
    }
    puVar5 = (undefined4 *)func_0x81005a98(uVar8 + 1);
    if (iVar7 != 0) {
      puVar4 = puVar9;
      if (0xf < (uint)puVar2[9]) {
        puVar4 = (undefined4 *)puVar2[4];
      }
      func_0x811182b0(puVar5,puVar4,iVar7);
    }
    if (0xf < (uint)puVar2[9]) {
      func_0x81005af0(puVar2[4]);
    }
    puVar2[8] = iVar7;
    *(undefined *)(puVar2 + 4) = 0;
    puVar2[4] = puVar5;
    puVar2[9] = uVar8;
    if (uVar8 < 0x10) {
      puVar5 = puVar9;
    }
    *(undefined *)(iVar7 + (int)puVar5) = 0;
    uVar3 = puVar2[9];
  }
  puVar5 = puVar9;
  if (0xf < uVar3) {
    puVar5 = (undefined4 *)puVar2[4];
  }
  func_0x811182b0(puVar5,&UNK_811380f4,0xe);
  puVar2[8] = 0xe;
  if (0xf < (uint)puVar2[9]) {
    puVar9 = (undefined4 *)puVar2[4];
  }
  *(undefined *)((int)puVar9 + 0xe) = 0;
  return puVar2;
}

