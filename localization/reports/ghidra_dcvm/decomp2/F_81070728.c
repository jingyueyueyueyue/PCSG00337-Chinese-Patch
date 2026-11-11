
void FUN_81070728(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((undefined4 *)(param_1 + 0xe4) != param_2) {
    iVar1 = *(int *)(param_1 + 0xe4);
    *(undefined4 *)(param_1 + 0xe4) = *param_2;
    *param_2 = 0;
    if (iVar1 != 0) {
      FUN_810707d4();
      func_0x81005af0();
    }
  }
  **(int **)(param_1 + 0xe4) = param_1;
  return;
}

