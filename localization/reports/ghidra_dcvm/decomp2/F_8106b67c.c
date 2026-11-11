
int FUN_8106b67c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 0xdc);
  iVar3 = 0;
  if ((uVar2 & 0x10) == 0) {
    for (uVar1 = (uint)*(ushort *)(param_2 + 0xe);
        (int)uVar1 <= (int)(short)(*(short *)(param_1 + 0x96) - *(short *)(param_1 + 0x92));
        uVar1 = uVar1 + *(ushort *)(param_2 + 0xe)) {
      param_2 = *(int *)(param_2 + 8);
      iVar3 = iVar3 + 1;
      if (param_2 == 0) {
        if ((uVar2 & 1) == 0) {
          param_2 = *(int *)(param_1 + 0x60);
        }
        if (param_2 == 0) {
          return iVar3;
        }
      }
    }
  }
  else {
    for (uVar1 = (uint)*(ushort *)(param_2 + 0xc);
        (int)uVar1 <= (int)(short)(*(short *)(param_1 + 0x94) - *(short *)(param_1 + 0x90));
        uVar1 = uVar1 + *(ushort *)(param_2 + 0xc)) {
      param_2 = *(int *)(param_2 + 8);
      iVar3 = iVar3 + 1;
      if (param_2 == 0) {
        if ((uVar2 & 1) == 0) {
          param_2 = *(int *)(param_1 + 0x60);
        }
        if (param_2 == 0) {
          return iVar3;
        }
      }
    }
  }
  return iVar3;
}

