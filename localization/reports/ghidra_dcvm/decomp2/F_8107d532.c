
uint FUN_8107d532(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = uRam81191370 & 3;
  uVar3 = uRam81191370 + 3;
  uRam81191370 = uRam81191370 + 1;
  uVar2 = *(uint *)(uVar2 * 4 + -0x7ee6eca0);
  iVar1 = (uVar3 & 3) * 4;
  uVar3 = *(uint *)(iVar1 + -0x7ee6eca0);
  uVar2 = uVar2 ^ uVar2 << 0xb;
  uVar2 = uVar2 ^ uVar2 >> 8 ^ uVar3 ^ uVar3 >> 0x13;
  *(uint *)(iVar1 + -0x7ee6eca0) = uVar2;
  return uVar2 & 0x7fff;
}

