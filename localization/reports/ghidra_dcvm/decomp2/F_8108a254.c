
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108a254(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int **ppiVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  int *piStack_88;
  int *piStack_84;
  int *piStack_80;
  int *piStack_7c;
  undefined4 uStack_78;
  int *piStack_74;
  undefined4 *puStack_6c;
  undefined *puStack_68;
  undefined4 uStack_48;
  int *piStack_44;
  int *piStack_40;
  undefined4 *puStack_3c;
  undefined *puStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int *piStack_28;
  undefined4 *puStack_24;
  undefined *puStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int *piStack_10;
  
  piStack_10 = _UNK_8111a5b0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 != &uStack_18) {
    FUN_8107db94(param_1);
    *param_1 = uStack_18;
    param_1[1] = uStack_14;
  }
  uStack_14 = 0;
  uStack_18 = 0;
  FUN_8107db94(&uStack_18);
  if (_UNK_8111a5b0 == piStack_10) {
    return;
  }
  uVar10 = 0x8108a29d;
  puVar2 = (undefined4 *)func_0x811185a0();
  puStack_20 = &UNK_8111a5b0;
  piStack_28 = _UNK_8111a5b0;
  uStack_30 = 0;
  uStack_2c = 0;
  puStack_24 = param_1;
  uStack_1c = uVar10;
  if (puVar2 != &uStack_30) {
    FUN_8107db94(puVar2);
    *puVar2 = uStack_30;
    puVar2[1] = uStack_2c;
  }
  uStack_2c = 0;
  uStack_30 = 0;
  FUN_8107db94(&uStack_30);
  FUN_8107db94(puVar2);
  if (_UNK_8111a5b0 == piStack_28) {
    return;
  }
  uVar10 = 0x8108a2ef;
  puVar3 = (undefined4 *)func_0x811185a0(puVar2);
  puStack_38 = &UNK_8111a5b0;
  piStack_40 = _UNK_8111a5b0;
  uStack_48 = 0;
  piStack_44 = (int *)0x0;
  puStack_3c = puVar2;
  uStack_34 = uVar10;
  if (puVar3 != &uStack_48) {
    FUN_8107db94(puVar3);
    *puVar3 = uStack_48;
    puVar3[1] = piStack_44;
  }
  piStack_44 = (int *)0x0;
  uStack_48 = 0;
  FUN_8107db94(&uStack_48);
  FUN_8107db94(puVar3);
  if (_UNK_8111a5b0 == piStack_40) {
    return;
  }
  piVar8 = piStack_40;
  uVar11 = func_0x811185a0(puVar3);
  piVar1 = piStack_44;
  ppiVar4 = (int **)uVar11;
  puStack_68 = &UNK_8111a5b0;
  piStack_74 = _UNK_8111a5b0;
  uStack_78 = uStack_48;
  piStack_80 = (int *)0x0;
  piStack_7c = (int *)0x0;
  puStack_6c = puVar3;
  if (ppiVar4 != &piStack_80) {
    FUN_8107db94(ppiVar4);
    *ppiVar4 = piStack_80;
    ppiVar4[1] = piStack_7c;
  }
  piStack_7c = (int *)0x0;
  piStack_80 = (int *)0x0;
  FUN_8107db94(&piStack_80);
  piVar9 = (int *)((int)((ulonglong)uVar11 >> 0x20) + 7U & 0xfffffff8);
  piVar5 = (int *)func_0x8108a7a0(uStack_78);
  uVar7 = (uint)((int)piVar8 * (int)param_4 * (int)piVar5) >> 3;
  if (uVar7 == 0) {
    uVar7 = 1;
  }
  piStack_84 = (int *)(**(code **)(*piVar1 + 0xc))(piVar1,uVar7,piVar1 + 9,piVar1[1]);
  piStack_88 = piVar1;
  if (ppiVar4 != &piStack_88) {
    FUN_8107db94(ppiVar4);
    *ppiVar4 = piStack_88;
    ppiVar4[1] = piStack_84;
    piStack_88 = (int *)0x0;
    piStack_84 = (int *)0x0;
  }
  FUN_8107db94(&piStack_88);
  iVar6 = func_0x81116c50(ppiVar4 + 2,uStack_78,0,0,(int *)0x3f < piVar5,piVar9,piVar8,param_4,
                          ppiVar4[1]);
  if (iVar6 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  ppiVar4[0xe] = piVar9;
  ppiVar4[0xf] = piVar8;
  ppiVar4[0x10] = piVar5;
  ppiVar4[0x11] = param_4;
  if (_UNK_8111a5b0 == piStack_74) {
    return;
  }
  puVar2 = (undefined4 *)func_0x811185a0();
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[3] = 0;
  puVar2[2] = 0;
  return;
}

