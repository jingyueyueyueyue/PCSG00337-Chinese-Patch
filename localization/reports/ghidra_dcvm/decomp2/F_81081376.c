
undefined4 FUN_81081376(int param_1,int *param_2,uint **param_3,int param_4)

{
  uint *puVar1;
  
  *param_2 = param_4;
  *(undefined4 *)(param_1 + 8) = 0;
  puVar1 = *param_3;
  if (puVar1 != (uint *)0x0) {
    if ((*puVar1 & 0xf) == 0) {
      func_0x8108d65a(param_2,puVar1 + 1,4);
      return 1;
    }
    if ((*puVar1 & 0xf) == 1) {
      *param_2 = (int)(float)puVar1[1];
      return 1;
    }
  }
  *(undefined4 *)(param_1 + 8) = 3;
  return 0;
}

