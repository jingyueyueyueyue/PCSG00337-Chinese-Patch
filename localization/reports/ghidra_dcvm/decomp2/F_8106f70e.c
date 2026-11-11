
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8106f70e(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_1 == (char *)0x0) || (uVar4 = (uint)*param_1, uVar4 == 0)) {
    uVar2 = 0;
  }
  else {
    do {
      cVar1 = param_1[1];
      iVar3 = (**(code **)(&UNK_81138ee4 + iRam811913c8 * 4))(uVar4 & 0xff);
      if ((iVar3 != 0) &&
         (iVar3 = (**(code **)(&UNK_81138eec + iRam811913c8 * 4))(cVar1), iVar3 != 0)) {
        return 0;
      }
      iVar3 = (int)*param_1;
      if ((iVar3 == 0x2c) || (iVar3 == 0x29)) {
        return 1;
      }
      if (0x7f < iVar3) {
        return 0;
      }
      if ((*(ushort *)(_UNK_8111a59c + iVar3 * 2) & 0x20) == 0) {
        return 0;
      }
      param_1 = param_1 + 1;
      uVar4 = (uint)*param_1;
    } while (uVar4 != 0);
    uVar2 = 1;
  }
  return uVar2;
}

