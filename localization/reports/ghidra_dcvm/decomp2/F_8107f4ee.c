
void FUN_8107f4ee(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar1 + 8))(piVar1);
  func_0x8107f15e(param_1,param_2);
  (**(code **)(*piVar1 + 0xc))(piVar1);
  return;
}

