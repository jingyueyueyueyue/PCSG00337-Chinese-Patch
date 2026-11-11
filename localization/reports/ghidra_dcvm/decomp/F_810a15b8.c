
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810a15b8(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined *param_4,
                 undefined4 param_5)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  int iVar7;
  undefined *unaff_r9;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined auStack_68 [8];
  undefined4 uStack_60;
  undefined4 *puStack_5c;
  undefined *puStack_58;
  undefined4 *puStack_54;
  undefined4 *puStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined *puStack_44;
  undefined *puStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined auStack_30 [8];
  undefined4 uStack_28;
  undefined4 *puStack_24;
  
  puStack_24 = _UNK_8111a5b0;
  *param_2 = 0;
  *param_3 = 0;
  puVar6 = param_4;
  piVar1 = (int *)(**(code **)(**(int **)(*param_1 + 4) + 0x20))();
  iVar7 = *piVar1;
  if (iVar7 == 0) {
    puVar2 = (undefined *)0x0;
    puStack_58 = param_4;
  }
  else {
    uStack_28 = 0;
    unaff_r9 = auStack_30;
    func_0x81080bb2(unaff_r9,param_4);
    uStack_38 = param_5;
    puVar6 = unaff_r9;
    puVar2 = (undefined *)FUN_81079552(iVar7,param_2,param_3);
    func_0x81005af0(uStack_28);
    puStack_58 = puVar2;
  }
  if (_UNK_8111a5b0 == puStack_24) {
    return;
  }
  uVar8 = 0x810a162f;
  puVar5 = puStack_24;
  uVar9 = func_0x811185a0(puVar2);
  uVar3 = uStack_38;
  puVar4 = (undefined4 *)((ulonglong)uVar9 >> 0x20);
  puStack_40 = &UNK_8111a5b0;
  uStack_48 = param_5;
  puStack_5c = _UNK_8111a5b0;
  *puVar4 = 0;
  piVar1 = *(int **)(*(int *)uVar9 + 4);
  *puVar5 = 0;
  puStack_54 = param_3;
  puStack_50 = param_2;
  iStack_4c = iVar7;
  puStack_44 = unaff_r9;
  uStack_3c = uVar8;
  piVar1 = (int *)(**(code **)(*piVar1 + 0x20))();
  iVar7 = *piVar1;
  if (iVar7 == 0) {
    uVar3 = 0;
  }
  else {
    uStack_60 = 0;
    func_0x81080bb2(auStack_68,puVar6);
    uVar3 = FUN_81078eaa(iVar7,puVar4,puVar5,auStack_68,uVar3);
    func_0x81005af0(uStack_60);
  }
  if (_UNK_8111a5b0 == puStack_5c) {
    return;
  }
  puVar5 = puStack_5c;
  uVar9 = func_0x811185a0(uVar3);
  iVar7 = (int)uVar9;
  (**(code **)(*(int *)(iVar7 + 0x14) + 8))(iVar7 + 0x14);
  func_0x8107e03a(iVar7,(int)((ulonglong)uVar9 >> 0x20),((uint)puVar5 & 0xff) + 1);
  (**(code **)(*(int *)(iVar7 + 0x14) + 0xc))(iVar7 + 0x14);
  return;
}

