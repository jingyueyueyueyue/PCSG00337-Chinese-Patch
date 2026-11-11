
void FUN_8108d5c2(void)

{
  int iVar1;
  
  if (iRam811913e8 != 0) {
    iVar1 = func_0x81118200();
    if (iVar1 != 0) {
      software_bkpt(0);
    }
    iRam811913e8 = 0;
  }
  if (-1 < iRam811913e4) {
    iVar1 = func_0x811187d0();
    if (iVar1 < 0) {
      software_bkpt(0);
    }
    uRam811913ec = 0;
    uRam811913f0 = 0;
    iRam811913e4 = -1;
  }
  return;
}

