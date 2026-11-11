
void FUN_8106877a(undefined4 param_1,uint param_2)

{
  if (((int)param_2 < -0x80) || (0x7f < (int)param_2)) {
    func_0x810697dc(param_1,0,1);
    func_0x810697dc(param_1,param_2,0x20);
  }
  else {
    func_0x810697dc(param_1,1,1);
    func_0x810697dc(param_1,param_2 & 0xff,8);
  }
  return;
}

