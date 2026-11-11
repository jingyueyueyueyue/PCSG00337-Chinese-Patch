
void FUN_8107040c(int param_1)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  
  iVar2 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
  uVar1 = *(ushort *)(iVar2 + 0xf4);
  if ((*(ushort *)(iVar2 + 0xf6) & 2) != 0) {
    *(short *)(param_1 + 0x1f8) = *(short *)(param_1 + 0x1f8) + -1;
    *(ushort *)(iVar2 + 0xf6) = *(ushort *)(iVar2 + 0xf6) & 0xfffd;
    iVar2 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
  }
  (**(code **)(**(int **)(iVar2 + 0xf0) + 0x1c))();
  iVar2 = *(int *)(param_1 + 0x1f0);
  *(undefined4 *)(param_1 + iVar2 * 8 + 0xf0) = 0;
  if (0 < iVar2) {
    *(int *)(param_1 + 0x1f0) = iVar2 + -1;
    iVar2 = param_1 + (iVar2 + -1) * 8;
    uVar3 = *(ushort *)(iVar2 + 0xf6) & 1;
    if (*(int *)(iVar2 + 0xf0) == 0) {
      FUN_8107026c(param_1,*(undefined2 *)(iVar2 + 0xf4));
      iVar2 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
      *(ushort *)(iVar2 + 0xf6) = *(ushort *)(iVar2 + 0xf6) & 0xfffe | uVar3;
      iVar2 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
      uVar3 = *(ushort *)(iVar2 + 0xf6) & 1;
    }
    if (uVar3 != 0) {
      (**(code **)(**(int **)(iVar2 + 0xf0) + 0x20))(*(int **)(iVar2 + 0xf0),(uint)uVar1);
    }
  }
  *(uint *)(param_1 + 500) = (uint)uVar1;
  return;
}

