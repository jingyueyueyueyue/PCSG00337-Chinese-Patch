
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8106b5fa(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined *puStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  uStack_24 = 0x80000016;
  puStack_28 = &UNK_81144de8;
  uStack_20 = 0;
  iStack_1c = 0;
  iStack_18 = 0;
  uVar1 = func_0x8106b5a4(param_1,1);
  uStack_20 = uVar1 & 1 | uStack_20 & 0xfffffffe;
  uVar1 = func_0x8106b5a4(param_1,2);
  uStack_20 = uStack_20 & 0xfffffffd | (uVar1 & 1) << 1;
  iStack_1c = param_1[0x3e];
  iStack_18 = param_1[0x17] - (uint)*(byte *)(param_1 + 0x36);
  (**(code **)(*param_1 + 0xa8))(param_1,&puStack_28);
  if (_UNK_8111a5b0 == iStack_14) {
    return _UNK_8111a5b0;
  }
  uVar6 = func_0x811185a0();
  iVar5 = (int)((ulonglong)uVar6 >> 0x20);
  iVar2 = (int)uVar6;
  uVar1 = *(uint *)(iVar2 + 0xdc);
  iVar4 = 0;
  if ((uVar1 & 0x10) == 0) {
    for (uVar3 = (uint)*(ushort *)(iVar5 + 0xe);
        (int)uVar3 <= (int)(short)(*(short *)(iVar2 + 0x96) - *(short *)(iVar2 + 0x92));
        uVar3 = uVar3 + *(ushort *)(iVar5 + 0xe)) {
      iVar5 = *(int *)(iVar5 + 8);
      iVar4 = iVar4 + 1;
      if (iVar5 == 0) {
        if ((uVar1 & 1) == 0) {
          iVar5 = *(int *)(iVar2 + 0x60);
        }
        if (iVar5 == 0) {
          return iVar4;
        }
      }
    }
  }
  else {
    for (uVar3 = (uint)*(ushort *)(iVar5 + 0xc);
        (int)uVar3 <= (int)(short)(*(short *)(iVar2 + 0x94) - *(short *)(iVar2 + 0x90));
        uVar3 = uVar3 + *(ushort *)(iVar5 + 0xc)) {
      iVar5 = *(int *)(iVar5 + 8);
      iVar4 = iVar4 + 1;
      if (iVar5 == 0) {
        if ((uVar1 & 1) == 0) {
          iVar5 = *(int *)(iVar2 + 0x60);
        }
        if (iVar5 == 0) {
          return iVar4;
        }
      }
    }
  }
  return iVar4;
}

