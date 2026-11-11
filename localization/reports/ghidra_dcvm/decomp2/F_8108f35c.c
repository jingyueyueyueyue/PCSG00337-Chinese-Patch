
void FUN_8108f35c(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = 7;
  puVar1 = (undefined2 *)0x811914a0;
  do {
    iVar2 = iVar2 + -1;
    *puVar1 = 0;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar2);
  func_0x8108f2a8(0xd,&UNK_8108f46f,0);
  iVar2 = func_0x810a6990(0,0,0,0);
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  return;
}

