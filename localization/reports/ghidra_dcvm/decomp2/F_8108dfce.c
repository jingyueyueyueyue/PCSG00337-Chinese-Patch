
void FUN_8108dfce(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((*(int *)(iVar1 + 0x10000) != 0) &&
     ((*(int *)(iVar1 + 0x10050) == 2 || (*(int *)(iVar1 + 0x10050) == 1)))) {
    *(undefined4 *)(iVar1 + 0x10050) = 3;
    iVar1 = func_0x81116dc0();
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
  }
  return;
}

