
void FUN_8108d550(void)

{
  int iVar1;
  
  iRam811913e4 = -1;
  iVar1 = iRam8114a76c;
  if (0 < iRam8114a76c) {
    while( true ) {
      iRam811913e4 = func_0x811187f0(&UNK_81137bf8,0xc20d060,iVar1,0);
      if (-1 < iRam811913e4) break;
      iVar1 = iVar1 + -0x100000;
    }
    iRam811913ec = iVar1;
    iVar1 = func_0x811187e0(iRam811913e4,0x811913f0);
    if (iVar1 < 0) {
      func_0x81118290(0x3000);
    }
    else {
      iRam811913e8 = func_0x811183e0(uRam811913f0,iRam811913ec);
      if (iRam811913e8 == 0) {
        func_0x81118290(0x3001);
      }
    }
  }
  return;
}

