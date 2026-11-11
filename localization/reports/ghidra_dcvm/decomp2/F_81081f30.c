
uint FUN_81081f30(byte *param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = 0;
  bVar1 = *param_1;
  while (bVar1 != 0) {
    uVar5 = (uint)*param_1;
    iVar2 = 0;
    do {
      uVar4 = uVar3 ^ uVar5;
      uVar3 = uVar3 >> 1;
      if ((uVar4 & 1) != 0) {
        uVar3 = uVar3 ^ param_2;
      }
      iVar2 = iVar2 + 1;
      uVar5 = (uVar5 << 0x17) >> 0x18;
    } while (iVar2 < 8);
    bVar1 = param_1[1];
    param_1 = param_1 + 1;
  }
  return uVar3;
}

