
void FUN_81070c14(int param_1,ushort param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc) + (uint)param_2 * 8;
  *(undefined2 *)(*(int *)(param_1 + 0xc) + (uint)param_2 * 8) = *(undefined2 *)(param_1 + 0x14);
  *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) & 0x9f;
  *(ushort *)(param_1 + 0x14) = param_2;
  return;
}

