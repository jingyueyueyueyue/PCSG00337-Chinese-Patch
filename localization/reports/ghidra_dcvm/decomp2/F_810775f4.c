
void FUN_810775f4(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x1c4);
  if (piVar2 != param_2) {
    if (*(int *)(param_1 + 0x1c4) != 0) {
      if (piVar2 == *(int **)(param_1 + 0x1cc)) {
        func_0x81101b54();
      }
      else {
        iVar1 = *(int *)(param_1 + 0x1c8);
        (*(int **)(param_1 + 0x1cc))[1] = iVar1;
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x1cc);
      }
    }
    *(undefined4 *)(param_1 + 0x1c4) = 0;
    *(undefined4 *)(param_1 + 0x1c8) = 0;
    *(undefined4 *)(param_1 + 0x1cc) = 0;
    iVar1 = *param_2;
    *(int *)(param_1 + 0x1c4) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x1c8) = 0;
      *(undefined4 *)(param_1 + 0x1cc) = 0;
    }
    else {
      *(int **)(param_1 + 0x1c8) = param_2;
      *(int *)(param_1 + 0x1cc) = param_2[2];
      param_2[2] = (int)piVar2;
      *(int **)(*(int *)(param_1 + 0x1cc) + 4) = piVar2;
    }
  }
  return;
}

