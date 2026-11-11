
void FUN_8106ea2e(int *param_1,undefined4 param_2)

{
  bool bVar1;
  
  if (param_1[0xe] == 0) {
    bVar1 = false;
    if ((*(byte *)((int)param_1 + 0x42) & 4) != 0) {
      bVar1 = true;
    }
  }
  else {
    bVar1 = false;
    if (((*(byte *)(param_1[0xe] + 0x42) & 4) != 0) && ((*(byte *)((int)param_1 + 0x42) & 4) != 0))
    {
      bVar1 = true;
    }
  }
  if (bVar1) {
    (**(code **)(*param_1 + 0x98))(param_1);
    (**(code **)(*param_1 + 0x9c))(param_1,param_2);
    (**(code **)(*param_1 + 0xa0))(param_1);
  }
  return;
}

