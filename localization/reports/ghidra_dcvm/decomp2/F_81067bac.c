
undefined4 FUN_81067bac(void)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    puVar1 = (ushort *)FUN_8107c556(iRam811ae688 + 0x80,iVar2);
    if ((*puVar1 & 1) != 0) {
      return 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x18);
  return 0;
}

