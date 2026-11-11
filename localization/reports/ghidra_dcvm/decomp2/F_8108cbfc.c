
int ** FUN_8108cbfc(int **param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *param_1;
  if (-1 < *piVar1) {
    iVar2 = func_0x81118840(*piVar1);
    piVar1 = *param_1;
    if (iVar2 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
  }
  if (piVar1 != (int *)0x0) {
    func_0x81005af0();
  }
  *param_1 = (int *)0x0;
  return param_1;
}

