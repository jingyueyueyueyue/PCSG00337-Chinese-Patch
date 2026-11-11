
int FUN_810943c0(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x20) != '\0') {
    iVar1 = func_0x81118580(param_1);
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    *(undefined *)(param_1 + 0x20) = 0;
  }
  return param_1;
}

