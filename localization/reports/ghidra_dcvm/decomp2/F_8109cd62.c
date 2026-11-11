
void FUN_8109cd62(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x1c);
  if (piVar2 != param_2) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      if (piVar2 == *(int **)(param_1 + 0x24)) {
        func_0x810f937c();
      }
      else {
        iVar1 = *(int *)(param_1 + 0x20);
        (*(int **)(param_1 + 0x24))[1] = iVar1;
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x24);
      }
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    iVar1 = *param_2;
    *(int *)(param_1 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    else {
      *(int **)(param_1 + 0x20) = param_2;
      *(int *)(param_1 + 0x24) = param_2[2];
      param_2[2] = (int)piVar2;
      *(int **)(*(int *)(param_1 + 0x24) + 4) = piVar2;
    }
  }
  return;
}

