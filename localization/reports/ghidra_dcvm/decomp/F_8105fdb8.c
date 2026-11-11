
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int **** FUN_8105fdb8(int *****param_1,int *param_2,undefined *param_3,char *param_4)

{
  char cVar1;
  char cVar2;
  int ****ppppiVar3;
  int *****pppppiVar4;
  int *****pppppiVar5;
  int iVar6;
  byte extraout_r1;
  int *piVar7;
  int ****ppppiVar8;
  uint uVar9;
  int *****pppppiVar10;
  int *piVar11;
  int *****unaff_r5;
  int *****pppppiVar12;
  int *piVar13;
  int *piVar14;
  int *****pppppiVar15;
  int *****pppppiVar16;
  undefined4 uVar17;
  int *piVar18;
  bool bVar19;
  undefined8 uVar20;
  char cStack_70;
  int *****pppppiStack_68;
  undefined4 uStack_64;
  int ****ppppiStack_60;
  int *****pppppiStack_5c;
  int *****pppppiStack_58;
  int *****pppppiStack_54;
  int iStack_50;
  int *****pppppiStack_4c;
  int ****ppppiStack_48;
  int *****pppppiStack_40;
  int *****pppppiStack_3c;
  int *piStack_38;
  undefined auStack_28 [8];
  undefined4 uStack_20;
  int ****ppppiStack_1c;
  
  ppppiStack_1c = _UNK_8111a5b0;
  *param_2 = -1;
  *param_3 = 0xff;
  if (((param_1[2] == (int ****)0x0) || (param_4 == (char *)0x0)) || (*param_4 == '\0')) {
    ppppiVar3 = (int ****)0x0;
  }
  else {
    uStack_20 = 0;
    func_0x81080bb2(auStack_28);
    param_1 = (int *****)param_1[1];
    unaff_r5 = (int *****)*param_1;
joined_r0x8105fe00:
    if (unaff_r5 != param_1) {
      iVar6 = FUN_810784ae(unaff_r5[4],auStack_28);
      if (-1 < iVar6) {
        *param_2 = iVar6;
        *param_3 = (char)unaff_r5[3];
        func_0x81005af0(uStack_20);
        ppppiVar3 = (int ****)0x1;
        goto LAB_8105fe64;
      }
      if (*(char *)((int)unaff_r5 + 0x15) == '\0') {
        pppppiVar16 = (int *****)unaff_r5[2];
        pppppiVar5 = unaff_r5;
        if (*(char *)((int)pppppiVar16 + 0x15) == '\0') {
          cVar1 = *(char *)((int)*pppppiVar16 + 0x15);
          unaff_r5 = pppppiVar16;
          pppppiVar5 = (int *****)*pppppiVar16;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*pppppiVar5 + 0x15);
            unaff_r5 = pppppiVar5;
            pppppiVar5 = (int *****)*pppppiVar5;
          }
        }
        else {
          do {
            unaff_r5 = (int *****)pppppiVar5[1];
            if (*(char *)((int)unaff_r5 + 0x15) != '\0') break;
            bVar19 = pppppiVar5 == (int *****)unaff_r5[2];
            pppppiVar5 = unaff_r5;
          } while (bVar19);
        }
      }
      goto joined_r0x8105fe00;
    }
    func_0x81005af0(uStack_20);
    ppppiVar3 = (int ****)0x0;
  }
LAB_8105fe64:
  if (_UNK_8111a5b0 == ppppiStack_1c) {
    return ppppiVar3;
  }
  ppppiVar8 = ppppiStack_1c;
  pppppiVar4 = (int *****)func_0x811185a0(ppppiVar3);
  cVar2 = cRam81190ab0;
  ppppiStack_48 = _UNK_8111a5b0;
  pppppiVar15 = (int *****)(uint)extraout_r1;
  pppppiStack_4c = (int *****)pppppiVar4[1];
  cVar1 = *(char *)((int)pppppiStack_4c[1] + 0x15);
  pppppiVar5 = pppppiStack_4c;
  pppppiVar16 = (int *****)pppppiStack_4c[1];
  while (cVar1 == '\0') {
    if (pppppiVar16[3] < pppppiVar15) {
      cVar1 = *(char *)((int)pppppiVar16[2] + 0x15);
      pppppiVar16 = (int *****)pppppiVar16[2];
    }
    else {
      cVar1 = *(char *)((int)*pppppiVar16 + 0x15);
      pppppiVar5 = pppppiVar16;
      pppppiVar16 = (int *****)*pppppiVar16;
    }
  }
  ppppiStack_60 = ppppiVar8;
  pppppiStack_5c = pppppiVar4;
  pppppiStack_40 = param_1;
  pppppiStack_3c = unaff_r5;
  piStack_38 = param_2;
  if ((pppppiVar5 == pppppiStack_4c) ||
     (pppppiVar16 = (int *****)pppppiVar5[3], pppppiVar12 = unaff_r5, pppppiVar15 < pppppiVar5[3]))
  {
    uStack_64 = 0;
    iStack_50 = (int)cRam81190ab0;
    pppppiStack_68 = pppppiVar15;
    if (pppppiVar4[2] == (int ****)0x0) {
      pppppiVar16 = (int *****)&pppppiStack_68;
      pppppiVar5 = (int *****)func_0x810fabe4(pppppiVar4,1,pppppiStack_4c);
      pppppiVar12 = (int *****)0x0;
      cStack_70 = cVar2;
    }
    else {
      pppppiVar12 = (int *****)*pppppiStack_4c;
      pppppiStack_54 = pppppiVar12;
      if (pppppiVar5 == pppppiVar12) {
        if (pppppiVar15 < pppppiVar5[3]) {
          pppppiVar16 = (int *****)&pppppiStack_68;
          pppppiVar5 = (int *****)func_0x810fabe4(pppppiVar4,1);
          cStack_70 = cVar2;
          goto LAB_8106010e;
        }
      }
      else if (pppppiVar5 == pppppiStack_4c) {
        if (pppppiStack_4c[2][3] < pppppiVar15) {
          pppppiVar16 = (int *****)&pppppiStack_68;
          pppppiVar5 = (int *****)func_0x810fabe4(pppppiVar4,0);
          cStack_70 = cVar2;
          goto LAB_8106010e;
        }
      }
      else {
        pppppiStack_58 = (int *****)pppppiVar5[3];
        if (pppppiVar15 < pppppiStack_58) {
          if (*(char *)((int)pppppiVar5 + 0x15) == '\0') {
            pppppiVar10 = (int *****)*pppppiVar5;
            pppppiVar16 = pppppiVar5;
            if (*(char *)((int)pppppiVar10 + 0x15) == '\0') {
              cVar1 = *(char *)((int)pppppiVar10[2] + 0x15);
              pppppiVar16 = (int *****)pppppiVar10[2];
              while (cVar1 == '\0') {
                cVar1 = *(char *)((int)pppppiVar16[2] + 0x15);
                pppppiVar10 = pppppiVar16;
                pppppiVar16 = (int *****)pppppiVar16[2];
              }
            }
            else {
              do {
                pppppiVar10 = pppppiVar16;
                pppppiVar16 = (int *****)pppppiVar10[1];
                if (*(char *)((int)pppppiVar16 + 0x15) != '\0') break;
              } while (pppppiVar10 == (int *****)*pppppiVar16);
              if (*(char *)((int)pppppiVar10 + 0x15) == '\0') {
                pppppiVar10 = pppppiVar16;
              }
            }
          }
          else {
            pppppiVar10 = (int *****)pppppiVar5[2];
          }
          if (pppppiVar10[3] < pppppiVar15) {
            if (*(char *)((int)pppppiVar10[2] + 0x15) == '\0') {
              pppppiVar16 = (int *****)&pppppiStack_68;
              pppppiVar5 = (int *****)func_0x810fabe4(pppppiVar4,1);
              cStack_70 = cVar2;
            }
            else {
              pppppiVar16 = (int *****)&pppppiStack_68;
              pppppiVar5 = (int *****)func_0x810fabe4(pppppiVar4,0,pppppiVar10);
              cStack_70 = cVar2;
            }
            goto LAB_8106010e;
          }
        }
        if (pppppiStack_58 < pppppiVar15) {
          pppppiVar10 = pppppiVar5;
          if (*(char *)((int)pppppiVar5 + 0x15) == '\0') {
            pppppiVar10 = (int *****)pppppiVar5[2];
            pppppiVar16 = pppppiVar5;
            if (*(char *)((int)pppppiVar10 + 0x15) == '\0') {
              cVar1 = *(char *)((int)*pppppiVar10 + 0x15);
              pppppiVar16 = (int *****)*pppppiVar10;
              while (cVar1 == '\0') {
                cVar1 = *(char *)((int)*pppppiVar16 + 0x15);
                pppppiVar10 = pppppiVar16;
                pppppiVar16 = (int *****)*pppppiVar16;
              }
            }
            else {
              do {
                pppppiVar10 = (int *****)pppppiVar16[1];
                if (*(char *)((int)pppppiVar10 + 0x15) != '\0') break;
                bVar19 = pppppiVar16 == (int *****)pppppiVar10[2];
                pppppiVar16 = pppppiVar10;
              } while (bVar19);
            }
          }
          if ((pppppiVar10 == pppppiStack_4c) || (pppppiVar15 < pppppiVar10[3])) {
            if (*(char *)((int)pppppiVar5[2] + 0x15) == '\0') {
              pppppiVar16 = (int *****)&pppppiStack_68;
              pppppiVar5 = (int *****)func_0x810fabe4(pppppiVar4,1,pppppiVar10);
              pppppiVar12 = pppppiVar4;
              cStack_70 = cVar2;
            }
            else {
              pppppiVar16 = (int *****)&pppppiStack_68;
              pppppiVar5 = (int *****)func_0x810fabe4(pppppiVar4,0);
              pppppiVar12 = pppppiVar4;
              cStack_70 = cVar2;
            }
            goto LAB_8106010e;
          }
        }
      }
      bVar19 = true;
      cVar1 = *(char *)((int)pppppiStack_4c[1] + 0x15);
      pppppiVar5 = pppppiStack_4c;
      pppppiVar16 = (int *****)pppppiStack_4c[1];
      while (cVar1 == '\0') {
        bVar19 = pppppiVar15 < pppppiVar16[3];
        if (bVar19) {
          pppppiVar10 = (int *****)*pppppiVar16;
        }
        else {
          pppppiVar10 = (int *****)pppppiVar16[2];
        }
        pppppiVar5 = pppppiVar16;
        pppppiVar16 = pppppiVar10;
        cVar1 = *(char *)((int)pppppiVar10 + 0x15);
      }
      if (bVar19) {
        if (pppppiVar5 == pppppiVar12) {
          pppppiVar16 = (int *****)&pppppiStack_68;
          pppppiVar5 = (int *****)func_0x810fabe4(pppppiVar4,1);
          pppppiVar12 = pppppiVar4;
          cStack_70 = (char)pppppiVar12;
          goto LAB_8106010e;
        }
        if (*(char *)((int)pppppiVar5 + 0x15) == '\0') {
          pppppiVar16 = (int *****)*pppppiVar5;
          if (*(char *)((int)pppppiVar16 + 0x15) == '\0') {
            cVar1 = *(char *)((int)pppppiVar16[2] + 0x15);
            pppppiVar5 = pppppiVar16;
            pppppiVar16 = (int *****)pppppiVar16[2];
            while (cVar1 == '\0') {
              cVar1 = *(char *)((int)pppppiVar16[2] + 0x15);
              pppppiVar5 = pppppiVar16;
              pppppiVar16 = (int *****)pppppiVar16[2];
            }
          }
          else {
            do {
              pppppiVar16 = pppppiVar5;
              pppppiVar12 = (int *****)pppppiVar16[1];
              if (*(char *)((int)pppppiVar12 + 0x15) != '\0') break;
              pppppiVar5 = pppppiVar12;
            } while (pppppiVar16 == (int *****)*pppppiVar12);
            pppppiVar5 = pppppiVar16;
            if (*(char *)((int)pppppiVar16 + 0x15) == '\0') {
              pppppiVar5 = pppppiVar12;
            }
          }
        }
        else {
          pppppiVar5 = (int *****)pppppiVar5[2];
        }
      }
      pppppiVar10 = (int *****)pppppiVar5[3];
      pppppiVar16 = pppppiVar5;
      pppppiVar12 = pppppiVar4;
      if (pppppiVar10 < pppppiVar15) {
        pppppiVar16 = (int *****)&pppppiStack_68;
        pppppiVar5 = (int *****)func_0x810fabe4(pppppiVar4);
        cStack_70 = (char)pppppiVar10;
      }
    }
  }
LAB_8106010e:
  pppppiVar5[4] = ppppiStack_60;
  if (_UNK_8111a5b0 == ppppiStack_48) {
    return _UNK_8111a5b0;
  }
  uVar17 = 0x81060125;
  uVar20 = func_0x811185a0();
  piVar7 = (int *)((ulonglong)uVar20 >> 0x20);
  *piVar7 = 0;
  *pppppiVar5 = (int ****)0x0;
  piVar11 = *(int **)((int)uVar20 + 4);
  uVar9 = (uint)*(char *)((int)(int *)piVar11[1] + 0x15);
  piVar13 = piVar11;
  piVar14 = piVar11;
  piVar18 = (int *)piVar11[1];
  if (uVar9 == 0) {
    do {
      piVar14 = piVar18;
      uVar9 = piVar14[3];
      if (uVar9 < ((uint)pppppiVar16 & 0xff)) {
        piVar18 = (int *)piVar14[2];
        cVar1 = *(char *)((int)piVar18 + 0x15);
        piVar14 = piVar13;
      }
      else {
        piVar18 = (int *)*piVar14;
        cVar1 = *(char *)((int)piVar18 + 0x15);
      }
      piVar13 = piVar14;
    } while (cVar1 == '\0');
  }
  if ((piVar14 == piVar11) || (uVar9 = piVar14[3], ((uint)pppppiVar16 & 0xff) < uVar9)) {
    piVar14 = piVar11;
  }
  if (piVar14 == piVar11) {
    ppppiVar3 = (int ****)0x0;
  }
  else {
    iVar6 = piVar14[4];
    *piVar7 = iVar6;
    ppppiVar3 = (int ****)
                func_0x810783d6(iVar6,cStack_70,uVar9,piVar11,pppppiVar12,&UNK_8111a5b0,param_3,
                                uVar17);
    *pppppiVar5 = ppppiVar3;
    if (ppppiVar3 == (int ****)0x0) {
      ppppiVar3 = (int ****)0x0;
      *pppppiVar5 = (int ****)0x0;
      *piVar7 = 0;
    }
    else {
      ppppiVar3 = (int ****)0x1;
    }
  }
  return ppppiVar3;
}

