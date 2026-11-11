
undefined4 * FUN_81083aaa(undefined4 *param_1)

{
  int **ppiVar1;
  
  ppiVar1 = (int **)param_1[1];
  *param_1 = &UNK_81146320;
  if (ppiVar1 != (int **)0x0) {
    if (*ppiVar1 != (int *)0x0) {
      (**(code **)(**ppiVar1 + 4))();
    }
    *ppiVar1 = (int *)0x0;
    func_0x81005af0(ppiVar1);
  }
  param_1[1] = 0;
  return param_1;
}

