
void FUN_8109cd16(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x10);
  if (piVar2 != param_2) {
    if (*(int *)(param_1 + 0x10) != 0) {
      if (piVar2 == *(int **)(param_1 + 0x18)) {
        func_0x810f936c();
      }
      else {
        iVar1 = *(int *)(param_1 + 0x14);
        (*(int **)(param_1 + 0x18))[1] = iVar1;
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x18);
      }
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    iVar1 = *param_2;
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else {
      *(int **)(param_1 + 0x14) = param_2;
      *(int *)(param_1 + 0x18) = param_2[2];
      param_2[2] = (int)piVar2;
      *(int **)(*(int *)(param_1 + 0x18) + 4) = piVar2;
    }
  }
  return;
}

