
void FUN_810797be(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = func_0x8108ad50();
  piVar2 = piRam811ae77c;
  if (iVar1 != 0) {
    while (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,param_1);
      if (piVar2 != (int *)0x0) {
        piVar2 = (int *)piVar2[2];
      }
    }
  }
  return;
}

