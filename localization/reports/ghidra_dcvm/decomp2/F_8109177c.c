
undefined4 FUN_8109177c(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0xc))();
  iVar2 = param_1[3];
  if (iVar2 < 1) {
    if (iVar2 < 0) {
      return 0;
    }
    if (iVar1 == 0) {
      return 0;
    }
    param_1[3] = 1;
  }
  else if (1 < iVar2) {
    return 0;
  }
  if (iVar1 == 2) {
    param_1[3] = 2;
    (**(code **)(*param_1 + 0x10))(param_1);
    (**(code **)(*param_1 + 0x14))(param_1);
    if (((code *)param_1[5] != (code *)0x0) &&
       (iVar1 = (*(code *)param_1[5])(param_1,param_1[4]), iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}

