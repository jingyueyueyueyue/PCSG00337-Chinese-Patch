
void FUN_8107e868(undefined4 param_1,int param_2)

{
  int *piVar1;
  
  func_0x810800f2();
  piVar1 = *(int **)(param_2 + 0xc);
  piVar1[4] = 2000000;
  piVar1[3] = 0;
  if (*(int *)(*piVar1 + 0x14) == 1) {
    piVar1[4] = 1000000;
  }
  return;
}

