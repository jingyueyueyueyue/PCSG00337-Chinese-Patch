
undefined4 FUN_81081520(int *param_1,int *param_2,undefined4 param_3,int param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  
  puVar1 = (uint *)FUN_810812b0(param_1,param_3);
  if (puVar1 == (uint *)0x0) {
    param_1[2] = 1;
    uVar2 = 0;
  }
  else {
    *param_2 = param_4;
    param_1[2] = 0;
    if ((*puVar1 & 0xf) == 2) {
      *param_2 = *(int *)(*param_1 + 0xc) + puVar1[1] + 8;
      uVar2 = 1;
    }
    else {
      param_1[2] = 3;
      uVar2 = 0;
    }
  }
  return uVar2;
}

