
void FUN_8107ca78(undefined4 *param_1)

{
  int **ppiVar1;
  int **ppiVar2;
  
  ppiVar1 = (int **)param_1[2];
  *param_1 = &UNK_81145de4;
  ppiVar2 = ppiVar1 + param_1[1];
  for (; ppiVar1 != ppiVar2; ppiVar1 = ppiVar1 + 1) {
    if (*ppiVar1 != (int *)0x0) {
      (**(code **)(**ppiVar1 + 4))();
    }
  }
  *param_1 = &UNK_81145d84;
  func_0x81005af0(param_1);
  return;
}

