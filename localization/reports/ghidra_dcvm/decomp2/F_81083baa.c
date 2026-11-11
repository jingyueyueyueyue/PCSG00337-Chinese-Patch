
void FUN_81083baa(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  *(undefined *)(iVar2 + 0x2c) = 1;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  *(undefined4 *)(iVar2 + 0x1c) = 1;
  *(undefined4 *)(iVar2 + 0x20) = 1;
  *(undefined4 *)(iVar2 + 0x24) = 2;
  *(undefined4 *)(iVar2 + 0x28) = 2;
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  *(bool *)(iVar2 + 0x30) = *(char *)(param_1 + 0x10) != '\0';
  *(undefined4 *)(iVar2 + 0x34) = uVar1;
  return;
}

