
void FUN_810808b4(undefined4 param_1,int **param_2)

{
  int *piVar1;
  
  piVar1 = *param_2;
  while (piVar1 != (int *)0x0) {
    if (piVar1 != (int *)0x0) {
      *param_2 = (int *)piVar1[1];
      piVar1[1] = 0;
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    piVar1 = *param_2;
  }
  return;
}

