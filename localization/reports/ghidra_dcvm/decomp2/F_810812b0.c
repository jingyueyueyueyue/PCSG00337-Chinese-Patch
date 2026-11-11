
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_810812b0(int **param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined8 uVar5;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  param_1[2] = (int *)0x1;
  if (((param_2 == 0) || (piVar1 = param_1[1], piVar1 == (int *)0x0)) || (*piVar1 == 0)) {
    iVar2 = 0;
  }
  else {
    iStack_1c = **param_1 + 8;
    iStack_20 = param_2;
    iVar2 = func_0x81118400(&iStack_20,(*param_1)[1] + piVar1[1] * 8 + 8,*piVar1,8,0x81081655);
    if (iVar2 != 0) {
      param_1[2] = (int *)0x0;
    }
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return iVar2;
  }
  uVar5 = func_0x811185a0(iVar2);
  uVar3 = (uint)((ulonglong)uVar5 >> 0x20);
  piVar1 = (int *)uVar5;
  puVar4 = (uint *)piVar1[1];
  piVar1[2] = 1;
  if (((puVar4 == (uint *)0x0) || (*puVar4 == 0)) || (*puVar4 <= uVar3)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*piVar1 + 4) +
            *(int *)(*(int *)(*piVar1 + 0x10) + (puVar4[1] + uVar3) * 4 + 8) * 8 + 8;
  }
  return iVar2;
}

