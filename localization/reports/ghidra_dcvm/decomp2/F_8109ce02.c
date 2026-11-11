
void FUN_8109ce02(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x34);
  if (piVar2 != param_2) {
    if (*(int *)(param_1 + 0x34) != 0) {
      if (piVar2 == *(int **)(param_1 + 0x3c)) {
        func_0x810c881c();
      }
      else {
        iVar1 = *(int *)(param_1 + 0x38);
        (*(int **)(param_1 + 0x3c))[1] = iVar1;
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x3c);
      }
    }
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    iVar1 = *param_2;
    *(int *)(param_1 + 0x34) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x38) = 0;
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    else {
      *(int **)(param_1 + 0x38) = param_2;
      *(int *)(param_1 + 0x3c) = param_2[2];
      param_2[2] = (int)piVar2;
      *(int **)(*(int *)(param_1 + 0x3c) + 4) = piVar2;
    }
  }
  return;
}

