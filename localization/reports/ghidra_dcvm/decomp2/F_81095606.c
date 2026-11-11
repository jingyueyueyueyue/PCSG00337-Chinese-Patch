
void FUN_81095606(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x34) != 3) {
    do {
      iVar1 = (**(code **)(param_1 + 0x38))(param_1);
      if (*(char *)(*(int *)(param_1 + 0x40) + 0x54) != '\0') {
        return;
      }
    } while (iVar1 != 0);
  }
  return;
}

