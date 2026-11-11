
void FUN_8108c484(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  puVar2 = (uint *)&UNK_81137b54;
  iVar3 = 1;
  do {
    iVar1 = func_0x81116d40(*puVar2 & 0xffff);
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    iVar3 = iVar3 + -1;
    puVar2 = puVar2 + -1;
  } while (-1 < iVar3);
  return;
}

