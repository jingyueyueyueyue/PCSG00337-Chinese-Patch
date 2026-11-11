
void FUN_8107e4b2(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if ((piVar1 != (int *)0x0) && (*(char *)(piVar1 + 6) != '\0')) {
    (**(code **)(*piVar1 + 0xc))();
    piVar1 = *(int **)(param_1 + 4);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  return;
}

