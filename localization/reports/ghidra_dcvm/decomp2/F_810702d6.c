
void FUN_810702d6(int param_1,undefined2 param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
  uVar1 = *(ushort *)(iVar2 + 0xf4);
  (**(code **)(**(int **)(iVar2 + 0xf0) + 0x1c))();
  iVar2 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
  *(undefined4 *)(iVar2 + 0xf0) = 0;
  *(ushort *)(iVar2 + 0xf6) = *(ushort *)(iVar2 + 0xf6) | 1;
  *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x1f0) + 1;
  FUN_8107026c(param_1,param_2);
  *(uint *)(param_1 + 500) = (uint)uVar1;
  return;
}

