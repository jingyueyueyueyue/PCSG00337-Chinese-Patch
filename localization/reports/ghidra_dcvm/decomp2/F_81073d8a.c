
void FUN_81073d8a(int param_1)

{
  int iVar1;
  
  (**(code **)(**(int **)(param_1 + 0x34) + 8))();
  iVar1 = *(int *)(param_1 + 0x30);
  if (*(char *)(iVar1 + 0x20) != '\0') {
    func_0x810846aa(iVar1);
    *(undefined *)(iVar1 + 0x20) = 0;
  }
  func_0x8108461e(iVar1,0,0);
  return;
}

