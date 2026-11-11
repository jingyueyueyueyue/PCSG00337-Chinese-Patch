
void FUN_81070bfc(int param_1,ushort param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = (uint)*(byte *)(*(int *)(param_1 + 0xc) + (uint)param_2 * 8 + 3) * 4;
  *(undefined2 *)(*(int *)(param_1 + 0xc) + (uint)param_2 * 8) = *(undefined2 *)(iVar1 + iVar2);
  *(ushort *)(iVar1 + iVar2) = param_2;
  return;
}

