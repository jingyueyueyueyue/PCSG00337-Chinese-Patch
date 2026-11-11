
undefined4 FUN_8107e62c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0xc))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x20))();
  uVar2 = 0;
  if (*piVar1 != 0) {
    uVar2 = FUN_810794f6(*piVar1,param_2,param_3,param_4,0x81191264);
  }
  return uVar2;
}

