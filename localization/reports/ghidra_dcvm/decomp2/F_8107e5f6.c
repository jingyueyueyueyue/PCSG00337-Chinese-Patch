
void FUN_8107e5f6(int param_1,undefined4 param_2)

{
  bool bVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 4);
  bVar1 = false;
  if ((piVar2 != (int *)0x0) && (*(char *)(piVar2 + 6) != '\0')) {
    (**(code **)(*piVar2 + 0x10))(piVar2,param_2);
    bVar1 = true;
  }
  piVar2 = *(int **)(param_1 + 8);
  if ((piVar2 != (int *)0x0) && (*(char *)(piVar2 + 1) != '\0')) {
    (**(code **)(*piVar2 + 0x14))(piVar2,param_2,!bVar1);
  }
  return;
}

