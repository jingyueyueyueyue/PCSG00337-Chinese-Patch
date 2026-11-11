
void FUN_8106e686(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xac))(piVar1,param_1,param_2);
  }
  return;
}

