
void FUN_8108c458(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = (uint *)&UNK_81137b50;
  uVar3 = 0;
  do {
    iVar1 = func_0x81116d50(*puVar2 & 0xffff);
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar3 < 2);
  return;
}

