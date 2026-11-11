
void FUN_8107c3ee(int *param_1,char param_2)

{
  if (*(char *)(param_1 + 0xc) != param_2) {
    *(char *)(param_1 + 0xc) = param_2;
    (**(code **)(*param_1 + 0x10))();
  }
  return;
}

