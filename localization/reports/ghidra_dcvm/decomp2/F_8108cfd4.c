
void FUN_8108cfd4(int param_1)

{
  int iVar1;
  
  param_1 = param_1 * 1000;
  if (param_1 == 0) {
    param_1 = 100;
  }
  iVar1 = func_0x81118870(param_1);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  return;
}

