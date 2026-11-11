
void FUN_8107cbe6(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = piRam811ae79c;
  if (piRam811ae79c != (int *)0x0) {
    do {
      (**(code **)(*piVar1 + 8))(piVar1,param_1);
      if (piVar1 != (int *)0x0) {
        piVar1 = (int *)piVar1[2];
      }
    } while (piVar1 != (int *)0x0);
  }
  return;
}

