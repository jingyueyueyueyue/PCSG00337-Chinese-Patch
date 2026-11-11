
void FUN_8107037c(int param_1,undefined2 param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
  uVar1 = *(ushort *)(iVar2 + 0xf4);
  *(ushort *)(iVar2 + 0xf6) = *(ushort *)(iVar2 + 0xf6) | 1;
  *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x1f0) + 1;
  *(short *)(param_1 + 0x1f8) = *(short *)(param_1 + 0x1f8) + 1;
  FUN_8107026c(param_1,param_2);
  iVar2 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
  *(ushort *)(iVar2 + 0xf6) = *(ushort *)(iVar2 + 0xf6) | 2;
  *(uint *)(param_1 + 500) = (uint)uVar1;
  return;
}

