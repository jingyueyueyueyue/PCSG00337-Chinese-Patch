
void FUN_8108e766(int *param_1)

{
  int iVar1;
  
  if (-1 < *param_1) {
    iVar1 = func_0x81116d00(*param_1,0);
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    iVar1 = func_0x81116d30(*param_1);
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    *param_1 = -1;
  }
  return;
}

