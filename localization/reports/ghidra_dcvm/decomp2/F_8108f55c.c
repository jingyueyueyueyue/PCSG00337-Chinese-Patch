
void FUN_8108f55c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  FUN_8107e2a0();
  iVar2 = *(int *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  if (iVar2 < 2) {
    if (-1 < iVar2) {
      if (iVar2 < 1) {
        piVar1 = *(int **)(*(int *)(param_1 + 0x388) + 4);
        piVar1[2] = 0;
        (**(code **)(*piVar1 + 8))();
      }
      else {
        piVar1 = *(int **)(*(int *)(param_1 + 0x388) + 4);
        piVar1[2] = 0;
        (**(code **)(*piVar1 + 8))();
      }
    }
  }
  else if (iVar2 < 3) {
    piVar1 = *(int **)(*(int *)(param_1 + 0x388) + 4);
    piVar1[2] = 0xf;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  else if (iVar2 < 4) {
    piVar1 = *(int **)(*(int *)(param_1 + 0x388) + 4);
    piVar1[2] = 0xf;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}

