
void FUN_8107d1cc(uint *param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  *param_1 = 0x75bcd15;
  param_1[1] = 0x159a55e5;
  param_1[2] = 0x1f123bb5;
  param_1[3] = 0x5491333;
  if (param_2 != 0) {
    uVar3 = 0;
    puVar2 = param_1;
    do {
      iVar1 = (param_2 ^ param_2 >> 0x1e) * 0x6c078965 + uVar3;
      uVar3 = uVar3 + 1;
      param_2 = iVar1 + 1;
      *puVar2 = param_2;
      puVar2 = puVar2 + 1;
    } while (uVar3 < 4);
  }
  param_1[4] = 0;
  return;
}

