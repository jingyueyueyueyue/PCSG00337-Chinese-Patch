
void FUN_8108987c(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x3c) != 0) {
    iVar1 = func_0x81116c30();
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (*(int *)(param_1 + 8) != 0) {
    iVar1 = func_0x81116750();
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  FUN_81092130(param_1 + 0x10);
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar1 = func_0x811169b0();
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  FUN_81092130(param_1 + 0x24);
  if (*(int *)(param_1 + 0x30) != 0) {
    iVar1 = func_0x811169d0();
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  FUN_81092130(param_1 + 0x34);
  return;
}

