
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810a1a0e(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  undefined8 uVar11;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined auStack_38 [8];
  undefined4 uStack_30;
  int iStack_2c;
  
  iStack_2c = _UNK_8111a5b0;
  uStack_40 = 0;
  uStack_3c = 0;
  piVar1 = (int *)(**(code **)(**(int **)(*param_1 + 4) + 0x20))();
  iVar7 = *piVar1;
  if (iVar7 != 0) {
    uStack_30 = 0;
    func_0x81080bb2(auStack_38,param_2);
    iVar7 = FUN_81079552(iVar7,&uStack_40,&uStack_3c,auStack_38,param_3);
    func_0x81005af0(uStack_30);
    if (iVar7 != 0) {
      uStack_30 = 0;
      uVar2 = func_0x810a1800(param_1,uStack_40,uStack_3c,param_4,param_5);
      goto LAB_810a1a9c;
    }
  }
  uVar2 = 2;
LAB_810a1a9c:
  if (_UNK_8111a5b0 == iStack_2c) {
    return;
  }
  uVar11 = func_0x811185a0(uVar2);
  iVar3 = (int)((ulonglong)uVar11 >> 0x20);
  iVar7 = (int)uVar11;
  puVar5 = *(undefined4 **)(iVar3 + 0x30);
  iVar10 = *(int *)(iVar7 + 0x24);
  if (puVar5 != (undefined4 *)0x0) {
    *puVar5 = *(undefined4 *)(iVar3 + 0x28);
    puVar5[1] = *(undefined4 *)(iVar3 + 0x2c);
  }
  (**(code **)(iVar10 + 8))(iVar7 + 0x24);
  iVar3 = iVar3 - *(int *)(iVar7 + 4);
  iVar3 = (int)((longlong)_DAT_810a1b08 * (longlong)iVar3 >> 0x24) - (iVar3 >> 0x1f);
  if ((iVar3 < 0) || (*(int *)(iVar7 + 0x10) <= iVar3)) {
    cVar9 = '\0';
    bVar4 = 0;
  }
  else {
    bVar4 = (byte)iVar3;
    cVar9 = *(char *)(*(int *)(iVar7 + 0x18) + iVar3);
  }
  uVar8 = (uint)bVar4;
  if ((cVar9 == *(char *)(*(int *)(iVar7 + 0x18) + uVar8)) &&
     (puVar6 = (undefined4 *)(uVar8 * 0x34 + *(int *)(iVar7 + 4)), puVar5 = puVar6,
     puVar6 != (undefined4 *)0x0)) {
    do {
      puVar5[6] = 0;
      puVar5[7] = 1;
      if (puVar5[4] == 0) {
        func_0x81005b02(puVar5[2]);
      }
      puVar5[3] = 0;
      puVar5[4] = 1;
      puVar5[2] = 0;
      puVar5[5] = uRam81191264;
      puVar5[6] = 0;
      puVar5[1] = 0;
      *(undefined *)((int)puVar5 + 0x27) = 0;
      puVar5[7] = 1;
      puVar5[3] = 0;
      puVar5[4] = 1;
      puVar5[2] = 0;
      uVar2 = uRam81191264;
      puVar5[3] = 0;
      puVar5[4] = 1;
      puVar5[2] = 0;
      puVar5[0xc] = 0;
      *(undefined *)((int)puVar5 + 0x25) = 0;
      *(undefined *)((int)puVar5 + 0x26) = 0;
      puVar5[8] = 0;
      *(undefined *)(puVar5 + 9) = 0;
      puVar5[5] = uVar2;
      puVar5[5] = uRam81191264;
      puVar5 = puVar5 + -0xd;
    } while (puVar6 <= puVar5);
    iVar3 = *(int *)(iVar7 + 0x18);
    if (*(char *)(iVar3 + uVar8) == -1) {
      *(undefined *)(iVar3 + uVar8) = 1;
    }
    else {
      *(char *)(iVar3 + uVar8) = *(char *)(iVar3 + uVar8) + '\x01';
    }
    *puVar6 = *(undefined4 *)(iVar7 + 0xc);
    *(undefined4 **)(iVar7 + 0xc) = puVar6;
    *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;
  }
  (**(code **)(*(int *)(iVar7 + 0x24) + 0xc))(iVar7 + 0x24);
  return;
}

