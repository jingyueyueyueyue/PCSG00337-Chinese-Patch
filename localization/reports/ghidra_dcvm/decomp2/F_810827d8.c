
void FUN_810827d8(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x14);
  (**(code **)(*piVar1 + 0xc))(piVar1);
  if (*(char *)(piVar1 + 8) != '\0') {
    func_0x810846aa(piVar1);
    *(undefined *)(piVar1 + 8) = 0;
  }
  return;
}

