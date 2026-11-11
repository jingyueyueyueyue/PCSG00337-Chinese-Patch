
void FUN_81072602(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 8) = 2;
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_1 + 0x44) = 0x3f800000;
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x18))();
    if (piVar1 != (int *)0x0) {
      piVar1 = (int *)piVar1[4];
    }
  }
  return;
}

