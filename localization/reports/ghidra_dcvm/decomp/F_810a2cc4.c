
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810a2cc4(undefined2 *param_1,int *param_2,int *param_3,undefined *param_4,
                 undefined4 param_5,undefined4 param_6,byte param_7)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined *puVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined auStack_90 [8];
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined uStack_80;
  int iStack_7c;
  int iStack_74;
  uint uStack_70;
  int *piStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined2 *puStack_60;
  undefined *puStack_5c;
  int *piStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  uint uStack_48;
  undefined uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  undefined auStack_38 [8];
  undefined4 uStack_30;
  byte bStack_2c;
  int iStack_28;
  
  iStack_28 = _UNK_8111a5b0;
  uStack_40 = 0;
  iStack_3c = 0;
  bStack_2c = param_7;
  piVar6 = *(int **)(**(int **)(*param_2 + 4) + 0x20);
  puVar9 = param_4;
  puVar2 = (uint *)(*(code *)piVar6)();
  uVar10 = *puVar2;
  iVar3 = 0x50;
  if (uVar10 == 0) {
LAB_810a2d56:
    iVar11 = iVar3;
    *param_1 = 0;
  }
  else {
    uStack_30 = 0;
    puVar9 = auStack_38;
    func_0x81080bb2(puVar9,param_5);
    uStack_50 = param_6;
    piVar6 = &iStack_3c;
    iVar3 = FUN_81079552(uVar10,&uStack_40,piVar6,puVar9);
    func_0x81005af0(uStack_30);
    iVar11 = iStack_3c;
    if (iVar3 == 0) goto LAB_810a2d56;
    uVar10 = (uint)bStack_2c;
    uStack_30 = 0;
    uStack_50 = uStack_40;
    iStack_4c = iStack_3c;
    piVar6 = param_3;
    puVar9 = param_4;
    uStack_48 = uVar10;
    func_0x810a1bc4(param_1,param_2,param_3,param_4);
  }
  if (_UNK_8111a5b0 == iStack_28) {
    return;
  }
  uVar12 = 0x810a2d77;
  uVar13 = func_0x811185a0();
  uVar1 = uStack_48;
  iVar3 = iStack_4c;
  piVar4 = (int *)((ulonglong)uVar13 >> 0x20);
  uStack_64 = param_5;
  uStack_68 = param_6;
  iStack_7c = _UNK_8111a5b0;
  uStack_98 = 0;
  uStack_94 = 0;
  uStack_80 = uStack_44;
  piVar7 = *(int **)(*piVar4 + 4);
  uStack_84 = uStack_50;
  iStack_74 = iVar11;
  uStack_70 = uVar10;
  piStack_6c = param_2;
  puStack_60 = param_1;
  puStack_5c = param_4;
  piStack_58 = param_3;
  uStack_54 = uVar12;
  piVar7 = (int *)(**(code **)(*piVar7 + 0x20))(piVar7);
  iVar11 = *piVar7;
  if (iVar11 != 0) {
    uStack_88 = 0;
    func_0x81080bb2(auStack_90,iVar3);
    iVar3 = FUN_81079552(iVar11,&uStack_98,&uStack_94,auStack_90,uVar1);
    func_0x81005af0(uStack_88);
    if (iVar3 != 0) {
      uStack_88 = 0;
      func_0x810a21f2((undefined2 *)uVar13,piVar4,piVar6,puVar9,uStack_84,uStack_98,uStack_94,
                      uStack_80);
      goto LAB_810a2e18;
    }
  }
  *(undefined2 *)uVar13 = 0;
LAB_810a2e18:
  if (_UNK_8111a5b0 == iStack_7c) {
    return;
  }
  uVar13 = func_0x811185a0();
  pcVar5 = (char *)((ulonglong)uVar13 >> 0x20);
  iVar3 = (int)uVar13;
  (**(code **)(*(int *)(iVar3 + 0x24) + 8))(iVar3 + 0x24);
  uVar10 = (uint)(byte)pcVar5[1];
  iVar11 = *(int *)(iVar3 + 0x24);
  if ((*pcVar5 == *(char *)(*(int *)(iVar3 + 0x18) + uVar10)) &&
     (iVar8 = uVar10 * 0x34 + *(int *)(iVar3 + 4), iVar8 != 0)) {
    *(undefined *)(iVar8 + 0x27) = 1;
  }
  (**(code **)(iVar11 + 0xc))(iVar3 + 0x24);
  return;
}

