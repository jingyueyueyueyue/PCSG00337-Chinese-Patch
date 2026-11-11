
void FUN_8107d4cc(uint param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  uRam81191360 = 0x75bcd15;
  uRam81191364 = 0x159a55e5;
  uRam81191368 = 0x1f123bb5;
  uRam8119136c = 0x5491333;
  if (param_1 != 0) {
    uVar3 = 0;
    puVar2 = (uint *)0x81191360;
    do {
      iVar1 = (param_1 ^ param_1 >> 0x1e) * 0x6c078965 + uVar3;
      uVar3 = uVar3 + 1;
      param_1 = iVar1 + 1;
      *puVar2 = param_1;
      puVar2 = puVar2 + 1;
    } while (uVar3 < 4);
  }
  uRam81191370 = 0;
  return;
}

