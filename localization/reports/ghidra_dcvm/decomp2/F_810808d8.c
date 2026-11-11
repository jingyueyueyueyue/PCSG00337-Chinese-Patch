
undefined4 * FUN_810808d8(undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  *param_1 = &UNK_81146268;
  while (piVar1 != (int *)0x0) {
    param_1[1] = piVar1[1];
    piVar1[1] = 0;
    (**(code **)(*piVar1 + 4))(piVar1);
    piVar1 = (int *)param_1[1];
  }
  piVar1 = (int *)param_1[2];
  while (piVar1 != (int *)0x0) {
    param_1[2] = piVar1[1];
    piVar1[1] = 0;
    (**(code **)(*piVar1 + 4))(piVar1);
    piVar1 = (int *)param_1[2];
  }
  return param_1;
}

