
void FUN_8106c17e(int param_1)

{
  short sVar1;
  short sVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  if (*(char *)(param_1 + 0xd9) == '\0') {
    iVar5 = *(int *)(param_1 + 0x5c) + -1;
    if ((*(uint *)(param_1 + 0xdc) & 0x10) == 0) {
      sVar1 = *(short *)(param_1 + 0x96);
      sVar2 = *(short *)(param_1 + 0x92);
      *(undefined *)(param_1 + 0xd9) = 1;
      iVar4 = func_0x8106d280(param_1 + 0x58,iVar5);
      iVar5 = (int)(short)(sVar1 - sVar2) - (uint)*(ushort *)(iVar4 + 0xe);
      cVar3 = *(char *)(param_1 + 0xd9);
      while ((0 < iVar5 && (iVar4 = *(int *)(iVar4 + 4), iVar4 != 0))) {
        cVar3 = cVar3 + '\x01';
        *(char *)(param_1 + 0xd9) = cVar3;
        iVar5 = iVar5 - (uint)*(ushort *)(iVar4 + 0xe);
      }
    }
    else {
      sVar1 = *(short *)(param_1 + 0x94);
      sVar2 = *(short *)(param_1 + 0x90);
      *(undefined *)(param_1 + 0xd9) = 1;
      iVar4 = func_0x8106d280(param_1 + 0x58,iVar5);
      iVar5 = (int)(short)(sVar1 - sVar2) - (uint)*(ushort *)(iVar4 + 0xc);
      cVar3 = *(char *)(param_1 + 0xd9);
      while ((0 < iVar5 && (iVar4 = *(int *)(iVar4 + 4), iVar4 != 0))) {
        cVar3 = cVar3 + '\x01';
        *(char *)(param_1 + 0xd9) = cVar3;
        iVar5 = iVar5 - (uint)*(ushort *)(iVar4 + 0xc);
      }
    }
  }
  return;
}

