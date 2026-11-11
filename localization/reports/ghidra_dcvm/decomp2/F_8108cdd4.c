
int ** FUN_8108cdd4(int **param_1)

{
  int *piVar1;
  
  func_0x8109db68();
  piVar1 = *param_1;
  if (((piVar1 != (int *)0x0) && (param_1 != ppiRam811adc54)) && (-1 < *piVar1)) {
    func_0x811186c0(*piVar1,0,0);
    piVar1 = *param_1;
    *piVar1 = -1;
  }
  if (piVar1 != (int *)0x0) {
    *param_1 = (int *)0x0;
    func_0x81005af0();
    if (*param_1 != (int *)0x0) {
      func_0x81005af0();
    }
  }
  *param_1 = (int *)0x0;
  return param_1;
}

