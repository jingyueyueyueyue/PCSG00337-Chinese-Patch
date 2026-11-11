
int FUN_8109b50a(int param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x28);
  if (piVar3 != (int *)0x0) {
    piVar2 = piVar3 + *(int *)(param_1 + 0x2c) * 3;
    for (; piVar3 != piVar2; piVar3 = piVar3 + 3) {
      if (((*(byte *)(piVar3 + 1) & param_3) != 0) &&
         (iVar1 = func_0x811181a0(param_2,*(int *)(param_1 + 0x40) +
                                          *(int *)(*(int *)(param_1 + 0x3c) + *piVar3 * 4)),
         iVar1 == 0)) {
        return ((int)piVar3 - *(int *)(param_1 + 0x28)) / 0xc;
      }
    }
  }
  return -1;
}

