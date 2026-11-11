
void FUN_81079796(int *param_1,int *param_2)

{
  (**(code **)(*param_1 + 0x14))(param_1);
  param_1[0xf] = *param_2;
  param_1[0x10] = param_2[1];
  param_1[0x11] = param_2[2];
  param_1[0x12] = param_2[3];
  (**(code **)(*param_1 + 0x18))(param_1);
  return;
}

