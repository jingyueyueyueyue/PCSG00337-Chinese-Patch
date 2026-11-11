
void FUN_81087e98(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((undefined4 *)(iVar1 + 0x1c) != param_2) {
    FUN_8107db94();
    *(undefined4 *)(iVar1 + 0x20) = param_2[1];
    *(undefined4 *)(iVar1 + 0x1c) = *param_2;
    *param_2 = 0;
    param_2[1] = 0;
  }
  return;
}

