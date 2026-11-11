
undefined4 FUN_8109b73e(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (*(int *)(param_3 + 0x70) == 0) {
    func_0x810697dc(param_2,0,1);
  }
  else {
    func_0x810697dc(param_2,1,1);
    func_0x810697dc(param_2,0,1);
    iVar1 = func_0x8109b69c(param_1,param_2,param_3);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

