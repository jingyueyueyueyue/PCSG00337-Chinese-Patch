
void FUN_8107226a(int *param_1)

{
  if (*(char *)(param_1 + 3) != '\0') {
    *(undefined *)(param_1 + 3) = 0;
    (**(code **)(*param_1 + 0x14))();
  }
  return;
}

