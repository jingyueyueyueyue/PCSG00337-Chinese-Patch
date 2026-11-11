
void FUN_810760fc(int param_1,undefined4 *param_2,undefined4 param_3)

{
  FUN_81084d28();
  if ((undefined4 *)(param_1 + 8) != param_2) {
    FUN_8107db94();
    *(undefined4 *)(param_1 + 0xc) = param_2[1];
    *(undefined4 *)(param_1 + 8) = *param_2;
    *param_2 = 0;
    param_2[1] = 0;
  }
  func_0x81084856(param_1,param_3);
  return;
}

