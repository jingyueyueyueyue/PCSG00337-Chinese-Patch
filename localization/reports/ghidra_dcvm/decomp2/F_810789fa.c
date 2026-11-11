
undefined4 FUN_810789fa(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if ((param_2[2] & 0x80000000) == 0) {
    uVar1 = 0xffffffff;
    if ((uVar2 <= (uint)param_1[1]) && (uVar1 = 0, uVar2 < (uint)param_1[1])) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = func_0x811181a0(*param_1,param_1[2] + uVar2);
  }
  return uVar1;
}

