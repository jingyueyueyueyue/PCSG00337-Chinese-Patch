
void FUN_8109afd0(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  (**(code **)(*param_1 + 0x14))(param_1);
  piVar2 = param_1 + 3;
  if (piVar2 != param_2) {
    if (param_1[3] != 0) {
      if (piVar2 == (int *)param_1[5]) {
        func_0x8110ca84();
      }
      else {
        iVar1 = param_1[4];
        ((int *)param_1[5])[1] = iVar1;
        *(int *)(iVar1 + 8) = param_1[5];
      }
    }
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    iVar1 = *param_2;
    param_1[3] = iVar1;
    if (iVar1 == 0) {
      param_1[4] = 0;
      param_1[5] = 0;
    }
    else {
      param_1[4] = (int)param_2;
      param_1[5] = param_2[2];
      param_2[2] = (int)piVar2;
      *(int **)(param_1[5] + 4) = piVar2;
    }
  }
  (**(code **)(*param_1 + 0x10))(param_1);
  return;
}

