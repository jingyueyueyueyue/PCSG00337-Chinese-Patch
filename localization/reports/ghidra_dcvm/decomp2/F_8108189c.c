
int FUN_8108189c(int param_1)

{
  int iVar1;
  
  (**(code **)(*(int *)(param_1 + 0x24) + 8))(param_1 + 0x24);
  iVar1 = FUN_8107e09a(param_1 + 8);
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 2;
  }
  (**(code **)(*(int *)(param_1 + 0x24) + 0xc))(param_1 + 0x24);
  return iVar1;
}

