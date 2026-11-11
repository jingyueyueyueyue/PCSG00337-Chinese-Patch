
void FUN_8108047c(int *param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = **(int **)(param_2 + 0xc);
  (**(code **)(*param_1 + 0x14))();
  uVar1 = *(ushort *)(iVar3 + 0x26);
  uVar2 = *(ushort *)(iVar3 + 0x28);
  *(undefined2 *)(iVar3 + 0x26) = *(undefined2 *)(iVar3 + 0x22);
  *(undefined2 *)(iVar3 + 0x28) = *(undefined2 *)(iVar3 + 0x24);
  if (0x3fff < uVar1) {
    uVar1 = 0x3fff;
  }
  *(ushort *)(iVar3 + 0x2a) = uVar1;
  if (0x3fff < uVar2) {
    uVar2 = 0x3fff;
  }
  *(ushort *)(iVar3 + 0x2c) = uVar2;
  *(undefined2 *)(iVar3 + 0x2e) = 0;
  *(undefined2 *)(iVar3 + 0x30) = 0x1e;
  return;
}

