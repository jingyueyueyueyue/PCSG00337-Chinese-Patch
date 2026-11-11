
undefined4 FUN_8108d144(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (ppiRam811adc54 == (int **)0x0) {
    uVar1 = 0;
  }
  else {
    iVar2 = func_0x81118520();
    if (iVar2 < 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    uVar1 = 0;
    if (**ppiRam811adc54 == iVar2) {
      uVar1 = 1;
    }
  }
  return uVar1;
}

