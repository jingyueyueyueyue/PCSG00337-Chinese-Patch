
undefined4 FUN_8106d9e8(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(int *)(param_1 + 4)) {
    uVar1 = 0;
  }
  else {
    uVar1 = func_0x8106d280(param_1);
    uVar1 = func_0x8106d900(param_1,uVar1);
  }
  return uVar1;
}

