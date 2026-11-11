
undefined4 * FUN_8109064a(undefined4 *param_1)

{
  int **ppiVar1;
  
  *param_1 = &UNK_81146724;
  FUN_8107e2ca(param_1);
  ppiVar1 = (int **)param_1[0xe2];
  param_1[0xe2] = 0;
  if (ppiVar1 != (int **)0x0) {
    if (ppiVar1[1] != (int *)0x0) {
      (**(code **)(*ppiVar1[1] + 4))();
    }
    ppiVar1[1] = (int *)0x0;
    if (*ppiVar1 != (int *)0x0) {
      (**(code **)(**ppiVar1 + 4))();
    }
    *ppiVar1 = (int *)0x0;
    func_0x81005af0(ppiVar1);
    ppiVar1 = (int **)param_1[0xe2];
    if (ppiVar1 != (int **)0x0) {
      if (ppiVar1[1] != (int *)0x0) {
        (**(code **)(*ppiVar1[1] + 4))();
      }
      ppiVar1[1] = (int *)0x0;
      if (*ppiVar1 != (int *)0x0) {
        (**(code **)(**ppiVar1 + 4))();
      }
      *ppiVar1 = (int *)0x0;
      func_0x81005af0(ppiVar1);
    }
  }
  param_1[0xe2] = 0;
  func_0x8107e25a(param_1);
  return param_1;
}

