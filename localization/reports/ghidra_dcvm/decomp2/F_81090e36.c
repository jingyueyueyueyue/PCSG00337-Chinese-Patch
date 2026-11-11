
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81090e36(int param_1,int param_2,undefined param_3)

{
  int *piVar1;
  
  piVar1 = **(int ***)(param_1 + 0x2c);
  piVar1 = *(int **)(piVar1[4] +
                    ((int)((longlong)_DAT_81090e64 * (longlong)(param_2 - *piVar1) >> 0x24) -
                    (param_2 - *piVar1 >> 0x1f)) * piVar1[5]);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,param_3);
  }
  return;
}

