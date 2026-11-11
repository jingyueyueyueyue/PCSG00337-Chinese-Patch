
void FUN_8106b24a(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  return;
}

