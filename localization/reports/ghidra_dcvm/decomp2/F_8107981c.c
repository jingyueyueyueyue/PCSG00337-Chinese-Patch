
void FUN_8107981c(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = func_0x8108ad4c();
  piVar3 = piRam811ae77c;
  piVar1 = piRam811ae77c;
  if (iVar2 != 0) {
    while (piVar3 != (int *)0x0) {
      if (param_1 != piVar3) {
        (**(code **)(*piVar3 + 0x14))(piVar3);
        piVar3 = piVar1;
      }
      if (piVar3 != (int *)0x0) {
        piVar3 = (int *)piVar3[2];
        piVar1 = piVar3;
      }
    }
  }
  return;
}

