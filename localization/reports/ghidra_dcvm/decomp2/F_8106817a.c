
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106817a(void)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  undefined *puVar4;
  undefined4 in_r3;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined *puVar11;
  undefined auStack_50 [4];
  int iStack_4c;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined auStack_40 [4];
  int iStack_3c;
  undefined *puStack_38;
  undefined4 uStack_34;
  undefined auStack_30 [4];
  int iStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined auStack_20 [4];
  int iStack_1c;
  undefined *puStack_18;
  undefined4 uStack_14;
  undefined auStack_10 [4];
  int iStack_c;
  
  iStack_c = _UNK_8111a5b0;
  func_0x81067ddc(auStack_10,&UNK_81136f00,0xffffffff);
  if (_UNK_8111a5b0 == iStack_c) {
    return;
  }
  uVar9 = 0x810681ad;
  func_0x811185a0();
  puStack_18 = &UNK_8111a5b0;
  iStack_1c = _UNK_8111a5b0;
  uStack_14 = uVar9;
  func_0x81067ddc(auStack_20,&UNK_81136ecc,0xffffffff);
  if (_UNK_8111a5b0 == iStack_1c) {
    return;
  }
  uVar9 = 0x810681e1;
  func_0x811185a0();
  puStack_28 = &UNK_8111a5b0;
  iStack_2c = _UNK_8111a5b0;
  uStack_24 = uVar9;
  func_0x81067ddc(auStack_30,&UNK_81136ecc,0xffffffff);
  if (_UNK_8111a5b0 == iStack_2c) {
    return;
  }
  uVar9 = 0x81068215;
  func_0x811185a0();
  puStack_38 = &UNK_8111a5b0;
  iStack_3c = _UNK_8111a5b0;
  uStack_34 = uVar9;
  func_0x81067ddc(auStack_40,&UNK_81136ecc,0xffffffff);
  if (_UNK_8111a5b0 != iStack_3c) {
    uVar9 = 0x81068249;
    func_0x811185a0();
    puStack_48 = &UNK_8111a5b0;
    iStack_4c = _UNK_8111a5b0;
    uStack_44 = uVar9;
    func_0x81067ddc(auStack_50,&UNK_81136ecc,0xffffffff);
    if (_UNK_8111a5b0 != iStack_4c) {
      uVar10 = func_0x811185a0();
      pcVar2 = (char *)((ulonglong)uVar10 >> 0x20);
      iVar1 = (int)uVar10;
      puVar11 = &UNK_8111a5b0;
      if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
        *(undefined *)(iVar1 + 4) = 0;
        *(undefined4 *)(iVar1 + 0x14) = 0;
        *(undefined4 *)(iVar1 + 0x18) = 0xf;
        puVar5 = (undefined *)(iVar1 + 4);
        if ((&UNK_81136f14 < puVar5) || (uVar3 = 0, puVar5 < &UNK_81136f15)) {
          *(undefined4 *)(iVar1 + 0x14) = 0;
          *(undefined *)(iVar1 + 4) = 0;
        }
        else {
          uVar8 = (int)&UNK_81136f14 - (int)puVar5;
          if (uVar8 != 0) {
            func_0x811184c0(&UNK_81138ebc);
            uVar3 = *(uint *)(iVar1 + 0x14);
          }
          iVar6 = uVar3 - uVar8;
          if (iVar6 != 0) {
            iVar6 = 0;
          }
          uVar7 = iVar6 + uVar8;
          if (uVar3 < uVar7) {
            func_0x811184c0(&UNK_81138ebc);
          }
          *(uint *)(iVar1 + 0x14) = uVar7;
          puVar4 = puVar5;
          if (0xf < *(uint *)(iVar1 + 0x18)) {
            puVar4 = *(undefined **)(iVar1 + 4);
          }
          puVar4[uVar7] = 0;
          if (uVar8 < *(uint *)(iVar1 + 0x14)) {
            if (uVar8 != 0) {
              uVar3 = *(uint *)(iVar1 + 0x18);
              puVar4 = puVar5;
              if (0xf < uVar3) {
                puVar4 = *(undefined **)(iVar1 + 4);
              }
              iVar6 = *(uint *)(iVar1 + 0x14) - uVar8;
              if (iVar6 != 0) {
                func_0x811183a0(puVar4,puVar4 + uVar8,iVar6,in_r3,puVar11);
                uVar3 = *(uint *)(iVar1 + 0x18);
              }
              *(int *)(iVar1 + 0x14) = iVar6;
              if (0xf < uVar3) {
                puVar5 = *(undefined **)(iVar1 + 4);
              }
              puVar5[iVar6] = 0;
            }
          }
          else {
            *(undefined4 *)(iVar1 + 0x14) = 0;
            if (0xf < *(uint *)(iVar1 + 0x18)) {
              puVar5 = *(undefined **)(iVar1 + 4);
            }
            *puVar5 = 0;
          }
        }
      }
      else {
        iVar6 = func_0x8106037e(uRam811ae688);
        func_0x81065f82(iVar1,*(int *)(*(int *)(*(int *)(iVar6 + 0x24) + 0x178) + 8) + 4,pcVar2);
      }
      return;
    }
    return;
  }
  return;
}

