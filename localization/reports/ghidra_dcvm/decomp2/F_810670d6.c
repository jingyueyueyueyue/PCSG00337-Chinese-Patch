
void FUN_810670d6(int **param_1,char param_2)

{
  int *piVar1;
  
  piVar1 = *param_1;
  if ((param_2 == '\0') || (piVar1 == (int *)0x0)) {
    *param_1 = (int *)0x0;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))();
    }
  }
  else {
    func_0x81072692(piVar1,200);
  }
  piVar1 = param_1[5];
  param_1[5] = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  piVar1 = param_1[4];
  param_1[4] = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  return;
}

