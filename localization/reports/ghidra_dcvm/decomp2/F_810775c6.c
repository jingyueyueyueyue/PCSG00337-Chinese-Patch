
void FUN_810775c6(int param_1)

{
  int *piVar1;
  int iVar2;
  
  (**(code **)(*(int *)(param_1 + 0x2c) + 8))(param_1 + 0x2c);
  iVar2 = *(int *)(param_1 + 0x2c);
  piVar1 = (int *)**(int **)(param_1 + 0x10);
  while (piVar1 != (int *)0x0) {
    piVar1[1] = piVar1[1] | 1;
    piVar1 = (int *)*piVar1;
  }
  (**(code **)(iVar2 + 0xc))(param_1 + 0x2c);
  return;
}

