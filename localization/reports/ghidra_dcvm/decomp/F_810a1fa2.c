
/* WARNING: Possible PIC construction at 0x810a25a0: Changing call to branch */
/* WARNING: Possible PIC construction at 0x810a27a2: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x810a25a4) */
/* WARNING: Removing unreachable block (ram,0x810a25b4) */
/* WARNING: Removing unreachable block (ram,0x810a25d4) */
/* WARNING: Removing unreachable block (ram,0x810a2604) */
/* WARNING: Removing unreachable block (ram,0x810a260e) */
/* WARNING: Removing unreachable block (ram,0x810a261a) */
/* WARNING: Removing unreachable block (ram,0x810a2620) */
/* WARNING: Removing unreachable block (ram,0x810a25ce) */
/* WARNING: Removing unreachable block (ram,0x810a25ae) */
/* WARNING: Removing unreachable block (ram,0x810a2684) */
/* WARNING: Removing unreachable block (ram,0x810a269a) */
/* WARNING: Removing unreachable block (ram,0x810a26e0) */
/* WARNING: Removing unreachable block (ram,0x810a26f8) */
/* WARNING: Removing unreachable block (ram,0x810a2724) */
/* WARNING: Removing unreachable block (ram,0x810a2734) */
/* WARNING: Removing unreachable block (ram,0x810a2754) */
/* WARNING: Removing unreachable block (ram,0x810a27a8) */
/* WARNING: Removing unreachable block (ram,0x810a27c6) */
/* WARNING: Removing unreachable block (ram,0x810a27f6) */
/* WARNING: Removing unreachable block (ram,0x810a2800) */
/* WARNING: Removing unreachable block (ram,0x810a281a) */
/* WARNING: Removing unreachable block (ram,0x810a2820) */
/* WARNING: Removing unreachable block (ram,0x810a2854) */
/* WARNING: Removing unreachable block (ram,0x810a284a) */
/* WARNING: Removing unreachable block (ram,0x810a27be) */
/* WARNING: Removing unreachable block (ram,0x810a2784) */
/* WARNING: Removing unreachable block (ram,0x810a2694) */
/* WARNING: Removing unreachable block (ram,0x810a27a6) */
/* WARNING: Removing unreachable block (ram,0x810a28c8) */
/* WARNING: Removing unreachable block (ram,0x810a28de) */
/* WARNING: Removing unreachable block (ram,0x810a290a) */
/* WARNING: Removing unreachable block (ram,0x810a290c) */
/* WARNING: Removing unreachable block (ram,0x810a28d8) */
/* WARNING: Removing unreachable block (ram,0x810a2414) */
/* WARNING: Removing unreachable block (ram,0x810a23c4) */
/* WARNING: Removing unreachable block (ram,0x810a2444) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810a1fa2(short *param_1,int **param_2,int **param_3,int **param_4,int **param_5,
                 int **param_6,byte param_7,code *param_8)

{
  int *piVar1;
  int **ppiVar2;
  int *piVar3;
  int **ppiVar4;
  int **ppiVar5;
  int iVar6;
  int **ppiVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  undefined2 *puVar12;
  int *piVar13;
  int **ppiVar14;
  int ***pppiVar15;
  undefined2 uVar16;
  undefined4 uVar17;
  undefined8 uVar18;
  int **ppiStack_90;
  int *piStack_8c;
  int **ppiStack_88;
  code *pcStack_84;
  undefined2 uStack_80;
  int **ppiStack_7c;
  int *piStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined auStack_6c [8];
  undefined4 uStack_64;
  int *apiStack_60 [2];
  undefined4 uStack_58;
  int *apiStack_54 [2];
  undefined4 uStack_4c;
  int **ppiStack_48;
  short *psStack_44;
  int **ppiStack_40;
  code *pcStack_3c;
  byte bStack_38;
  code *pcStack_34;
  int **ppiStack_30;
  int *piStack_2c;
  
  piStack_2c = _UNK_8111a5b0;
  bStack_38 = param_7;
  ppiVar5 = param_4;
  if ((param_7 & 8) == 0) {
    uStack_74 = 0;
    uStack_70 = 0;
    piVar1 = (int *)(**(code **)(*(int *)(*param_2)[1] + 0x20))();
    iVar9 = *piVar1;
    if (iVar9 != 0) {
      pcStack_34 = param_8;
      uStack_4c = 0;
      ppiVar5 = apiStack_54;
      func_0x81080bb2(ppiVar5,param_5);
      ppiStack_90 = param_6;
      iVar9 = FUN_81079552(iVar9,&uStack_74,&uStack_70);
      func_0x81005af0(uStack_4c);
      param_8 = pcStack_34;
      uStack_4c = 0;
      if (iVar9 != 0) {
        ppiStack_90 = (int **)0x0;
        ppiVar5 = (int **)0x1;
        func_0x810a1800(param_2,uStack_74,uStack_70);
      }
    }
  }
  ppiStack_7c = (int **)0x0;
  piStack_78 = (int *)0x0;
  ppiStack_48 = param_6;
  ppiVar4 = *(int ***)(*(int *)(*param_2)[1] + 0x20);
  ppiStack_40 = param_4;
  pcStack_3c = param_8;
  ppiVar2 = (int **)(*(code *)ppiVar4)();
  piVar1 = *ppiVar2;
  if (piVar1 != (int *)0x0) {
    ppiVar5 = apiStack_60;
    ppiStack_48 = param_6;
    uStack_58 = 0;
    ppiStack_40 = param_4;
    pcStack_3c = param_8;
    pcStack_34 = param_8;
    ppiStack_30 = param_4;
    func_0x81080bb2(ppiVar5,param_5);
    ppiStack_90 = param_6;
    ppiVar4 = &piStack_78;
    piVar1 = (int *)FUN_81079552(piVar1,&ppiStack_7c);
    func_0x81005af0(uStack_58);
    param_4 = ppiStack_30;
    param_8 = pcStack_34;
    piVar3 = piStack_78;
    uStack_58 = 0;
    if (piVar1 != (int *)0x0) {
      param_6 = (int **)(uint)bStack_38;
      ppiStack_90 = ppiStack_7c;
      piStack_8c = piStack_78;
      pcStack_84 = pcStack_34;
      ppiVar4 = param_3;
      ppiVar5 = ppiStack_30;
      ppiStack_88 = param_6;
      func_0x810a1e48(param_1,param_2);
      goto LAB_810a21d6;
    }
  }
  piVar3 = piVar1;
  psStack_44 = param_1;
  func_0x810a170e(&uStack_80,*param_2 + 0x1f);
  if (uStack_80 == 0) {
    *param_1 = 0;
  }
  else {
    piVar1 = *param_2;
    (**(code **)(piVar1[0x28] + 8))(piVar1 + 0x28);
    param_1 = (short *)0x0;
    param_8 = *(code **)(piVar1[0x28] + 0xc);
    if ((char)uStack_80 == *(char *)(piVar1[0x25] + (uint)uStack_80._1_1_)) {
      param_1 = (short *)((uint)uStack_80._1_1_ * 0x34 + piVar1[0x20]);
    }
    (*param_8)(piVar1 + 0x28);
    uStack_64 = 0;
    func_0x81080bb2(auStack_6c,param_5);
    uVar17 = uStack_64;
    if (*(int *)(param_1 + 8) == 0) {
      func_0x81005b02(*(undefined4 *)(param_1 + 4));
    }
    *(undefined4 *)(param_1 + 6) = 0;
    *(undefined4 *)(param_1 + 8) = 1;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 10) = uRam81191264;
    iVar9 = func_0x81118330(uVar17);
    iVar6 = func_0x81005aaa(iVar9 + 1);
    *(int *)(param_1 + 4) = iVar6;
    if (iVar6 == 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    func_0x8109d75c(iVar6,iVar9 + 1,uVar17);
    *(undefined4 *)(param_1 + 8) = 0;
    *(int **)(param_1 + 10) = *ppiStack_48;
    *(int ***)(param_1 + 0xc) = ppiStack_40;
    *(undefined4 *)(param_1 + 0xe) = 1;
    *(byte *)(param_1 + 0x12) = bStack_38;
    func_0x81005af0(uStack_64);
    uStack_64 = 0;
    *(byte *)(param_1 + 0x12) = *(byte *)(param_1 + 0x12) & 0xfd;
    *param_3 = (int *)0x1;
    param_3[1] = (int *)0x0;
    *(int ***)(param_1 + 0x18) = param_3;
    piVar3 = *param_2;
    param_6 = (int **)(piVar3 + 0xf);
    param_4 = (int **)(piVar3 + 10);
    (**(code **)(piVar3[0xf] + 8))(param_6);
    ppiVar4 = (int **)(((uint)pcStack_3c & 0xff) + 1);
    func_0x8107e03a(param_4,param_1);
    (**(code **)(piVar3[0xf] + 0xc))(param_6);
    *psStack_44 = uStack_80;
  }
LAB_810a21d6:
  if (_UNK_8111a5b0 == piStack_2c) {
    return;
  }
  uVar17 = 0x810a21f1;
  uVar18 = func_0x811185a0();
  pppiVar15 = &ppiStack_90;
  do {
    piVar1 = _UNK_8111a5b0;
    ppiVar2 = (int **)((ulonglong)uVar18 >> 0x20);
    puVar12 = (undefined2 *)uVar18;
    pppiVar15[-1] = (int **)uVar17;
    pppiVar15[-2] = param_3;
    pppiVar15[-3] = param_5;
    pppiVar15[-4] = param_2;
    pppiVar15[-5] = (int **)param_8;
    pppiVar15[-6] = param_4;
    pppiVar15[-7] = (int **)param_1;
    pppiVar15[-8] = param_6;
    pppiVar15[-9] = (int **)piVar3;
    pppiVar15[-10] = (int **)_UNK_8111a5b0;
    ppiVar14 = pppiVar15[2];
    iVar9 = 0;
    pppiVar15[-0xc] = ppiVar5;
    *ppiVar5 = (int *)0x0;
    piVar13 = (int *)pppiVar15[1];
    piVar10 = (int *)0x811ade00;
    pppiVar15[-0xe] = ppiVar4;
    piVar11 = (int *)pppiVar15[3];
    pppiVar15[-0x14] = (int **)piVar13;
    ppiVar4 = (int **)((int)ppiRam811ade00 + 1);
    pppiVar15[-0x13] = ppiVar14;
    piVar3 = *ppiVar2;
    pppiVar15[-0x11] = *pppiVar15;
    ppiRam811ade00 = ppiVar4;
    if (piVar3[7] != 0) {
      func_0x8108caee(piVar3[7] + 0x1c);
      piVar3 = *ppiVar2;
    }
    if (piVar3[7] == 0) {
LAB_810a227c:
      ppiVar2 = (int **)(*ppiVar2)[7];
      if (ppiVar2 != (int **)0x0) {
        func_0x8108cb0a(ppiVar2 + 7);
      }
      *puVar12 = 0;
    }
    else {
      ppiVar4 = (int **)0x1;
      iVar9 = func_0x810772be(piVar3[7],pppiVar15 + -0x14);
      if (iVar9 == 0) goto LAB_810a227c;
      if (((uint)piVar11 & 1) == 0) {
        func_0x810770f8(iVar9);
      }
      pppiVar15[-0x10] = (int **)iVar9;
      func_0x81077368(iVar9);
      if ((*(uint *)(iVar9 + 0x18) & 2) != 0) goto LAB_810a227c;
      piVar1 = (int *)(*ppiVar2)[1];
      iVar6 = *piVar1;
      pppiVar15[-0x12] = (int **)piVar11;
      uVar17 = (**(code **)(iVar6 + 0x38))(piVar1,piVar13,ppiVar14);
      ppiVar7 = (int **)(*ppiVar2)[1];
      piVar1 = *ppiVar7;
      pppiVar15[-0xf] = (int **)uVar17;
      ppiVar5 = (int **)piVar1[0x10];
      ppiVar4 = ppiVar14;
      uVar17 = (*(code *)ppiVar5)(ppiVar7,piVar13);
      piVar3 = *ppiVar2;
      if (((uint)piVar11 & 4) != 0) {
        uVar17 = 0;
      }
      pppiVar15[-0xd] = (int **)uVar17;
      pppiVar15[-0xb] = (int **)puVar12;
      func_0x810a170e(pppiVar15 + -0x16,piVar3 + 0x1f);
      if (*(short *)(pppiVar15 + -0x16) == 0) {
        ppiVar2 = (int **)(*ppiVar2)[7];
        uVar16 = 0;
        if (ppiVar2 != (int **)0x0) {
          func_0x8108cb0a(ppiVar2 + 7);
          uVar16 = *(undefined2 *)(pppiVar15 + -0x16);
        }
        *puVar12 = uVar16;
      }
      else {
        piVar10 = *ppiVar2;
        (**(code **)(piVar10[0x28] + 8))(piVar10 + 0x28);
        puVar12 = (undefined2 *)0x0;
        if (*(char *)(pppiVar15 + -0x16) ==
            *(char *)(piVar10[0x25] + (uint)*(byte *)((int)pppiVar15 + -0x57))) {
          puVar12 = (undefined2 *)((uint)*(byte *)((int)pppiVar15 + -0x57) * 0x34 + piVar10[0x20]);
        }
        (**(code **)(piVar10[0x28] + 0xc))(piVar10 + 0x28);
        uVar17 = pppiVar15[-0xe];
        *(undefined4 *)(puVar12 + 0x14) = 0;
        *(undefined4 *)(puVar12 + 0x16) = 0;
        *(undefined4 *)(puVar12 + 0x18) = uVar17;
        if (*(int *)(puVar12 + 8) == 0) {
          func_0x81005b02(*(undefined4 *)(puVar12 + 4));
        }
        *(int **)(puVar12 + 4) = piVar13;
        *(int ***)(puVar12 + 6) = ppiVar14;
        uVar17 = pppiVar15[-0x12];
        iVar9 = piVar13[10];
        *(undefined4 *)(puVar12 + 8) = 1;
        *(int *)(puVar12 + 10) = iVar9;
        *(byte *)(puVar12 + 0x12) = (byte)uVar17 & 0xfd;
        *(undefined *)(puVar12 + 0x13) = 3;
        iRam811addfc = iRam811addfc + 1;
        piVar3 = (int *)pppiVar15[-0x11];
        iVar9 = (int)pppiVar15[-0xf];
        if (pppiVar15[-0xd] == (int **)0x0) {
          piVar11 = *ppiVar2 + 0x2a;
          if (iVar9 == 0) {
            iVar9 = 1;
          }
          if (piVar11 == (int *)0x0) {
            piVar11 = piVar3 + 9;
          }
          ppiVar5 = (int **)&UNK_811388fc;
          piVar1 = *(int **)(*piVar3 + 0xc);
          piVar11 = (int *)(*(code *)piVar1)(piVar3,iVar9,piVar11);
          iVar9 = 0;
          if (piVar11 != (int *)0x0) {
            ppiVar4 = pppiVar15[-0xf];
            func_0x8108d65a(piVar11,*(undefined4 *)((int)pppiVar15[-0x10] + 0x10));
            iVar9 = 0;
            piVar13 = (int *)pppiVar15[-0x11];
            *(byte *)(puVar12 + 0x13) = *(byte *)(puVar12 + 0x13) | 1;
LAB_810a2462:
            ppiVar7 = pppiVar15[-0xc];
            *ppiVar7 = piVar11;
            *(int ***)(puVar12 + 0xc) = ppiVar7;
            *(undefined4 *)(puVar12 + 0xe) = 0;
            *(int *)(puVar12 + 0x10) = iVar9;
            *(int **)(puVar12 + 2) = piVar13;
            piVar10 = *ppiVar2;
            iVar9 = piVar10[7];
            if (iVar9 != 0) {
              func_0x8108cb0a(iVar9 + 0x1c);
              piVar10 = *ppiVar2;
            }
            if (pppiVar15[-0xd] == (int **)0x0) {
              func_0x810a1ab2(piVar10 + 0x1f,puVar12);
            }
            else {
              piVar1 = piVar10 + 0x1b;
              piVar11 = piVar10 + 0x16;
              (**(code **)(piVar10[0x1b] + 8))(piVar1);
              ppiVar4 = (int **)0x1;
              func_0x8107e03a(piVar11,puVar12);
              (**(code **)(piVar10[0x1b] + 0xc))(piVar1);
            }
            *(undefined2 *)pppiVar15[-0xb] = *(undefined2 *)(pppiVar15 + -0x16);
            goto LAB_810a2514;
          }
        }
        else {
          ppiVar5 = (int **)(*ppiVar2 + 0x2c);
          piVar3 = (int *)**ppiVar2;
          if (iVar9 == 0) {
            iVar9 = 1;
          }
          if (ppiVar5 == (int **)0x0) {
            ppiVar5 = (int **)(piVar3 + 9);
          }
          piVar1 = *(int **)(*piVar3 + 0xc);
          iVar9 = (*(code *)piVar1)(piVar3,iVar9,ppiVar5,&UNK_811388fc);
          piVar11 = (int *)0x0;
          if (iVar9 != 0) {
            iVar6 = (int)pppiVar15[-0xd];
            piVar13 = (int *)pppiVar15[-0x11];
            piVar3 = *ppiVar2 + 0x2a;
            if (iVar6 == 0) {
              iVar6 = 1;
            }
            if (piVar3 == (int *)0x0) {
              piVar3 = piVar13 + 9;
            }
            ppiVar5 = (int **)&UNK_811388fc;
            piVar1 = *(int **)(*piVar13 + 0xc);
            piVar11 = (int *)(*(code *)piVar1)(piVar13,iVar6,piVar3);
            if (piVar11 != (int *)0x0) {
              ppiVar4 = pppiVar15[-0xf];
              func_0x8108d65a(iVar9,*(undefined4 *)((int)pppiVar15[-0x10] + 0x10));
              goto LAB_810a2462;
            }
          }
        }
        ppiVar4 = (int **)*ppiVar2;
        if (ppiVar4[7] != (int *)0x0) {
          func_0x8108cb0a(ppiVar4[7] + 7);
          ppiVar4 = (int **)*ppiVar2;
        }
        ppiVar5 = ppiVar4;
        if (puVar12 != (undefined2 *)0x0) {
          func_0x810a1ab2(ppiVar4 + 0x1f,puVar12);
          ppiVar4 = (int **)*ppiVar2;
        }
        if (iVar9 != 0) {
          piVar3 = *ppiVar4;
          ppiVar4 = *(int ***)(*piVar3 + 0x10);
          (*(code *)ppiVar4)(piVar3,iVar9);
        }
        if (piVar11 != (int *)0x0) {
          ppiVar4 = *(int ***)((int)*pppiVar15[-0x11] + 0x10);
          (*(code *)ppiVar4)(pppiVar15[-0x11],piVar11);
        }
        *(undefined2 *)pppiVar15[-0xb] = 0;
      }
    }
LAB_810a2514:
    if ((int **)_UNK_8111a5b0 == pppiVar15[-10]) {
      return;
    }
    uVar17 = 0x810a252f;
    uVar18 = func_0x811185a0();
    param_2 = (int **)((ulonglong)uVar18 >> 0x20);
    param_8 = (code *)uVar18;
    pppiVar15[-0x17] = (int **)uVar17;
    pppiVar15[-0x18] = ppiVar14;
    pppiVar15[-0x19] = ppiVar2;
    pppiVar15[-0x1a] = (int **)piVar13;
    pppiVar15[-0x1b] = (int **)puVar12;
    pppiVar15[-0x1c] = (int **)iVar9;
    pppiVar15[-0x1d] = (int **)piVar11;
    pppiVar15[-0x1e] = (int **)piVar10;
    pppiVar15[-0x1f] = (int **)piVar1;
    pppiVar15[-0x21] = (int **)_UNK_8111a5b0;
    uVar8 = (uint)pppiVar15[-0x13];
    param_1 = (short *)pppiVar15[-0x14];
    uVar17 = pppiVar15[-0x12];
    param_4 = pppiVar15[-0x16];
    param_3 = pppiVar15[-0x15];
    *(char *)(pppiVar15 + -0x22) = (char)uVar8;
    pppiVar15[-0x23] = (int **)uVar17;
    *ppiVar5 = (int *)0x0;
    if ((uVar8 & 8) == 0) {
      pppiVar15[-0x2c] = (int **)0x0;
      func_0x810a1800(param_2,param_3,param_1,uVar17);
    }
    pppiVar15[-0x26] = (int **)param_1;
    pppiVar15[-0x25] = param_4;
    uVar18 = CONCAT44(param_2,(int)pppiVar15 + -0x9e);
    piVar3 = (int *)(uint)*(byte *)(pppiVar15 + -0x22);
    pppiVar15[-0x27] = ppiVar5;
    pppiVar15[-0x2c] = param_4;
    pppiVar15[-0x2b] = param_3;
    pppiVar15[-0x2a] = (int **)param_1;
    pppiVar15[-0x29] = (int **)piVar3;
    uVar17 = 0x810a25a5;
    param_6 = ppiVar5;
    param_5 = ppiVar4;
    pppiVar15 = pppiVar15 + -0x2c;
  } while( true );
}

