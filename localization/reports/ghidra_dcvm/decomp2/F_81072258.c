
void FUN_81072258(int *param_1)

{
  if (*(char *)(param_1 + 3) == '\0') {
    *(undefined *)(param_1 + 3) = 1;
    (**(code **)(*param_1 + 0x10))();
  }
  return;
}

