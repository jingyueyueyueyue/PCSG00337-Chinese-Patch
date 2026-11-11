
void FUN_81069d18(int param_1)

{
  int *piVar1;
  int iVar2;
  
  (**(code **)(*(int *)(param_1 + 0x24) + 8))(param_1 + 0x24);
  iVar2 = *(int *)(param_1 + 0x24);
  piVar1 = (int *)**(int **)(param_1 + 8);
  while (piVar1 != (int *)0x0) {
    piVar1[1] = piVar1[1] | 1;
    piVar1 = (int *)*piVar1;
  }
  (**(code **)(iVar2 + 0xc))(param_1 + 0x24);
  return;
}

