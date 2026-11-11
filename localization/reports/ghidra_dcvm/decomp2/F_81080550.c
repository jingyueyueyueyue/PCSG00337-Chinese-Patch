
bool FUN_81080550(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,*(undefined4 *)(param_2 + 0xc));
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 8) = 10;
  }
  return iVar1 == 0;
}

