
void FUN_8107146c(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0xb8);
  if (piVar2 != param_2) {
    if (*(int *)(param_1 + 0xb8) != 0) {
      if (piVar2 == *(int **)(param_1 + 0xc0)) {
        func_0x81101ac4();
      }
      else {
        iVar1 = *(int *)(param_1 + 0xbc);
        (*(int **)(param_1 + 0xc0))[1] = iVar1;
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0xc0);
      }
    }
    *(undefined4 *)(param_1 + 0xb8) = 0;
    *(undefined4 *)(param_1 + 0xbc) = 0;
    *(undefined4 *)(param_1 + 0xc0) = 0;
    iVar1 = *param_2;
    *(int *)(param_1 + 0xb8) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0xbc) = 0;
      *(undefined4 *)(param_1 + 0xc0) = 0;
    }
    else {
      *(int **)(param_1 + 0xbc) = param_2;
      *(int *)(param_1 + 0xc0) = param_2[2];
      param_2[2] = (int)piVar2;
      *(int **)(*(int *)(param_1 + 0xc0) + 4) = piVar2;
    }
  }
  return;
}

