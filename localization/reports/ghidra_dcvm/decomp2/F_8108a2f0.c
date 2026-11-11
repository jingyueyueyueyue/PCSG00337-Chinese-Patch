
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108a2f0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int **ppiVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  undefined8 uVar9;
  int *piStack_58;
  int *piStack_54;
  int *piStack_50;
  int *piStack_4c;
  undefined4 uStack_48;
  int *piStack_44;
  undefined4 *puStack_3c;
  undefined *puStack_38;
  undefined4 uStack_18;
  int *piStack_14;
  int *piStack_10;
  
  piStack_10 = _UNK_8111a5b0;
  uStack_18 = 0;
  piStack_14 = (int *)0x0;
  if (param_1 != &uStack_18) {
    FUN_8107db94(param_1);
    *param_1 = uStack_18;
    param_1[1] = piStack_14;
  }
  piStack_14 = (int *)0x0;
  uStack_18 = 0;
  FUN_8107db94(&uStack_18);
  FUN_8107db94(param_1);
  if (_UNK_8111a5b0 == piStack_10) {
    return;
  }
  piVar7 = piStack_10;
  uVar9 = func_0x811185a0(param_1);
  piVar1 = piStack_14;
  ppiVar2 = (int **)uVar9;
  puStack_38 = &UNK_8111a5b0;
  piStack_44 = _UNK_8111a5b0;
  uStack_48 = uStack_18;
  piStack_50 = (int *)0x0;
  piStack_4c = (int *)0x0;
  puStack_3c = param_1;
  if (ppiVar2 != &piStack_50) {
    FUN_8107db94(ppiVar2);
    *ppiVar2 = piStack_50;
    ppiVar2[1] = piStack_4c;
  }
  piStack_4c = (int *)0x0;
  piStack_50 = (int *)0x0;
  FUN_8107db94(&piStack_50);
  piVar8 = (int *)((int)((ulonglong)uVar9 >> 0x20) + 7U & 0xfffffff8);
  piVar3 = (int *)func_0x8108a7a0(uStack_48);
  uVar6 = (uint)((int)piVar7 * (int)param_4 * (int)piVar3) >> 3;
  if (uVar6 == 0) {
    uVar6 = 1;
  }
  piStack_54 = (int *)(**(code **)(*piVar1 + 0xc))(piVar1,uVar6,piVar1 + 9,piVar1[1]);
  piStack_58 = piVar1;
  if (ppiVar2 != &piStack_58) {
    FUN_8107db94(ppiVar2);
    *ppiVar2 = piStack_58;
    ppiVar2[1] = piStack_54;
    piStack_58 = (int *)0x0;
    piStack_54 = (int *)0x0;
  }
  FUN_8107db94(&piStack_58);
  iVar4 = func_0x81116c50(ppiVar2 + 2,uStack_48,0,0,(int *)0x3f < piVar3,piVar8,piVar7,param_4,
                          ppiVar2[1]);
  if (iVar4 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  ppiVar2[0xe] = piVar8;
  ppiVar2[0xf] = piVar7;
  ppiVar2[0x10] = piVar3;
  ppiVar2[0x11] = param_4;
  if (_UNK_8111a5b0 == piStack_44) {
    return;
  }
  puVar5 = (undefined4 *)func_0x811185a0();
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[3] = 0;
  puVar5[2] = 0;
  return;
}

