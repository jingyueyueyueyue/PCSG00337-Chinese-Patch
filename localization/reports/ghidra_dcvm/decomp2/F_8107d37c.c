
undefined4 FUN_8107d37c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = -param_1;
    if (param_1 < 0) {
      iVar2 = param_1;
      param_1 = -param_1;
    }
    uVar1 = func_0x8107d308(iVar2,param_1,param_2);
  }
  return uVar1;
}

