
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_81081248(int **param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int **ppiVar3;
  uint uVar4;
  uint *puVar5;
  int unaff_r5;
  int unaff_r6;
  undefined4 uVar6;
  undefined8 uVar7;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int **ppiStack_3c;
  int iStack_38;
  int iStack_34;
  undefined *puStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  param_1[2] = (int *)0x1;
  if (((param_2 == 0) || (piVar1 = param_1[1], piVar1 == (int *)0x0)) || (*piVar1 == 0)) {
    iVar2 = 0;
  }
  else {
    unaff_r5 = (*param_1)[1];
    unaff_r6 = piVar1[1];
    iStack_1c = **param_1 + 8;
    uStack_28 = 0x81081655;
    iStack_20 = param_2;
    iVar2 = func_0x81118400(&iStack_20,unaff_r5 + unaff_r6 * 8 + 8,*piVar1,8);
    if (iVar2 != 0) {
      param_1[2] = (int *)0x0;
    }
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return iVar2;
  }
  uVar6 = 0x810812af;
  uVar7 = func_0x811185a0(iVar2);
  iVar2 = (int)((ulonglong)uVar7 >> 0x20);
  ppiVar3 = (int **)uVar7;
  puStack_30 = &UNK_8111a5b0;
  iStack_40 = _UNK_8111a5b0;
  ppiVar3[2] = (int *)0x1;
  ppiStack_3c = param_1;
  iStack_38 = unaff_r5;
  iStack_34 = unaff_r6;
  uStack_2c = uVar6;
  if (((iVar2 == 0) || (piVar1 = ppiVar3[1], piVar1 == (int *)0x0)) || (*piVar1 == 0)) {
    iVar2 = 0;
  }
  else {
    iStack_44 = **ppiVar3 + 8;
    iStack_48 = iVar2;
    iVar2 = func_0x81118400(&iStack_48,(*ppiVar3)[1] + piVar1[1] * 8 + 8,*piVar1,8,0x81081655);
    if (iVar2 != 0) {
      ppiVar3[2] = (int *)0x0;
    }
  }
  if (_UNK_8111a5b0 == iStack_40) {
    return iVar2;
  }
  uVar7 = func_0x811185a0(iVar2);
  uVar4 = (uint)((ulonglong)uVar7 >> 0x20);
  piVar1 = (int *)uVar7;
  puVar5 = (uint *)piVar1[1];
  piVar1[2] = 1;
  if (((puVar5 == (uint *)0x0) || (*puVar5 == 0)) || (*puVar5 <= uVar4)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*piVar1 + 4) +
            *(int *)(*(int *)(*piVar1 + 0x10) + (puVar5[1] + uVar4) * 4 + 8) * 8 + 8;
  }
  return iVar2;
}

