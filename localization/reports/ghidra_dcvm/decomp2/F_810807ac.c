
void FUN_810807ac(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x30);
  if (piVar2 != param_2) {
    if (*(int *)(param_1 + 0x30) != 0) {
      if (piVar2 == *(int **)(param_1 + 0x38)) {
        func_0x81101b54();
      }
      else {
        iVar1 = *(int *)(param_1 + 0x34);
        (*(int **)(param_1 + 0x38))[1] = iVar1;
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x38);
      }
    }
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    iVar1 = *param_2;
    *(int *)(param_1 + 0x30) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x34) = 0;
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    else {
      *(int **)(param_1 + 0x34) = param_2;
      *(int *)(param_1 + 0x38) = param_2[2];
      param_2[2] = (int)piVar2;
      *(int **)(*(int *)(param_1 + 0x38) + 4) = piVar2;
    }
  }
  return;
}

