
void FUN_810797f0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = func_0x8108ad4c();
  piVar2 = piRam811ae77c;
  if (iVar1 != 0) {
    while (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))();
      if (piVar2 != (int *)0x0) {
        piVar2 = (int *)piVar2[2];
      }
    }
  }
  return;
}

