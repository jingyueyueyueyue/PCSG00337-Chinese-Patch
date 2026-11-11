
undefined4 * FUN_8107130c(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  *param_1 = &UNK_811456c8;
  if (param_1[0x2e] != 0) {
    if (param_1 + 0x2e == (undefined4 *)param_1[0x30]) {
      func_0x81101ac4();
    }
    else {
      iVar2 = param_1[0x2f];
      ((undefined4 *)param_1[0x30])[1] = iVar2;
      *(undefined4 *)(iVar2 + 8) = param_1[0x30];
    }
  }
  piVar1 = (int *)0x0;
  piVar3 = (int *)param_1[0x32];
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x32] = 0;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(piVar3);
    piVar1 = (int *)param_1[0x32];
  }
  param_1[0x37] = 0xffffffff;
  param_1[0x38] = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  param_1[0x32] = 0;
  if (param_1[0x2e] != 0) {
    if (param_1 + 0x2e == (undefined4 *)param_1[0x30]) {
      func_0x81101ac4();
    }
    else {
      iVar2 = param_1[0x2f];
      ((undefined4 *)param_1[0x30])[1] = iVar2;
      *(undefined4 *)(iVar2 + 8) = param_1[0x30];
    }
  }
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  return param_1;
}

