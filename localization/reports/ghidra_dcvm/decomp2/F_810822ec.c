
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810822ec(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  char extraout_r1;
  int iVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int **ppiVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  undefined4 uStack_78;
  undefined4 uStack_74;
  uint uStack_70;
  code *pcStack_68;
  int *piStack_64;
  int *piStack_60;
  int **ppiStack_5c;
  undefined *puStack_58;
  undefined4 uStack_54;
  int *piStack_50;
  int *piStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  int *piStack_38;
  undefined4 *puStack_34;
  undefined *puStack_30;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  
  uStack_18 = _UNK_8111a5b0;
  puVar7 = (undefined4 *)*param_1;
  uStack_20 = 0;
  uStack_1c = 0;
  if (puVar7 != &uStack_20) {
    FUN_8107db94(puVar7);
    puVar7[1] = uStack_1c;
    *puVar7 = uStack_20;
  }
  uStack_1c = 0;
  uStack_20 = 0;
  FUN_8107db94(&uStack_20);
  param_1[2] = 0;
  if (_UNK_8111a5b0 == uStack_18) {
    return;
  }
  piVar1 = (int *)func_0x811185a0();
  puStack_30 = &UNK_8111a5b0;
  uStack_40 = _UNK_8111a5b0;
  puVar9 = (undefined4 *)*piVar1;
  uStack_48 = 0;
  uStack_44 = 0;
  piStack_38 = param_1;
  puStack_34 = puVar7;
  if (puVar9 != &uStack_48) {
    FUN_8107db94(puVar9);
    puVar9[1] = uStack_44;
    *puVar9 = uStack_48;
  }
  uStack_44 = 0;
  uStack_48 = 0;
  FUN_8107db94(&uStack_48);
  ppiVar10 = (int **)*piVar1;
  piVar1[2] = 0;
  if (param_3 == 0) {
    param_3 = -0x7ee6ee0c;
  }
  *(byte *)(piVar1 + 3) = *(byte *)(piVar1 + 3) & 0xfe | 2 | extraout_r1 != '\0';
  piVar8 = *(int **)(param_3 + 4);
  iVar3 = 0x10;
  pcVar6 = *(code **)(*piVar8 + 0xc);
  if (extraout_r1 != '\0') {
    iVar3 = 0x100;
  }
  iVar4 = iVar3 << 2;
  if (iVar3 == 0) {
    iVar4 = 1;
  }
  piStack_4c = (int *)(*pcVar6)(piVar8,iVar4,piVar8 + 9,piVar8[1]);
  piStack_50 = piVar8;
  if (ppiVar10 != &piStack_50) {
    FUN_8107db94(ppiVar10);
    ppiVar10[1] = piStack_4c;
    *ppiVar10 = piStack_50;
    piStack_50 = (int *)0x0;
    piStack_4c = (int *)0x0;
  }
  FUN_8107db94(&piStack_50);
  iVar3 = *(int *)(*piVar1 + 4);
  if (iVar3 != 0) {
    piVar1[2] = iVar3;
    piVar1[1] = (int)&UNK_811378e4;
  }
  if (_UNK_8111a5b0 == uStack_40) {
    return;
  }
  uVar11 = 0x81082427;
  uVar5 = uStack_40;
  uVar12 = func_0x811185a0(iVar3 != 0);
  puVar7 = (undefined4 *)((ulonglong)uVar12 >> 0x20);
  piVar2 = (int *)uVar12;
  puStack_58 = &UNK_8111a5b0;
  uStack_70 = _UNK_8111a5b0;
  puVar9 = (undefined4 *)*piVar2;
  uStack_78 = 0;
  uStack_74 = 0;
  pcStack_68 = pcVar6;
  piStack_64 = piVar1;
  piStack_60 = piVar8;
  ppiStack_5c = ppiVar10;
  uStack_54 = uVar11;
  if (puVar9 != &uStack_78) {
    FUN_8107db94(puVar9);
    puVar9[1] = uStack_74;
    *puVar9 = uStack_78;
  }
  uStack_74 = 0;
  uStack_78 = 0;
  FUN_8107db94(&uStack_78);
  puVar9 = (undefined4 *)*piVar2;
  piVar2[2] = 0;
  *(byte *)(piVar2 + 3) = *(byte *)(piVar2 + 3) & 0xfe | 2 | (uVar5 & 0xff) != 0;
  if (puVar9 != puVar7) {
    FUN_8107db94(puVar9);
    puVar9[1] = puVar7[1];
    *puVar9 = *puVar7;
    *puVar7 = 0;
    puVar7[1] = 0;
    puVar9 = (undefined4 *)*piVar2;
  }
  iVar3 = puVar9[1];
  if (iVar3 != 0) {
    piVar2[2] = iVar3;
    piVar2[1] = (int)&UNK_811378e4;
  }
  if (_UNK_8111a5b0 == uStack_70) {
    return;
  }
  func_0x811185a0(iVar3 != 0);
  return;
}

