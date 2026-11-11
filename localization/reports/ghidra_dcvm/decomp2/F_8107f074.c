
void FUN_8107f074(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  
  if ((((*param_2 != 0) && ((uint)*(ushort *)((int)param_2 + 2) < *(uint *)(param_1 + 0x14))) &&
      (iVar1 = (uint)*(ushort *)((int)param_2 + 2) * 0x34 + *(int *)(param_1 + 0x10),
      *(short *)(iVar1 + 0x1e) == *(short *)param_2)) &&
     ((iVar1 != 0 && ((*(ushort *)(iVar1 + 0x18) & 0x40) == 0)))) {
    *(ushort *)(iVar1 + 0x18) = *(ushort *)(iVar1 + 0x18) | 0x40;
    *(undefined2 *)(iVar1 + 0x26) = *(undefined2 *)(iVar1 + 0x22);
    *(undefined2 *)(iVar1 + 0x28) = *(undefined2 *)(iVar1 + 0x24);
    *(undefined2 *)(iVar1 + 0x2a) = 0;
    *(undefined2 *)(iVar1 + 0x2c) = 0;
    *(undefined2 *)(iVar1 + 0x2e) = 0;
    if (60000 < param_3) {
      param_3 = 60000;
    }
    *(short *)(iVar1 + 0x30) = (short)param_3;
  }
  return;
}

