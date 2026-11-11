
void FUN_810703ce(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1f0);
  iVar1 = param_1 + iVar2 * 8;
  *(uint *)(param_1 + 500) = (uint)*(ushort *)(iVar1 + 0xf4);
  for (; -1 < iVar2; iVar2 = iVar2 + -1) {
    if (*(int **)(iVar1 + 0xf0) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0xf0) + 0x1c))();
      *(undefined4 *)(iVar1 + 0xf0) = 0;
    }
    iVar1 = iVar1 + -8;
  }
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined2 *)(param_1 + 0x1f8) = 0;
  return;
}

