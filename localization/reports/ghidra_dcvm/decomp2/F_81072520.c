
undefined4 * FUN_81072520(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = &UNK_811456f0;
  FUN_810724c0(param_1);
  FUN_81072488(param_1);
  FUN_81072450(param_1);
  piVar2 = (int *)param_1[1];
  piVar1 = (int *)0x0;
  param_1[1] = 0;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
    piVar1 = (int *)param_1[1];
  }
  param_1[2] = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  param_1[1] = 0;
  return param_1;
}

