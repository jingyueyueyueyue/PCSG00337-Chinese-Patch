
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108a29e(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int **ppiVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  int *piStack_70;
  int *piStack_6c;
  int *piStack_68;
  int *piStack_64;
  undefined4 uStack_60;
  int *piStack_5c;
  undefined4 *puStack_54;
  undefined *puStack_50;
  undefined4 uStack_30;
  int *piStack_2c;
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
  FUN_8107db94(param_1);
  if (_UNK_8111a5b0 == piStack_10) {
    return;
  }
  uVar9 = 0x8108a2ef;
  puVar2 = (undefined4 *)func_0x811185a0(param_1);
  puStack_20 = &UNK_8111a5b0;
  piStack_28 = _UNK_8111a5b0;
  uStack_30 = 0;
  piStack_2c = (int *)0x0;
  puStack_24 = param_1;
  uStack_1c = uVar9;
  if (puVar2 != &uStack_30) {
    FUN_8107db94(puVar2);
    *puVar2 = uStack_30;
    puVar2[1] = piStack_2c;
  }
  piStack_2c = (int *)0x0;
  uStack_30 = 0;
  FUN_8107db94(&uStack_30);
  FUN_8107db94(puVar2);
  if (_UNK_8111a5b0 == piStack_28) {
    return;
  }
  piVar7 = piStack_28;
  uVar10 = func_0x811185a0(puVar2);
  piVar1 = piStack_2c;
  ppiVar3 = (int **)uVar10;
  puStack_50 = &UNK_8111a5b0;
  piStack_5c = _UNK_8111a5b0;
  uStack_60 = uStack_30;
  piStack_68 = (int *)0x0;
  piStack_64 = (int *)0x0;
  puStack_54 = puVar2;
  if (ppiVar3 != &piStack_68) {
    FUN_8107db94(ppiVar3);
    *ppiVar3 = piStack_68;
    ppiVar3[1] = piStack_64;
  }
  piStack_64 = (int *)0x0;
  piStack_68 = (int *)0x0;
  FUN_8107db94(&piStack_68);
  piVar8 = (int *)((int)((ulonglong)uVar10 >> 0x20) + 7U & 0xfffffff8);
  piVar4 = (int *)func_0x8108a7a0(uStack_60);
  uVar6 = (uint)((int)piVar7 * (int)param_4 * (int)piVar4) >> 3;
  if (uVar6 == 0) {
    uVar6 = 1;
  }
  piStack_6c = (int *)(**(code **)(*piVar1 + 0xc))(piVar1,uVar6,piVar1 + 9,piVar1[1]);
  piStack_70 = piVar1;
  if (ppiVar3 != &piStack_70) {
    FUN_8107db94(ppiVar3);
    *ppiVar3 = piStack_70;
    ppiVar3[1] = piStack_6c;
    piStack_70 = (int *)0x0;
    piStack_6c = (int *)0x0;
  }
  FUN_8107db94(&piStack_70);
  iVar5 = func_0x81116c50(ppiVar3 + 2,uStack_60,0,0,(int *)0x3f < piVar4,piVar8,piVar7,param_4,
                          ppiVar3[1]);
  if (iVar5 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  ppiVar3[0xe] = piVar8;
  ppiVar3[0xf] = piVar7;
  ppiVar3[0x10] = piVar4;
  ppiVar3[0x11] = param_4;
  if (_UNK_8111a5b0 == piStack_5c) {
    return;
  }
  puVar2 = (undefined4 *)func_0x811185a0();
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[3] = 0;
  puVar2[2] = 0;
  return;
}

