
void FUN_81070324(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
  *(undefined4 *)(iVar1 + 0xf8) = *(undefined4 *)(iVar1 + 0xf0);
  *(undefined4 *)(iVar1 + 0xfc) = *(undefined4 *)(iVar1 + 0xf4);
  iVar1 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
  *(undefined4 *)(iVar1 + 0xf0) = 0;
  *(ushort *)(iVar1 + 0xf6) = *(ushort *)(iVar1 + 0xf6) | 1;
  iVar2 = param_1 + *(int *)(param_1 + 0x1f0) * 8;
  *(undefined2 *)(iVar1 + 0xf4) = param_2;
  *(ushort *)(iVar2 + 0xf6) = *(ushort *)(iVar2 + 0xf6) & 0xfffd;
  *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x1f0) + 1;
  return;
}

