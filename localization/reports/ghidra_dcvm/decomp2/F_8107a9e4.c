
int FUN_8107a9e4(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  if (((uRam81191280 & 1) == 0) && (iVar1 = func_0x811183f0(0x81191280), iVar1 != 0)) {
    uRam81191284 = 0;
    uRam81191285 = 0;
    func_0x81118240(0x81191280);
  }
  if (param_3 < (uint)param_1[2]) {
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = -0x7ee6ed7c;
    }
  }
  else {
    iVar1 = -0x7ee6ed7c;
  }
  return iVar1;
}

