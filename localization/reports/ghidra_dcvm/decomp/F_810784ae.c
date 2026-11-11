
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_810784ae(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  int iStack_28;
  
  iStack_28 = _UNK_8111a5b0;
  if (*(int *)(param_1 + 0x40) == 0) {
    iVar4 = -1;
  }
  else {
    uStack_44 = 0;
    iVar4 = -1;
    func_0x81080caa(&uStack_44);
    iStack_48 = func_0x81080f92(&uStack_44);
    iStack_2c = func_0x81080f96(&uStack_44);
    iVar12 = 0;
    iVar11 = *(int *)(param_1 + 0x2c);
    if (*(int *)(param_1 + 0x3c) == 0) {
      iVar12 = -1;
    }
    piVar8 = (int *)0x0;
    if (-1 < iVar12) {
      piVar8 = (int *)(*(int *)(param_1 + 0x3c) + iVar12 * 0x10);
    }
    iVar12 = *piVar8;
    cVar3 = *(char *)(iVar11 + iVar12);
    if ((cVar3 != '.') && (cVar3 != '\0')) {
      uVar5 = func_0x81080fc8(&iStack_48);
      iVar11 = func_0x811181a0(iVar11 + iVar12,uVar5);
      if (iVar11 != 0) {
        func_0x81005af0(uStack_44);
        iVar4 = -1;
        goto LAB_810785f0;
      }
      func_0x81080f9a(&iStack_48);
    }
    while (iStack_48 != iStack_2c) {
      if (piVar8 == (int *)0x0) goto LAB_810785e8;
      uVar5 = func_0x81080fc8(&iStack_48);
      uVar1 = *(ushort *)(piVar8 + 2);
      uVar2 = *(ushort *)(piVar8 + 1);
      if (uVar1 != 0) {
        uVar13 = 0;
        do {
          uVar6 = (uint)uVar2;
          if (*(int *)(param_1 + 0x3c) == 0) {
            uVar6 = 0xffffffff;
          }
          piVar8 = (int *)0x0;
          if (-1 < (int)uVar6) {
            piVar8 = (int *)(*(int *)(param_1 + 0x3c) + uVar6 * 0x10);
          }
          iVar11 = func_0x811181a0(uVar5,*(int *)(param_1 + 0x2c) + *piVar8);
          if (iVar11 == 0) goto LAB_8107858c;
          uVar13 = uVar13 + 1;
          uVar2 = *(ushort *)((int)piVar8 + 6);
        } while (uVar13 < uVar1);
      }
      piVar8 = (int *)0x0;
LAB_8107858c:
      func_0x81080f9a(&iStack_48);
    }
    if (piVar8 != (int *)0x0) {
      uVar1 = *(ushort *)(piVar8 + 3);
      iVar11 = *(int *)(param_1 + 0x38);
      uStack_38 = uStack_40;
      uStack_34 = func_0x81080acc(uStack_40);
      uStack_30 = *(undefined4 *)(param_1 + 0x2c);
      iVar11 = func_0x81118400(&uStack_38,iVar11 + (uint)uVar1 * 0xc,
                               *(undefined2 *)((int)piVar8 + 0xe),0xc,&UNK_810789fb);
      if (iVar11 != 0) {
        iVar4 = (iVar11 - *(int *)(param_1 + 0x38)) / 0xc;
      }
    }
LAB_810785e8:
    func_0x81005af0(uStack_44);
  }
LAB_810785f0:
  if (_UNK_8111a5b0 == iStack_28) {
    return iVar4;
  }
  iVar4 = func_0x811185a0(iVar4);
  piVar8 = *(int **)(iVar4 + 0x10);
  if (piVar8 == (int *)0x0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  piVar10 = (int *)0x0;
  piVar7 = (int *)0x0;
  if (*piVar8 == 0x53464344) {
    piVar7 = piVar8;
  }
  *(int **)(iVar4 + 0x40) = piVar7;
  if (piVar7 == (int *)0x0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  piVar8 = piVar7 + 7;
  if ((piVar7[1] == 0x1c) || (uVar13 = 0, piVar9 = piVar8, piVar8 == (int *)0x0)) {
LAB_81078682:
    piVar9 = (int *)0x0;
  }
  else {
    do {
      if (*piVar9 == 0x204d5553) break;
      iVar11 = piVar9[1];
      uVar13 = uVar13 + iVar11;
      if ((uVar13 < piVar7[1] - 0x1cU) && (iVar11 != -1)) {
        piVar9 = (int *)((int)piVar9 + iVar11);
      }
      else {
        piVar9 = (int *)0x0;
      }
    } while (piVar9 != (int *)0x0);
    if (piVar9 == (int *)0x0) goto LAB_81078682;
    piVar9 = piVar9 + 3;
  }
  *(int **)(iVar4 + 0x30) = piVar9;
  if (piVar9 != (int *)0x0) {
    if ((piVar7[1] == 0x1c) || (uVar13 = 0, piVar9 = piVar8, piVar8 == (int *)0x0)) {
LAB_810786c4:
      piVar9 = (int *)0x0;
    }
    else {
      do {
        if (*piVar9 == 0x204d5553) break;
        iVar11 = piVar9[1];
        uVar13 = uVar13 + iVar11;
        if ((uVar13 < piVar7[1] - 0x1cU) && (iVar11 != -1)) {
          piVar9 = (int *)((int)piVar9 + iVar11);
        }
        else {
          piVar9 = (int *)0x0;
        }
      } while (piVar9 != (int *)0x0);
      if (piVar9 == (int *)0x0) goto LAB_810786c4;
      piVar9 = piVar9 + 3;
    }
    *(int **)(iVar4 + 0x30) = piVar9;
  }
  if ((piVar7[1] == 0x1c) || (uVar13 = 0, piVar9 = piVar8, piVar8 == (int *)0x0)) {
LAB_81078704:
    piVar9 = (int *)0x0;
  }
  else {
    do {
      if (*piVar9 == 0x454d414e) break;
      iVar11 = piVar9[1];
      uVar13 = uVar13 + iVar11;
      if ((uVar13 < piVar7[1] - 0x1cU) && (iVar11 != -1)) {
        piVar9 = (int *)((int)piVar9 + iVar11);
      }
      else {
        piVar9 = (int *)0x0;
      }
    } while (piVar9 != (int *)0x0);
    if (piVar9 == (int *)0x0) goto LAB_81078704;
    piVar9 = piVar9 + 3;
  }
  *(int **)(iVar4 + 0x2c) = piVar9;
  if (piVar9 == (int *)0x0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (piVar7[1] == 0x1c) {
    piVar9 = (int *)0x0;
  }
  else {
    uVar13 = 0;
    piVar9 = piVar8;
    while ((piVar9 != (int *)0x0 && (*piVar9 != 0x454c4946))) {
      iVar11 = piVar9[1];
      uVar13 = uVar13 + iVar11;
      if ((uVar13 < piVar7[1] - 0x1cU) && (iVar11 != -1)) {
        piVar9 = (int *)((int)piVar9 + iVar11);
      }
      else {
        piVar9 = (int *)0x0;
      }
    }
  }
  iVar11 = piVar7[1];
  *(int **)(iVar4 + 0x34) = piVar9;
  if ((iVar11 != 0x1c) && (uVar13 = 0, piVar9 = piVar8, piVar8 != (int *)0x0)) {
    do {
      if (*piVar9 == 0x454c4946) break;
      iVar12 = piVar9[1];
      uVar13 = uVar13 + iVar12;
      if ((uVar13 < iVar11 - 0x1cU) && (iVar12 != -1)) {
        piVar9 = (int *)((int)piVar9 + iVar12);
      }
      else {
        piVar9 = (int *)0x0;
      }
    } while (piVar9 != (int *)0x0);
    if (piVar9 != (int *)0x0) {
      piVar9 = piVar9 + 3;
      goto LAB_8107878e;
    }
  }
  piVar9 = (int *)0x0;
LAB_8107878e:
  *(int **)(iVar4 + 0x38) = piVar9;
  if (piVar9 == (int *)0x0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if ((piVar7[1] != 0x1c) && (uVar13 = 0, piVar8 != (int *)0x0)) {
    do {
      if (*piVar8 == 0x20524944) break;
      iVar11 = piVar8[1];
      uVar13 = uVar13 + iVar11;
      if ((uVar13 < piVar7[1] - 0x1cU) && (iVar11 != -1)) {
        piVar8 = (int *)((int)piVar8 + iVar11);
      }
      else {
        piVar8 = (int *)0x0;
      }
    } while (piVar8 != (int *)0x0);
    if (piVar8 != (int *)0x0) {
      piVar10 = piVar8 + 3;
    }
  }
  *(int **)(iVar4 + 0x3c) = piVar10;
  if (piVar10 != (int *)0x0) {
    *(uint *)(iVar4 + 0x20) = (uint)*(byte *)(piVar7 + 6) * 0x80 + 0x80;
    return 1;
  }
  do {
    func_0x81118870(1000);
  } while( true );
}

