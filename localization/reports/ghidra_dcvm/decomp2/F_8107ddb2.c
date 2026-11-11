
undefined4 FUN_8107ddb2(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(uint *)(param_1 + 0x40) <= param_2) &&
     (param_2 < *(int *)(param_1 + 0x30) * *(int *)(param_1 + 0x38) + *(uint *)(param_1 + 0x40))) {
    uVar1 = 1;
  }
  return uVar1;
}

