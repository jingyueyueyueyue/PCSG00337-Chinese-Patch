
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8107f01c(undefined4 *param_1,int param_2,int param_3)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  
  *param_1 = 0;
  iVar3 = *(int *)(*(int *)(param_2 + 0x1c) + param_3 * 0x24);
  if (iVar3 != 0) {
    iVar2 = iVar3 - *(int *)(param_2 + 0x10);
    lVar1 = (longlong)_DAT_8107f048;
    *(undefined2 *)param_1 = *(undefined2 *)(iVar3 + 0x1e);
    *(short *)((int)param_1 + 2) = (short)(int)(lVar1 * iVar2 >> 0x24) - (short)(iVar2 >> 0x1f);
  }
  return;
}

