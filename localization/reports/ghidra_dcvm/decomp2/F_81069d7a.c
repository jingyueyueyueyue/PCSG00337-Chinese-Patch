
undefined4 * FUN_81069d7a(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &UNK_81144c38;
  (**(code **)(param_1[9] + 8))(param_1 + 9);
  piVar1 = (int *)*(int *)param_1[2];
  while (piVar1 != (int *)0x0) {
    piVar1[1] = piVar1[1] | 1;
    piVar1 = (int *)*piVar1;
  }
  (**(code **)(param_1[9] + 0xc))(param_1 + 9);
  FUN_8108170c(param_1);
  *param_1 = &UNK_81144c14;
  FUN_81081804(param_1);
  return param_1;
}

