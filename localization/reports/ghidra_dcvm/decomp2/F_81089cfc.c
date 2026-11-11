
void FUN_81089cfc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x18) != 0) &&
     (iVar1 = func_0x81116c80(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14)),
     iVar1 != 0)) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x18) = param_3;
  iVar1 = func_0x81116830(param_2,param_3,param_1 + 0x14);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  return;
}

