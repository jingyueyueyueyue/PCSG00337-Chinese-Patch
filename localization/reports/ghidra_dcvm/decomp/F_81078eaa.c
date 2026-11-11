
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81078eaa(int **param_1,int **param_2,int **param_3,int **param_4,int **param_5)

{
  char cVar1;
  undefined4 uVar2;
  int **ppiVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  int **ppiVar10;
  undefined *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int **ppiVar14;
  undefined4 *puVar15;
  int **unaff_r7;
  int *unaff_r8;
  int **ppiVar16;
  int *piVar17;
  int **ppiVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  bool bVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  uint uStack_168;
  undefined auStack_164 [8];
  undefined4 uStack_15c;
  int *piStack_158;
  int *piStack_150;
  undefined4 *puStack_14c;
  undefined4 uStack_148;
  undefined *puStack_144;
  undefined4 *puStack_140;
  undefined *puStack_13c;
  uint uStack_128;
  int *piStack_124;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  int *piStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 auStack_100 [2];
  undefined4 uStack_f8;
  int *piStack_f4;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined *puStack_e4;
  undefined *puStack_e0;
  int *piStack_dc;
  undefined *puStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_c8;
  undefined auStack_c4 [4];
  undefined auStack_c0 [8];
  undefined4 uStack_b8;
  int *piStack_b4;
  undefined *puStack_ac;
  int **ppiStack_a8;
  int **ppiStack_a4;
  int **ppiStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_90;
  undefined auStack_8c [4];
  int *piStack_88;
  int **ppiStack_80;
  undefined4 uStack_7c;
  char cStack_78;
  undefined auStack_70 [4];
  int **ppiStack_6c;
  int **ppiStack_68;
  int **ppiStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int **ppiStack_58;
  int **ppiStack_54;
  int **ppiStack_50;
  int **ppiStack_4c;
  int **ppiStack_48;
  int **ppiStack_44;
  int **ppiStack_40;
  int iStack_3c;
  int *piStack_38;
  int **ppiStack_34;
  int **ppiStack_30;
  int **ppiStack_2c;
  int **ppiStack_28;
  int *piStack_24;
  
  piStack_24 = _UNK_8111a5b0;
  ppiVar14 = (int **)0x0;
  *param_2 = (int *)0x0;
  *param_3 = (int *)0xffffffff;
  ppiStack_34 = param_1 + 1;
  ppiStack_30 = param_5;
  ppiStack_54 = param_3;
  ppiStack_50 = param_2;
  ppiStack_4c = param_1;
  (*(code *)param_1[1][2])(ppiStack_34);
  ppiStack_58 = param_4;
  if (*param_4 == (int *)0x0) {
    (*(code *)ppiStack_4c[1][3])(ppiStack_34);
    uVar2 = 0;
  }
  else {
    param_5 = (int **)*ppiStack_4c;
    if ((((param_5[3] == *ppiStack_30) && (param_5[2] != (int *)0x0)) && (param_4[2] != (int *)0x0))
       && (iVar5 = func_0x811181a0(), iVar5 == 0)) {
      *ppiStack_50 = param_5[4];
      *ppiStack_54 = param_5[5];
      (*(code *)ppiStack_4c[1][3])(ppiStack_34);
      uVar2 = 1;
    }
    else {
      ppiStack_6c = (int **)0x0;
      ppiStack_68 = (int **)0x0;
      ppiStack_6c = (int **)func_0x81005a98(0x1c);
      if (ppiStack_6c != (int **)0x0) {
        *ppiStack_6c = (int *)ppiStack_6c;
      }
      if (ppiStack_6c != (int **)0xfffffffc) {
        ppiStack_6c[1] = (int *)ppiStack_6c;
      }
      if (ppiStack_6c != (int **)0xfffffff8) {
        ppiStack_6c[2] = (int *)ppiStack_6c;
      }
      *(undefined *)((int)ppiStack_6c + 0x19) = 1;
      *(undefined *)(ppiStack_6c + 6) = 1;
      ppiStack_28 = (int **)ppiStack_4c[3];
      ppiVar14 = ppiStack_6c;
      ppiVar3 = ppiStack_48;
      while (ppiStack_48 = ppiVar14, ppiVar14 = ppiStack_28, ppiStack_28 = ppiVar14,
            ppiVar14 != (int **)0x0) {
        piStack_38 = (int *)FUN_810784ae(ppiVar14,ppiStack_58);
        if (-1 < (int)piStack_38) {
          ppiVar10 = (int **)ppiVar14[10];
          ppiStack_2c = ppiStack_6c;
          ppiVar16 = ppiStack_6c;
          ppiVar3 = ppiStack_6c;
          ppiVar18 = (int **)ppiStack_6c[1];
          if (*(char *)((int)ppiStack_6c[1] + 0x19) == '\0') {
            do {
              ppiVar3 = ppiVar18;
              if (ppiVar3[3] < ppiVar10) {
                ppiVar18 = (int **)ppiVar3[2];
                cVar1 = *(char *)((int)ppiVar18 + 0x19);
                ppiVar3 = ppiVar16;
              }
              else {
                ppiVar18 = (int **)*ppiVar3;
                cVar1 = *(char *)((int)ppiVar18 + 0x19);
              }
              param_4 = (int **)(int)cVar1;
              ppiVar16 = ppiVar3;
            } while (param_4 == (int **)0x0);
          }
          if ((ppiVar3 == ppiStack_6c) || (ppiVar10 < ppiVar3[3])) {
            uStack_60 = 0;
            uStack_5c = 0;
            iStack_3c = (int)cRam8119126c;
            param_4 = ppiStack_68;
            ppiStack_64 = ppiVar10;
            if (ppiStack_68 == (int **)0x0) {
              cStack_78 = cRam8119126c;
              ppiVar3 = (int **)func_0x81104580(auStack_70,1,ppiStack_6c,&ppiStack_64);
            }
            else {
              ppiStack_40 = (int **)*ppiStack_6c;
              if (ppiVar3 == ppiStack_40) {
                if (ppiVar10 < ppiVar3[3]) {
                  cStack_78 = cRam8119126c;
                  ppiVar3 = (int **)func_0x81104580(auStack_70,1,ppiVar3,&ppiStack_64);
                  goto LAB_81079204;
                }
              }
              else if (ppiVar3 == ppiStack_6c) {
                ppiVar14 = (int **)ppiStack_6c[2][3];
                if (ppiVar14 < ppiVar10) {
                  cStack_78 = cRam8119126c;
                  ppiVar3 = (int **)func_0x81104580(auStack_70,0,ppiStack_6c[2],&ppiStack_64);
                  goto LAB_81079204;
                }
              }
              else {
                ppiStack_44 = (int **)ppiVar3[3];
                if (ppiVar10 < ppiStack_44) {
                  if (*(char *)((int)ppiVar3 + 0x19) == '\0') {
                    ppiVar16 = (int **)*ppiVar3;
                    ppiVar14 = ppiVar3;
                    if (*(char *)((int)ppiVar16 + 0x19) == '\0') {
                      cVar1 = *(char *)((int)ppiVar16[2] + 0x19);
                      ppiVar14 = (int **)ppiVar16[2];
                      while (cVar1 == '\0') {
                        cVar1 = *(char *)((int)ppiVar14[2] + 0x19);
                        ppiVar16 = ppiVar14;
                        ppiVar14 = (int **)ppiVar14[2];
                      }
                    }
                    else {
                      do {
                        ppiVar16 = ppiVar14;
                        ppiVar14 = (int **)ppiVar16[1];
                        if (*(char *)((int)ppiVar14 + 0x19) != '\0') break;
                      } while (ppiVar16 == (int **)*ppiVar14);
                      if (*(char *)((int)ppiVar16 + 0x19) == '\0') {
                        ppiVar16 = ppiVar14;
                      }
                    }
                  }
                  else {
                    ppiVar16 = (int **)ppiVar3[2];
                  }
                  ppiVar14 = (int **)ppiVar16[3];
                  if (ppiVar14 < ppiVar10) {
                    if (*(char *)((int)ppiVar16[2] + 0x19) == '\0') {
                      cStack_78 = cRam8119126c;
                      ppiVar3 = (int **)func_0x81104580(auStack_70,1,ppiVar3,&ppiStack_64);
                    }
                    else {
                      cStack_78 = cRam8119126c;
                      ppiVar3 = (int **)func_0x81104580(auStack_70,0,ppiVar16,&ppiStack_64);
                    }
                    goto LAB_81079204;
                  }
                }
                if (ppiStack_44 < ppiVar10) {
                  ppiVar16 = ppiVar3;
                  if (*(char *)((int)ppiVar3 + 0x19) == '\0') {
                    ppiVar16 = (int **)ppiVar3[2];
                    ppiVar18 = ppiVar3;
                    if (*(char *)((int)ppiVar16 + 0x19) == '\0') {
                      cVar1 = *(char *)((int)*ppiVar16 + 0x19);
                      ppiVar18 = (int **)*ppiVar16;
                      while (cVar1 == '\0') {
                        cVar1 = *(char *)((int)*ppiVar18 + 0x19);
                        ppiVar16 = ppiVar18;
                        ppiVar18 = (int **)*ppiVar18;
                      }
                    }
                    else {
                      do {
                        ppiVar16 = (int **)ppiVar18[1];
                        if (*(char *)((int)ppiVar16 + 0x19) != '\0') break;
                        bVar21 = ppiVar18 == (int **)ppiVar16[2];
                        ppiVar18 = ppiVar16;
                      } while (bVar21);
                    }
                  }
                  if ((ppiVar16 == ppiStack_6c) || (ppiVar10 < ppiVar16[3])) {
                    if (*(char *)((int)ppiVar3[2] + 0x19) == '\0') {
                      cStack_78 = cRam8119126c;
                      ppiVar3 = (int **)func_0x81104580(auStack_70,1,ppiVar16,&ppiStack_64);
                    }
                    else {
                      cStack_78 = cRam8119126c;
                      ppiVar3 = (int **)func_0x81104580(auStack_70,0,ppiVar3,&ppiStack_64);
                    }
                    goto LAB_81079204;
                  }
                }
              }
              bVar21 = true;
              unaff_r7 = (int **)0x0;
              cVar1 = *(char *)((int)ppiStack_6c[1] + 0x19);
              ppiVar14 = (int **)ppiStack_6c[1];
              ppiVar16 = ppiStack_6c;
              while (ppiVar3 = ppiVar14, ppiVar14 = (int **)(int)cVar1, ppiVar14 == (int **)0x0) {
                bVar21 = ppiVar10 < ppiVar3[3];
                if (bVar21) {
                  ppiVar14 = (int **)*ppiVar3;
                }
                else {
                  ppiVar14 = (int **)ppiVar3[2];
                }
                cVar1 = *(char *)((int)ppiVar14 + 0x19);
                ppiVar16 = ppiVar3;
              }
              param_4 = ppiVar16;
              if (bVar21 != false) {
                if (ppiVar16 == ppiStack_40) {
                  cStack_78 = (char)ppiStack_48;
                  ppiVar3 = (int **)func_0x81104580(auStack_70,1,ppiVar16,&ppiStack_64);
                  goto LAB_81079204;
                }
                if (*(char *)((int)ppiVar16 + 0x19) == '\0') {
                  param_4 = (int **)*ppiVar16;
                  ppiVar3 = ppiVar16;
                  if (*(char *)((int)param_4 + 0x19) == '\0') {
                    cVar1 = *(char *)((int)param_4[2] + 0x19);
                    ppiVar3 = (int **)param_4[2];
                    while (cVar1 == '\0') {
                      cVar1 = *(char *)((int)ppiVar3[2] + 0x19);
                      param_4 = ppiVar3;
                      ppiVar3 = (int **)ppiVar3[2];
                    }
                  }
                  else {
                    do {
                      param_4 = ppiVar3;
                      ppiVar3 = (int **)param_4[1];
                      if (*(char *)((int)ppiVar3 + 0x19) != '\0') break;
                    } while (param_4 == (int **)*ppiVar3);
                    if (*(char *)((int)param_4 + 0x19) == '\0') {
                      param_4 = ppiVar3;
                    }
                  }
                }
                else {
                  param_4 = (int **)ppiVar16[2];
                }
              }
              ppiVar3 = param_4;
              if (param_4[3] < ppiVar10) {
                cStack_78 = (char)ppiStack_48;
                ppiVar3 = (int **)func_0x81104580(auStack_70,bVar21,ppiVar16,&ppiStack_64);
              }
            }
          }
LAB_81079204:
          ppiVar3[4] = (int *)ppiStack_28;
          ppiVar3[5] = piStack_38;
        }
        param_5 = ppiVar14;
        ppiVar14 = ppiStack_48;
        ppiVar3 = ppiStack_48;
        if (ppiStack_28 != (int **)0x0) {
          ppiStack_28 = (int **)ppiStack_28[2];
        }
      }
      ppiVar14 = (int **)0x0;
      ppiStack_48 = ppiVar3;
      if (ppiStack_68 == (int **)0x0) {
        func_0x81103db4(auStack_70);
        (*(code *)ppiStack_4c[1][3])(ppiStack_34);
        uVar2 = 0;
      }
      else {
        unaff_r8 = *ppiStack_30;
        if (piRam81191264 == unaff_r8) {
          if (*(char *)((int)ppiStack_6c + 0x19) == '\0') {
            ppiVar14 = (int **)*ppiStack_6c;
            ppiVar3 = ppiStack_6c;
            if (*(char *)((int)ppiVar14 + 0x19) == '\0') {
              cVar1 = *(char *)((int)ppiVar14[2] + 0x19);
              ppiVar3 = (int **)ppiVar14[2];
              while (cVar1 == '\0') {
                cVar1 = *(char *)((int)ppiVar3[2] + 0x19);
                ppiVar14 = ppiVar3;
                ppiVar3 = (int **)ppiVar3[2];
              }
            }
            else {
              do {
                ppiVar14 = ppiVar3;
                ppiVar3 = (int **)ppiVar14[1];
                if (*(char *)((int)ppiVar3 + 0x19) != '\0') break;
              } while (ppiVar14 == (int **)*ppiVar3);
              if (*(char *)((int)ppiVar14 + 0x19) == '\0') {
                ppiVar14 = ppiVar3;
              }
            }
          }
          else {
            ppiVar14 = (int **)ppiStack_6c[2];
          }
          piVar17 = ppiVar14[4];
          *ppiStack_50 = piVar17;
          if (*(char *)((int)ppiStack_6c + 0x19) == '\0') {
            ppiVar14 = (int **)*ppiStack_6c;
            ppiVar3 = ppiStack_6c;
            if (*(char *)((int)ppiVar14 + 0x19) == '\0') {
              cVar1 = *(char *)((int)ppiVar14[2] + 0x19);
              ppiVar3 = (int **)ppiVar14[2];
              while (cVar1 == '\0') {
                cVar1 = *(char *)((int)ppiVar3[2] + 0x19);
                ppiVar14 = ppiVar3;
                ppiVar3 = (int **)ppiVar3[2];
              }
            }
            else {
              do {
                ppiVar14 = ppiVar3;
                ppiVar3 = (int **)ppiVar14[1];
                if (*(char *)((int)ppiVar3 + 0x19) != '\0') break;
              } while (ppiVar14 == (int **)*ppiVar3);
              if (*(char *)((int)ppiVar14 + 0x19) == '\0') {
                ppiVar14 = ppiVar3;
              }
            }
          }
          else {
            ppiVar14 = (int **)ppiStack_6c[2];
          }
          param_4 = (int **)ppiVar14[5];
          *ppiStack_54 = (int *)param_4;
        }
        else {
          cVar1 = *(char *)((int)ppiStack_6c[1] + 0x19);
          ppiVar3 = (int **)ppiStack_6c[1];
          ppiVar14 = ppiStack_6c;
          while (ppiVar16 = ppiVar3, cVar1 == '\0') {
            if (ppiVar16[3] < unaff_r8) {
              cVar1 = *(char *)((int)ppiVar16[2] + 0x19);
              ppiVar3 = (int **)ppiVar16[2];
            }
            else {
              cVar1 = *(char *)((int)*ppiVar16 + 0x19);
              ppiVar3 = (int **)*ppiVar16;
              ppiVar14 = ppiVar16;
            }
          }
          if ((ppiVar14 == ppiStack_6c) || (unaff_r8 < ppiVar14[3])) {
            ppiVar14 = ppiStack_6c;
          }
          if (ppiVar14 == ppiStack_6c) {
            if (*(char *)((int)ppiStack_6c + 0x19) == '\0') {
              ppiVar14 = (int **)*ppiStack_6c;
              ppiVar3 = ppiStack_6c;
              if (*(char *)((int)ppiVar14 + 0x19) == '\0') {
                cVar1 = *(char *)((int)ppiVar14[2] + 0x19);
                ppiVar3 = (int **)ppiVar14[2];
                while (cVar1 == '\0') {
                  cVar1 = *(char *)((int)ppiVar3[2] + 0x19);
                  ppiVar14 = ppiVar3;
                  ppiVar3 = (int **)ppiVar3[2];
                }
              }
              else {
                do {
                  ppiVar14 = ppiVar3;
                  ppiVar3 = (int **)ppiVar14[1];
                  if (*(char *)((int)ppiVar3 + 0x19) != '\0') break;
                } while (ppiVar14 == (int **)*ppiVar3);
                if (*(char *)((int)ppiVar14 + 0x19) == '\0') {
                  ppiVar14 = ppiVar3;
                }
              }
            }
            else {
              ppiVar14 = (int **)ppiStack_6c[2];
            }
            piVar17 = ppiVar14[4];
            *ppiStack_50 = piVar17;
            if (*(char *)((int)ppiStack_6c + 0x19) == '\0') {
              ppiVar14 = (int **)*ppiStack_6c;
              ppiVar3 = ppiStack_6c;
              if (*(char *)((int)ppiVar14 + 0x19) == '\0') {
                cVar1 = *(char *)((int)ppiVar14[2] + 0x19);
                ppiVar3 = (int **)ppiVar14[2];
                while (cVar1 == '\0') {
                  cVar1 = *(char *)((int)ppiVar3[2] + 0x19);
                  ppiVar14 = ppiVar3;
                  ppiVar3 = (int **)ppiVar3[2];
                }
              }
              else {
                do {
                  ppiVar14 = ppiVar3;
                  ppiVar3 = (int **)ppiVar14[1];
                  if (*(char *)((int)ppiVar3 + 0x19) != '\0') break;
                } while (ppiVar14 == (int **)*ppiVar3);
                if (*(char *)((int)ppiVar14 + 0x19) == '\0') {
                  ppiVar14 = ppiVar3;
                }
              }
            }
            else {
              ppiVar14 = (int **)ppiStack_6c[2];
            }
            param_4 = (int **)ppiVar14[5];
            *ppiStack_54 = (int *)param_4;
          }
          else {
            piVar17 = ppiVar14[4];
            *ppiStack_50 = piVar17;
            param_4 = (int **)ppiVar14[5];
            *ppiStack_54 = (int *)param_4;
          }
        }
        ppiVar14 = (int **)*ppiStack_4c;
        piVar9 = *ppiStack_30;
        piVar4 = ppiVar14[2];
        ppiVar14[2] = (int *)0x0;
        ppiVar14[3] = piVar9;
        func_0x81005af0(piVar4);
        unaff_r7 = ppiStack_58;
        ppiVar14[1] = ppiStack_58[1];
        piVar4 = *ppiStack_58;
        *ppiVar14 = piVar4;
        if (ppiStack_58[2] != (int *)0x0) {
          param_5 = (int **)((int)piVar4 + 1);
          piVar4 = (int *)func_0x81005aaa(param_5);
          piVar9 = ppiVar14[2];
          ppiVar14[2] = piVar4;
          func_0x81005af0(piVar9);
          func_0x8109d75c(ppiVar14[2],param_5,unaff_r7[2]);
        }
        ppiVar14[4] = piVar17;
        ppiVar14[5] = (int *)param_4;
        func_0x81103db4(auStack_70);
        (*(code *)ppiStack_4c[1][3])(ppiStack_34);
        uVar2 = 1;
      }
    }
  }
  if (_UNK_8111a5b0 == piStack_24) {
    return;
  }
  uVar19 = 0x81079467;
  uVar22 = func_0x811185a0(uVar2);
  piStack_88 = _UNK_8111a5b0;
  uStack_90 = 0;
  uStack_98 = 0x81191264;
  ppiStack_80 = param_5;
  uStack_7c = uVar19;
  FUN_81078eaa((int)uVar22,&uStack_90,auStack_8c,(int)((ulonglong)uVar22 >> 0x20));
  if (_UNK_8111a5b0 == piStack_88) {
    return;
  }
  uVar19 = 0x810794a1;
  uVar2 = func_0x811185a0();
  puStack_ac = &UNK_8111a5b0;
  piStack_b4 = _UNK_8111a5b0;
  uStack_b8 = 0;
  ppiStack_a8 = ppiVar14;
  ppiStack_a4 = param_4;
  ppiStack_a0 = unaff_r7;
  uStack_9c = uVar19;
  func_0x81080bb2(auStack_c0);
  uStack_c8 = 0;
  uStack_d0 = 0x81191264;
  puVar11 = auStack_c0;
  uVar2 = FUN_81078eaa(uVar2,&uStack_c8,auStack_c4,auStack_c0);
  func_0x81005af0(uStack_b8);
  if (_UNK_8111a5b0 == piStack_b4) {
    return;
  }
  uVar20 = 0x810794f5;
  piVar17 = piStack_b4;
  uVar22 = func_0x811185a0(uVar2);
  uVar19 = uStack_d0;
  uVar6 = (undefined4)((ulonglong)uVar22 >> 0x20);
  puStack_d8 = &UNK_8111a5b0;
  puStack_e0 = &UNK_8111a5b0;
  uStack_e8 = 0;
  piStack_f4 = _UNK_8111a5b0;
  uStack_f8 = 0;
  uStack_ec = uVar2;
  puStack_e4 = auStack_c0;
  piStack_dc = unaff_r8;
  uStack_d4 = uVar20;
  func_0x81080bb2(auStack_100,puVar11);
  uStack_108 = uVar19;
  puVar12 = auStack_100;
  uVar2 = FUN_81078eaa((int)uVar22,uVar6,piVar17,auStack_100);
  func_0x81005af0(uStack_f8);
  if (_UNK_8111a5b0 == piStack_f4) {
    return;
  }
  uVar20 = 0x81079551;
  piVar4 = piStack_f4;
  uVar23 = func_0x811185a0(uVar2);
  uVar19 = uStack_108;
  puVar15 = (undefined4 *)((ulonglong)uVar23 >> 0x20);
  piStack_124 = _UNK_8111a5b0;
  *puVar15 = 0;
  *piVar4 = 0;
  uStack_11c = uVar2;
  uStack_118 = uVar6;
  piStack_114 = piVar17;
  uStack_110 = (int)uVar22;
  uStack_10c = uVar20;
  iVar5 = FUN_81078eaa((int)uVar23,puVar15,&uStack_128);
  if (iVar5 == 0) {
    uVar2 = 0;
  }
  else {
    puVar13 = (undefined4 *)*puVar15;
    puVar15 = (undefined4 *)puVar13[0xe];
    if (puVar15 == (undefined4 *)0x0) {
      uStack_128 = 0xffffffff;
    }
    puVar7 = (undefined4 *)0x0;
    puVar12 = puVar13;
    if ((-1 < (int)uStack_128) &&
       (puVar7 = (undefined4 *)0x0, puVar12 = puVar7, uStack_128 < *(uint *)(puVar13[0xd] + 8))) {
      puVar7 = puVar15 + uStack_128 * 3;
      puVar12 = puVar7;
    }
    uVar2 = 1;
    *piVar4 = (int)puVar7;
  }
  if (_UNK_8111a5b0 == piStack_124) {
    return;
  }
  piVar17 = piStack_124;
  uVar22 = func_0x811185a0(uVar2);
  piVar9 = (int *)((ulonglong)uVar22 >> 0x20);
  puStack_13c = &UNK_8111a5b0;
  puStack_144 = &UNK_8111a5b0;
  uStack_148 = 0;
  piStack_158 = _UNK_8111a5b0;
  uStack_15c = 0;
  piStack_150 = piVar4;
  puStack_14c = puVar15;
  puStack_140 = auStack_100;
  func_0x81080bb2(auStack_164,puVar12);
  *piVar9 = 0;
  *piVar17 = 0;
  iVar5 = FUN_81078eaa((int)uVar22,piVar9,&uStack_168,auStack_164,uVar19);
  if (iVar5 == 0) {
    uVar2 = 0;
  }
  else {
    iVar5 = *(int *)(*piVar9 + 0x38);
    if (iVar5 == 0) {
      uStack_168 = 0xffffffff;
    }
    iVar8 = 0;
    if ((-1 < (int)uStack_168) && (iVar8 = 0, uStack_168 < *(uint *)(*(int *)(*piVar9 + 0x34) + 8)))
    {
      iVar8 = iVar5 + uStack_168 * 0xc;
    }
    *piVar17 = iVar8;
    uVar2 = 1;
  }
  func_0x81005af0(uStack_15c);
  if (_UNK_8111a5b0 == piStack_158) {
    return;
  }
  func_0x811185a0(uVar2);
  piRam81191264 = (int *)0xffffffff;
  return;
}

