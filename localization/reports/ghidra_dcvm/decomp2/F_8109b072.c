
uint FUN_8109b072(byte *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      uVar2 = uVar2 + *param_1 + uVar1;
      if ((uVar1 & 1) != 0) {
        uVar2 = ~uVar2;
      }
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 1;
    } while (uVar1 < param_2);
  }
  return uVar2;
}

