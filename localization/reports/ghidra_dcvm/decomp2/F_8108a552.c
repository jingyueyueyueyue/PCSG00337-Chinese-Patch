
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108a552(int **param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int **ppiVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int **ppiVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  int *piStack_70;
  int *piStack_6c;
  int *piStack_68;
  int *piStack_64;
  int *piStack_60;
  int *piStack_5c;
  int iStack_58;
  int *piStack_54;
  int *piStack_50;
  int *piStack_4c;
  int *piStack_48;
  int **ppiStack_44;
  int **ppiStack_40;
  int **ppiStack_3c;
  undefined *puStack_38;
  int *piStack_20;
  int *piStack_1c;
  int *piStack_18;
  
  piStack_18 = _UNK_8111a5b0;
  piStack_20 = (int *)0x0;
  piStack_1c = (int *)0x0;
  ppiVar7 = param_1 + 2;
  if (param_1 != &piStack_20) {
    FUN_8107db94(param_1);
    *param_1 = piStack_20;
    param_1[1] = piStack_1c;
  }
  piStack_1c = (int *)0x0;
  piStack_20 = (int *)0x0;
  FUN_8107db94(&piStack_20);
  piStack_20 = (int *)0x0;
  piStack_1c = (int *)0x0;
  if (ppiVar7 != &piStack_20) {
    FUN_8107db94(ppiVar7);
    param_1[2] = piStack_20;
    param_1[3] = piStack_1c;
  }
  piStack_1c = (int *)0x0;
  piStack_20 = (int *)0x0;
  FUN_8107db94(&piStack_20);
  FUN_8107db94(ppiVar7);
  FUN_8107db94(param_1);
  if (_UNK_8111a5b0 == piStack_18) {
    return;
  }
  piVar6 = piStack_18;
  uVar10 = func_0x811185a0(param_1);
  piVar1 = piStack_20;
  piVar4 = (int *)((ulonglong)uVar10 >> 0x20);
  ppiVar2 = (int **)uVar10;
  puStack_38 = &UNK_8111a5b0;
  piStack_48 = _UNK_8111a5b0;
  piStack_60 = (int *)0x0;
  piStack_5c = (int *)0x0;
  ppiStack_44 = param_1;
  ppiStack_40 = ppiVar7;
  ppiStack_3c = &piStack_20;
  if (ppiVar2 != &piStack_60) {
    ppiStack_3c = &piStack_20;
    FUN_8107db94(ppiVar2);
    *ppiVar2 = piStack_60;
    ppiVar2[1] = piStack_5c;
  }
  piStack_5c = (int *)0x0;
  piStack_60 = (int *)0x0;
  FUN_8107db94(&piStack_60);
  piStack_60 = (int *)0x0;
  piStack_5c = (int *)0x0;
  ppiVar7 = ppiVar2 + 2;
  if (ppiVar7 != &piStack_60) {
    FUN_8107db94(ppiVar7);
    ppiVar2[2] = piStack_60;
    ppiVar2[3] = piStack_5c;
  }
  piStack_5c = (int *)0x0;
  piStack_60 = (int *)0x0;
  piStack_50 = piVar6;
  piStack_4c = piVar4;
  FUN_8107db94(&piStack_60);
  piStack_54 = (int *)((int)piVar4 + 0x1fU & 0xffffffe0);
  iVar3 = ((int)piVar6 + 0x1fU & 0xffffffe0) * (int)piStack_54;
  if (param_4 == 0x2444000) {
    iVar9 = 2;
    iVar8 = 0;
LAB_8108a6c4:
    iVar5 = iVar9 * iVar3;
    if (iVar5 == 0) {
      iVar5 = 1;
    }
    iStack_58 = iVar3;
    piStack_6c = (int *)(**(code **)(*piVar1 + 0xc))(piVar1,iVar5,piVar1 + 9,piVar1[1]);
    piStack_70 = piVar1;
    if (ppiVar2 != &piStack_70) {
      FUN_8107db94(ppiVar2);
      *ppiVar2 = piStack_70;
      ppiVar2[1] = piStack_6c;
      piStack_70 = (int *)0x0;
      piStack_6c = (int *)0x0;
    }
    FUN_8107db94(&piStack_70);
    if (iVar8 == 0) goto LAB_8108a748;
  }
  else {
    if (param_4 == 0x1266000) {
      iVar9 = 4;
      iVar8 = 0;
      goto LAB_8108a6c4;
    }
    if (param_4 == 0xee000) {
LAB_8108a6ae:
      iVar9 = 4;
      iVar8 = 1;
      goto LAB_8108a6c4;
    }
    if (param_4 == 0xcc000) {
LAB_8108a69c:
      iVar9 = 4;
      iVar8 = 0;
      goto LAB_8108a6c4;
    }
    if (param_4 == 0x66000) goto LAB_8108a6ae;
    if (param_4 == 0x44000) goto LAB_8108a69c;
    iVar8 = 0;
    iVar9 = 0;
    if (param_4 != 0x22000) goto LAB_8108a748;
    iVar8 = 1;
    iVar9 = 0;
    iStack_58 = iVar3;
  }
  iVar3 = iStack_58 * iVar8;
  if (iVar3 == 0) {
    iVar3 = 1;
  }
  piStack_64 = (int *)(**(code **)(*piVar1 + 0xc))(piVar1,iVar3,piVar1 + 9,piVar1[1]);
  piStack_68 = piVar1;
  if (ppiVar7 != &piStack_68) {
    FUN_8107db94(ppiVar7);
    ppiVar2[2] = piStack_68;
    ppiVar2[3] = piStack_64;
    piStack_68 = (int *)0x0;
    piStack_64 = (int *)0x0;
  }
  FUN_8107db94(&piStack_68);
LAB_8108a748:
  iVar3 = func_0x81116b90(ppiVar2 + 4,param_4,0x11000,piStack_54,ppiVar2[1],ppiVar2[3]);
  if (iVar3 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  ppiVar2[9] = piStack_4c;
  ppiVar2[10] = piStack_50;
  ppiVar2[0xb] = (int *)((iVar9 + iVar8) * 8);
  ppiVar2[0xc] = piStack_54;
  if (_UNK_8111a5b0 != piStack_48) {
    func_0x811185a0();
    return;
  }
  return;
}

