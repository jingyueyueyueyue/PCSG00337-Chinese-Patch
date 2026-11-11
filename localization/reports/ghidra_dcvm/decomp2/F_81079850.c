
void FUN_81079850(undefined param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = func_0x8108ad4c();
  piVar3 = piRam811ae77c;
  piVar2 = piRam811ae77c;
  if (iVar1 != 0) {
    while (piVar3 = piRam811ae77c, piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))(piVar2);
      if (piVar2 != (int *)0x0) {
        piVar2 = (int *)piVar2[2];
      }
    }
  }
  while (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x10))(piVar3,param_1);
    if (piVar3 != (int *)0x0) {
      piVar3 = (int *)piVar3[2];
    }
  }
  return;
}

