
void FUN_8107e490(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if ((piVar1 != (int *)0x0) && (*(char *)(piVar1 + 1) != '\0')) {
    (**(code **)(*piVar1 + 8))();
    piVar1 = *(int **)(param_1 + 8);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  return;
}

