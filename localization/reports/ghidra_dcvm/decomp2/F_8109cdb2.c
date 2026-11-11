
void FUN_8109cdb2(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x28);
  if (piVar2 != param_2) {
    if (*(int *)(param_1 + 0x28) != 0) {
      if (piVar2 == *(int **)(param_1 + 0x30)) {
        func_0x810c881c();
      }
      else {
        iVar1 = *(int *)(param_1 + 0x2c);
        (*(int **)(param_1 + 0x30))[1] = iVar1;
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x30);
      }
    }
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    iVar1 = *param_2;
    *(int *)(param_1 + 0x28) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    else {
      *(int **)(param_1 + 0x2c) = param_2;
      *(int *)(param_1 + 0x30) = param_2[2];
      param_2[2] = (int)piVar2;
      *(int **)(*(int *)(param_1 + 0x30) + 4) = piVar2;
    }
  }
  return;
}

