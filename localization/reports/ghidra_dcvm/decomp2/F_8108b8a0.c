
undefined4 FUN_8108b8a0(undefined4 param_1,char param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = (uint *)(param_3 + 0xc);
  if (*puVar1 != 0) {
    do {
      if (param_2 == *(char *)(param_3 + 0x10)) {
        return 0;
      }
      uVar2 = uVar2 + 1;
      param_3 = param_3 + 0x10;
    } while (uVar2 < *puVar1);
  }
  return 1;
}

