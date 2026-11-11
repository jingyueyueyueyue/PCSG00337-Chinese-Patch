
undefined4 FUN_8107f2c0(int param_1)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar3 + 8))(piVar3);
  uVar1 = 0;
  if (*(uint *)(param_1 + 0x20) != 0) {
    piVar2 = *(int **)(param_1 + 0x1c);
    do {
      if (*piVar2 != 0) {
        (**(code **)(*piVar3 + 0xc))(piVar3);
        return 1;
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 9;
    } while (uVar1 < *(uint *)(param_1 + 0x20));
  }
  (**(code **)(*piVar3 + 0xc))(piVar3);
  return 0;
}

