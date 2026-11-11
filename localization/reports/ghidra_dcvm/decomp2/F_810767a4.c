
void FUN_810767a4(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = 1;
  puVar1 = (undefined2 *)0x8119121a;
  do {
    iVar2 = iVar2 + -1;
    *puVar1 = 0;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar2);
  uRam8119121c = 0;
  uRam81191220 = 0;
  func_0x81118450(0x8119121c,&UNK_810ce6fd,0x811ae7e8);
  return;
}

