
int FUN_8107aa52(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  if (((uRam81191288 & 1) == 0) && (iVar1 = func_0x811183f0(0x81191288), iVar1 != 0)) {
    uRam8119128c = 0;
    func_0x81118240(0x81191288);
  }
  if (param_3 < (uint)param_1[1]) {
    iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = -0x7ee6ed74;
    }
  }
  else {
    iVar1 = -0x7ee6ed74;
  }
  return iVar1;
}

