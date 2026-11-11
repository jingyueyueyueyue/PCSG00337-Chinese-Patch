
void FUN_8107b040(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    piVar1 = *(int **)(param_1 + 0x14);
    if (piVar1 != (int *)0x0) {
      if (piVar1[2] != 0) {
        func_0x8107ac88();
        piVar1 = *(int **)(param_1 + 0x14);
      }
      (**(code **)(*piVar1 + 0xc))(piVar1);
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 4;
  } while (iVar2 < 8);
  return;
}

