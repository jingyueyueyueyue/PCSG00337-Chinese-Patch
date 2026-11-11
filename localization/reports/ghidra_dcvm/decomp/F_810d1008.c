
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810d1008(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  undefined4 uVar11;
  short sStack_50;
  short sStack_4e;
  int iStack_4c;
  undefined4 *puStack_48;
  int *piStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  uint uStack_2c;
  int iStack_28;
  
  iStack_28 = _UNK_8111a5b0;
  iVar1 = func_0x8109473e(param_2,0);
  iVar7 = *(int *)(iVar1 + 4);
  iVar1 = func_0x8109473e(param_2,1);
  piStack_44 = piRam811ae680;
  pcVar6 = *(char **)(*(int *)(param_1 + 0x14) + 0x24);
  iVar1 = *(int *)(iVar1 + 4);
  uVar5 = *(uint *)(pcVar6 + iVar7 * 8 + 0x10);
  uVar8 = *(uint *)(pcVar6 + 4);
  if (*pcVar6 == '\x12') {
    uVar5 = uVar5 >> 0x18 | (uVar5 >> 0x10 & 0xff) << 8 | (uVar5 >> 8 & 0xff) << 0x10 |
            uVar5 << 0x18;
    uVar8 = uVar8 >> 0x18 | (uVar8 >> 0x10 & 0xff) << 8 | (uVar8 >> 8 & 0xff) << 0x10 |
            uVar8 << 0x18;
  }
  uVar4 = uVar8;
  if (uVar8 == 0) {
    uVar4 = 1;
  }
  uStack_40 = (**(code **)(*piRam811ae680 + 0xc))
                        (piRam811ae680,uVar4,piRam811ae680 + 9,piRam811ae680[1]);
  iVar7 = 0;
  if (iRam811ae688 != 0) {
    iVar7 = iRam811ae688 + 4;
  }
  uVar9 = **(undefined4 **)(*(int *)(iVar7 + 0x10) + 0x1c);
  piVar2 = (int *)func_0x810a15ac(uVar9);
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x20))();
  iVar7 = FUN_810795bc(*puVar3,&iStack_4c,&puStack_48,&UNK_8113a9e4,0x81191264);
  if (iVar7 == 0) {
    func_0x8107db94(&piStack_44);
  }
  else {
    uStack_34 = *puStack_48;
    iVar7 = puStack_48[1];
    uVar11 = *(undefined4 *)(iStack_4c + 0x20);
    uVar4 = puStack_48[2];
    iStack_30 = iVar7;
    iStack_30 = func_0x810c8324((iVar1 + uVar5) * uVar8,uVar11);
    iStack_30 = iStack_30 + iVar7;
    iVar1 = func_0x810c8324(uVar8,uVar11);
    sStack_50 = 0;
    uStack_3c = 1;
    uStack_38 = 0;
    uStack_2c = uVar4 & 0x80000000 | iVar1 - 1U & 0xfffffff;
    do {
      func_0x810a1e48(&sStack_4e,uVar9,&uStack_3c,uStack_40,iStack_4c,&uStack_34,0,1);
      sStack_50 = sStack_4e;
    } while (sStack_4e == 0);
    while (iVar1 = func_0x810a2916(uVar9,&sStack_50), iVar1 != 0) {
      func_0x8108cfd4(10);
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
    puVar10 = *(uint **)(iVar1 + 0x3c);
    uVar9 = *(undefined4 *)(iVar1 + 0x34);
    func_0x8108d644(puVar10,0x294);
    *puVar10 = uVar8;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    func_0x8108d65a(uVar9,uStack_40,uVar8);
    *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(iVar1 + 0x34);
    func_0x8107db94(&piStack_44);
  }
  if (_UNK_8111a5b0 != iStack_28) {
    puVar3 = (undefined4 *)func_0x811185a0();
    *puVar3 = &UNK_8113a8f8;
    func_0x81009478(puVar3);
    func_0x81005af0(puVar3);
    return;
  }
  return;
}

