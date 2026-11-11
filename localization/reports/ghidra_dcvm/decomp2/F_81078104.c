
undefined4 FUN_81078104(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x20))();
  if (*piVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_810794a2(*piVar1,param_2);
  }
  return uVar2;
}

