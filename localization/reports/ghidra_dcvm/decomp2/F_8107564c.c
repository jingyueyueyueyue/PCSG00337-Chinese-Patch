
void FUN_8107564c(int *param_1)

{
  (**(code **)(*param_1 + 0xc))();
  if (*(char *)(param_1 + 8) != '\0') {
    func_0x810846aa(param_1);
    *(undefined *)(param_1 + 8) = 0;
  }
  (**(code **)(*param_1 + 0x1c))(param_1);
  return;
}

