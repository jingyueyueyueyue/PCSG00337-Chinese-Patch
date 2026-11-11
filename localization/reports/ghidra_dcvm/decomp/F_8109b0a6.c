
undefined FUN_8109b0a6(int *param_1)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  int *piStack_2c;
  
  param_1[6] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[8] = -1;
  param_1[9] = -1;
  param_1[10] = 0;
  if ((((param_1[3] != 0) && (piVar2 = *(int **)(param_1[3] + 4), piVar2 != (int *)0x0)) &&
      (*piVar2 == 0x4d564344)) &&
     ((*(short *)(piVar2 + 3) == 0x1000 && (*(char *)((int)piVar2 + 0xe) == '\0')))) {
    iVar9 = piVar2[1];
    piVar7 = piVar2 + 4;
    if ((iVar9 != 0x10) && (uVar3 = 0, piStack_2c = piVar7, piVar7 != (int *)0x0)) {
      do {
        if (*piStack_2c == 0x20525453) break;
        iVar6 = piStack_2c[1];
        uVar3 = uVar3 + iVar6;
        if ((uVar3 < iVar9 - 0x10U) && (iVar6 != -1)) {
          piStack_2c = (int *)((int)piStack_2c + iVar6);
        }
        else {
          piStack_2c = (int *)0x0;
        }
      } while (piStack_2c != (int *)0x0);
      if (((piStack_2c != (int *)0x0) && (iVar9 != 0x10)) &&
         (uVar3 = 0, piVar8 = piVar7, piVar7 != (int *)0x0)) {
        do {
          if (*piVar8 == 0x4c425453) break;
          iVar6 = piVar8[1];
          uVar3 = uVar3 + iVar6;
          if ((uVar3 < iVar9 - 0x10U) && (iVar6 != -1)) {
            piVar8 = (int *)((int)piVar8 + iVar6);
          }
          else {
            piVar8 = (int *)0x0;
          }
        } while (piVar8 != (int *)0x0);
        if (piVar8 != (int *)0x0) {
          piVar10 = piStack_2c + 4;
          iVar9 = piVar8[2];
          param_1[0xf] = (int)(piVar8 + 3);
          param_1[0x10] = (int)piVar10;
          param_1[0x11] = iVar9;
          if ((piVar2[1] != 0x10) && (uVar3 = 0, piVar8 = piVar7, piVar7 != (int *)0x0)) {
            do {
              if (*piVar8 == 0x45444f43) break;
              iVar9 = piVar8[1];
              uVar3 = uVar3 + iVar9;
              if ((uVar3 < piVar2[1] - 0x10U) && (iVar9 != -1)) {
                piVar8 = (int *)((int)piVar8 + iVar9);
              }
              else {
                piVar8 = (int *)0x0;
              }
            } while (piVar8 != (int *)0x0);
            if (piVar8 != (int *)0x0) {
              piVar11 = piVar8 + 7;
              param_1[6] = (int)piVar11;
              param_1[8] = piVar8[2];
              param_1[9] = piVar8[3];
              param_1[7] = piVar8[4];
              if (piVar8[6] != 0) {
                uVar3 = 0;
                if (piVar8[6] != 0) {
                  do {
                    uVar4 = uVar3 & 7;
                    uVar3 = uVar3 + 1;
                    *(byte *)piVar11 = (&UNK_81138844)[uVar4] ^ *(byte *)piVar11;
                    piVar11 = (int *)((int)piVar11 + 1);
                  } while (uVar3 < (uint)piVar8[6]);
                }
                piVar8[6] = 0;
                piVar10 = (int *)param_1[0x10];
              }
              if (piStack_2c[3] != 0) {
                uVar3 = 0;
                if (piStack_2c[3] != 0) {
                  do {
                    uVar4 = uVar3 & 7;
                    uVar3 = uVar3 + 1;
                    *(byte *)piVar10 = (&UNK_8113884c)[uVar4] ^ *(byte *)piVar10;
                    piVar10 = (int *)((int)piVar10 + 1);
                  } while (uVar3 < (uint)piStack_2c[3]);
                }
                piStack_2c[3] = 0;
                piVar10 = (int *)param_1[0x10];
              }
              pbVar5 = (byte *)param_1[6];
              uVar4 = param_1[7];
              uVar13 = 0;
              pbVar14 = pbVar5;
              uVar3 = uVar13;
              if (uVar4 != 0) {
                do {
                  uVar13 = uVar13 + *pbVar14 + uVar3;
                  if ((uVar3 & 1) != 0) {
                    uVar13 = ~uVar13;
                  }
                  uVar3 = uVar3 + 1;
                  pbVar14 = pbVar14 + 1;
                } while (uVar3 < uVar4);
              }
              uVar3 = 0;
              if (param_1[0x11] != 0) {
                piVar11 = (int *)param_1[0xf];
                uVar12 = uVar3;
                do {
                  pbVar14 = (byte *)(*piVar11 + (int)piVar10);
                  bVar1 = *(byte *)(*piVar11 + (int)piVar10);
                  while (bVar1 != 0) {
                    uVar3 = uVar3 + (int)(char)*pbVar14;
                    pbVar14 = pbVar14 + 1;
                    bVar1 = *pbVar14;
                  }
                  uVar12 = uVar12 + 1;
                  piVar11 = piVar11 + 1;
                } while (uVar12 < (uint)param_1[0x11]);
              }
              if (((uVar13 == piVar8[5]) && (uVar3 == piStack_2c[2])) &&
                 (uVar13 + uVar3 == piVar2[2])) {
                uVar3 = piVar2[1] - 0x10;
                if ((uVar3 != 0) && (uVar13 = 0, piVar8 = piVar7, piVar7 != (int *)0x0)) {
                  do {
                    if (*piVar8 == 0x4c425446) break;
                    iVar9 = piVar8[1];
                    uVar13 = uVar13 + iVar9;
                    if ((uVar13 < uVar3) && (iVar9 != -1)) {
                      piVar8 = (int *)((int)piVar8 + iVar9);
                    }
                    else {
                      piVar8 = (int *)0x0;
                    }
                  } while (piVar8 != (int *)0x0);
                  if ((piVar8 != (int *)0x0) && (piVar8[2] != 0)) {
                    param_1[0xb] = piVar8[2];
                    param_1[10] = (int)(piVar8 + 3);
                    uVar3 = piVar2[1] - 0x10;
                  }
                }
                if ((uVar3 != 0) && (uVar13 = 0, piVar8 = piVar7, piVar7 != (int *)0x0)) {
                  do {
                    if (*piVar8 == 0x4c425456) break;
                    iVar9 = piVar8[1];
                    uVar13 = uVar13 + iVar9;
                    if ((uVar13 < uVar3) && (iVar9 != -1)) {
                      piVar8 = (int *)((int)piVar8 + iVar9);
                    }
                    else {
                      piVar8 = (int *)0x0;
                    }
                  } while (piVar8 != (int *)0x0);
                  if ((piVar8 != (int *)0x0) && (piVar8[2] != 0)) {
                    param_1[0x13] = piVar8[2];
                    param_1[0x12] = (int)(piVar8 + 3);
                    uVar3 = piVar2[1] - 0x10;
                  }
                }
                if (uVar3 == 0) {
                  piVar2 = (int *)0x0;
                }
                else {
                  uVar13 = 0;
                  piVar2 = piVar7;
                  while ((piVar2 != (int *)0x0 && (*piVar2 != 0x4c425450))) {
                    iVar9 = piVar2[1];
                    uVar13 = uVar13 + iVar9;
                    if ((uVar13 < uVar3) && (iVar9 != -1)) {
                      piVar2 = (int *)((int)piVar2 + iVar9);
                    }
                    else {
                      piVar2 = (int *)0x0;
                    }
                  }
                }
                if (uVar3 == 0) {
                  piVar7 = (int *)0x0;
                }
                else {
                  uVar13 = 0;
                  while ((piVar7 != (int *)0x0 && (*piVar7 != 0x52545350))) {
                    iVar9 = piVar7[1];
                    uVar13 = uVar13 + iVar9;
                    if ((uVar13 < uVar3) && (iVar9 != -1)) {
                      piVar7 = (int *)((int)piVar7 + iVar9);
                    }
                    else {
                      piVar7 = (int *)0x0;
                    }
                  }
                }
                if ((piVar2 != (int *)0x0) && (piVar2[2] != 0)) {
                  if (piVar7 == (int *)0x0) goto LAB_8109b4b6;
                  param_1[0xe] = piVar2[2];
                  param_1[0xc] = (int)(piVar2 + 3);
                  param_1[0xd] = (int)(piVar7 + 2);
                }
                if (pbVar5 == (byte *)0x0) {
                  iVar9 = -1;
                }
                else {
                  iVar9 = 0;
                  pbVar14 = pbVar5 + uVar4;
                  for (; pbVar5 != pbVar14; pbVar5 = pbVar5 + 1) {
                    iVar9 = iVar9 + (uint)*pbVar5;
                  }
                }
                param_1[0x1e] = iVar9;
                return 1;
              }
            }
          }
        }
      }
    }
  }
LAB_8109b4b6:
  (**(code **)(*param_1 + 0x14))();
  return 0;
}

