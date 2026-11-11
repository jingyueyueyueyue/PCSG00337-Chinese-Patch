
/* WARNING: Possible PIC construction at 0x8109538e: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x81095392) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810951ba(int param_1,uint *param_2,undefined4 param_3,int param_4)

{
  undefined2 uVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  int unaff_r6;
  int unaff_r7;
  int unaff_r8;
  undefined *unaff_r9;
  int *piVar12;
  int iVar13;
  undefined8 uVar14;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  piVar12 = &iStack_18;
  puVar11 = &UNK_8111a5b0;
  iStack_10 = _UNK_8111a5b0;
  if ((*param_2 & 0xf) == 6) {
    puVar2 = (undefined *)param_2[1];
  }
  else {
    func_0x810964f6(param_2,&iStack_18,&iStack_14);
    puVar2 = &UNK_81138164;
    if (iStack_14 != 0) {
      param_4 = *(int *)(*(int *)(param_1 + 0x28) + 0x74);
      if (param_4 == iStack_18) {
        puVar2 = (undefined *)func_0x8109b066();
      }
      else {
        puVar4 = (undefined4 *)func_0x8109ca34(*(undefined4 *)(param_1 + 0x40));
        uVar5 = func_0x8109c2ae(*puVar4,iStack_18);
        puVar2 = (undefined *)func_0x8109b066(uVar5,iStack_14);
      }
    }
  }
  if (_UNK_8111a5b0 == iStack_10) {
    return;
  }
  iVar13 = -0x7ef6addb;
  iVar6 = iStack_10;
  uVar14 = func_0x811185a0(puVar2);
  do {
    iVar10 = param_4;
    iVar9 = iVar6;
    iVar6 = _UNK_8111a5b0;
    iVar3 = (int)uVar14;
    piVar12[-1] = iVar13;
    piVar12[-2] = (int)unaff_r9;
    piVar12[-3] = unaff_r8;
    piVar12[-4] = unaff_r7;
    piVar12[-5] = unaff_r6;
    piVar12[-6] = (int)puVar11;
    piVar12[-7] = param_1;
    unaff_r9 = &UNK_8111a5b0;
    piVar12[-9] = _UNK_8111a5b0;
    puVar4 = (undefined4 *)
             func_0x8109b5e0(*(undefined4 *)(iVar3 + 0x28),(int)((ulonglong)uVar14 >> 0x20));
    if ((*(ushort *)((int)puVar4 + 6) & 4) == 0) {
      if (iVar10 == 3) goto LAB_81095286;
      *(undefined4 *)(iVar3 + 0x34) = 3;
      *(undefined **)(iVar3 + 0x38) = &UNK_81096439;
      uVar5 = 0xffffffff;
    }
    else if (iVar10 == 6) {
LAB_81095286:
      uVar5 = *puVar4;
      if ((*(ushort *)((int)puVar4 + 6) & 1) == 0) {
        iVar6 = func_0x8109b066(*(undefined4 *)(iVar3 + 0x28));
        if ((*(ushort *)((int)puVar4 + 6) & 2) == 0) {
          uVar1 = *(undefined2 *)(puVar4 + 1);
          piVar12[-0xc] = iVar10;
          iVar13 = func_0x8109d626(iVar9,piVar12 + -10,iVar6,uVar1);
          if (iVar13 == 0) {
            iVar8 = piVar12[-10];
            if (iVar8 < 2) {
              if (iVar8 < 1) {
LAB_810952ce:
                *(undefined4 *)(iVar3 + 0x34) = 3;
                *(undefined **)(iVar3 + 0x38) = &UNK_81096439;
              }
              else {
                if (iVar10 == 6) {
                  iVar13 = func_0x8109d338(iVar9,iVar6);
                  if (iVar13 == 0) {
                    *(undefined4 *)(iVar3 + 0x34) = 3;
                    *(undefined **)(iVar3 + 0x38) = &UNK_81096439;
                    uVar5 = 0xffffffff;
                  }
                  else {
                    if ((uint)*(ushort *)(puVar4 + 1) <= *(uint *)(iVar13 + 0xc)) goto LAB_8109534e;
                    *(undefined4 *)(iVar3 + 0x34) = 3;
                    *(undefined **)(iVar3 + 0x38) = &UNK_81096439;
                    uVar5 = 0xffffffff;
                  }
                  goto LAB_81095364;
                }
                *(undefined4 *)(iVar3 + 0x34) = 3;
                *(undefined **)(iVar3 + 0x38) = &UNK_81096439;
              }
            }
            else if (iVar8 < 3) {
              *(undefined4 *)(iVar3 + 0x34) = 3;
              *(undefined **)(iVar3 + 0x38) = &UNK_81096439;
            }
            else {
              if (3 < iVar8) goto LAB_810952ce;
              *(undefined4 *)(iVar3 + 0x34) = 3;
              *(undefined **)(iVar3 + 0x38) = &UNK_81096439;
            }
LAB_8109534e:
            if (iVar13 == 0) {
              uVar5 = 0xffffffff;
              goto LAB_81095364;
            }
          }
        }
        else {
          iVar13 = func_0x8109d338(iVar9,iVar6);
        }
        uVar5 = *(undefined4 *)(iVar13 + 8);
        *puVar4 = uVar5;
        *(ushort *)((int)puVar4 + 6) = *(ushort *)((int)puVar4 + 6) | 1;
      }
    }
    else {
      *(undefined4 *)(iVar3 + 0x34) = 3;
      *(undefined **)(iVar3 + 0x38) = &UNK_81096439;
      uVar5 = 0xffffffff;
    }
LAB_81095364:
    if (_UNK_8111a5b0 == piVar12[-9]) {
      return;
    }
    iVar13 = -0x7ef6ac87;
    uVar14 = func_0x811185a0(uVar5);
    puVar11 = (undefined *)((ulonglong)uVar14 >> 0x20);
    param_1 = (int)uVar14;
    piVar12[-0xd] = iVar13;
    piVar12[-0xe] = iVar3;
    piVar12[-0xf] = (int)puVar4;
    piVar12 = piVar12 + -0x10;
    *piVar12 = iVar6;
    piVar7 = (int *)func_0x8109cdfe(*(undefined4 *)(param_1 + 0x40));
    iVar13 = -0x7ef6ac6d;
    iVar6 = *piVar7;
    param_4 = 3;
    unaff_r6 = iVar3;
    unaff_r7 = iVar9;
    unaff_r8 = iVar10;
  } while( true );
}

