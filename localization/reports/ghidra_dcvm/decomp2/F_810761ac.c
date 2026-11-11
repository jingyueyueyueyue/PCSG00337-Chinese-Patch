
void FUN_810761ac(int param_1,undefined4 *param_2)

{
  FUN_81084d28();
  if ((undefined4 *)(param_1 + 8) != param_2) {
    FUN_8107db94();
    *(undefined4 *)(param_1 + 0xc) = param_2[1];
    *(undefined4 *)(param_1 + 8) = *param_2;
    *param_2 = 0;
    param_2[1] = 0;
  }
  return;
}

