
void FUN_8107e5c8(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if ((piVar1 != (int *)0x0) && (*(char *)(piVar1 + 1) != '\0')) {
    (**(code **)(*piVar1 + 0x18))(piVar1,param_2);
    *(undefined *)(piVar1 + 4) = 0;
  }
  piVar1 = *(int **)(param_1 + 4);
  if ((piVar1 != (int *)0x0) && (*(char *)(piVar1 + 6) != '\0')) {
    (**(code **)(*piVar1 + 0x14))(piVar1,param_2);
  }
  return;
}

