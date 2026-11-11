
void FUN_8108d43e(void)

{
  int iVar1;
  
  if (iRam811913d8 != 0) {
    iVar1 = func_0x81118200();
    if (iVar1 != 0) {
      software_bkpt(0);
    }
    iRam811913d8 = 0;
  }
  if (-1 < iRam811913d4) {
    iVar1 = func_0x811187d0();
    if (iVar1 < 0) {
      software_bkpt(0);
    }
    uRam811913dc = 0;
    uRam811913e0 = 0;
    iRam811913d4 = -1;
  }
  return;
}

