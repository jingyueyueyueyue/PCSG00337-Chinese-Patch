
int FUN_81094e48(int param_1)

{
  int *piVar1;
  
  FUN_81094d4e();
  if ((*(int *)(param_1 + 0x40) != 0) &&
     (FUN_8109ce98(*(int *)(param_1 + 0x40),*(undefined4 *)(param_1 + 8)),
     *(int *)(param_1 + 0x24) != 0)) {
    piVar1 = (int *)func_0x8109ce56(*(undefined4 *)(param_1 + 0x40));
    if (*(int *)(param_1 + 0x24) != 0) {
      (**(code **)(*piVar1 + 0x10))();
    }
  }
  return param_1;
}

