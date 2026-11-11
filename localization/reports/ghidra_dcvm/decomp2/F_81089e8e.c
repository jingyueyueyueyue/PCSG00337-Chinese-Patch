
void FUN_81089e8e(int *param_1)

{
  int iVar1;
  
  if (param_1[3] != 0) {
    iVar1 = func_0x81116ab0(*(undefined4 *)(*param_1 + 0x10));
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    param_1[3] = 0;
  }
  if (*param_1 != 0) {
    if (param_1 == (int *)param_1[2]) {
      func_0x810cf3ec();
    }
    else {
      iVar1 = param_1[1];
      ((int *)param_1[2])[1] = iVar1;
      *(int *)(iVar1 + 8) = param_1[2];
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

