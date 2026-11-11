
void FUN_810767e2(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  *(int *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (param_2 < 3) {
    if (0 < param_2) {
      if (param_2 < 2) {
        *(undefined4 *)(param_1 + 0x10) = 2;
      }
      else {
        *(undefined4 *)(param_1 + 0x10) = 4;
      }
    }
  }
  else if (param_2 < 4) {
    *(undefined4 *)(param_1 + 0x10) = 4;
  }
  else if (param_2 < 5) {
    *(undefined4 *)(param_1 + 0x10) = 4;
  }
  FUN_8108545a(param_1,param_4);
  return;
}

