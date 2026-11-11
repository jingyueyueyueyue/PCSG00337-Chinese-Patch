
void FUN_8108ea2c(int param_1)

{
  int iVar1;
  
  *(undefined *)(param_1 + 4) = 1;
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_81094348();
    iVar1 = *(int *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x10) = 0;
    if (iVar1 != 0) {
      func_0x810942c4();
      func_0x81005af0();
    }
  }
  func_0x810a0446();
  if (*(int *)(param_1 + 8) != 0) {
    iVar1 = func_0x81116f80();
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      func_0x81118280();
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  func_0x81116d40(0xb);
  return;
}

