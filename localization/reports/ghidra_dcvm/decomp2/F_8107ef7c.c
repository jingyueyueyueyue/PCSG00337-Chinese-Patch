
void FUN_8107ef7c(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[3];
  if (param_2 == 0) {
    param_2 = 1;
  }
  (**(code **)(*piVar1 + 8))(piVar1);
  (**(code **)(*param_1 + 8))(param_1,param_2);
  (**(code **)(*piVar1 + 0xc))(piVar1);
  return;
}

