
void FUN_81073c8a(int *param_1,int param_2,int param_3)

{
  param_1[0xe] = param_2;
  param_1[0xf] = param_3;
  (**(code **)(*param_1 + 0x10))();
  if (param_1[1] == 0) {
    func_0x81073706(param_1);
  }
  else {
    func_0x810738d0(param_1);
  }
  FUN_81075858(param_1[0xc]);
  return;
}

