
void FUN_8107a6ac(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int **)(param_1 + 0x14) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x14) + 0x18))();
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 4;
  } while (iVar1 < 8);
  return;
}

