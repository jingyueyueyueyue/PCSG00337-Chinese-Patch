
undefined4 * FUN_8107e4d4(undefined4 *param_1)

{
  int *piVar1;
  code *pcVar2;
  
  piVar1 = (int *)param_1[1];
  *param_1 = &UNK_81145fd0;
  if ((piVar1 != (int *)0x0) && (*(char *)(piVar1 + 6) != '\0')) {
    (**(code **)(*piVar1 + 0xc))();
    piVar1 = (int *)param_1[1];
  }
  param_1[1] = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    if (*(char *)(piVar1 + 1) != '\0') {
      (**(code **)(*piVar1 + 8))();
      piVar1 = (int *)param_1[2];
    }
    if (piVar1 != (int *)0x0) {
      pcVar2 = *(code **)(*piVar1 + 4);
      param_1[2] = 0;
      (*pcVar2)();
      if ((int *)param_1[2] != (int *)0x0) {
        (**(code **)(*(int *)param_1[2] + 4))();
      }
    }
  }
  param_1[2] = 0;
  if ((int *)param_1[1] != (int *)0x0) {
    (**(code **)(*(int *)param_1[1] + 4))();
  }
  param_1[1] = 0;
  return param_1;
}

