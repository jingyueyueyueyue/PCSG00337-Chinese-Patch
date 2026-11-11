
void FUN_81092436(int param_1)

{
  int iVar1;
  
  *(undefined *)(param_1 + 0x28) = 0;
  iVar1 = param_1 + 0x10;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  if (0xf < *(uint *)(param_1 + 0x24)) {
    iVar1 = *(int *)(param_1 + 0x10);
  }
  FUN_810942c8(param_1 + 4,iVar1,0x81092485,0x100000ff,0x4000,0,0x70000,0);
  FUN_81094306(param_1 + 4,param_1);
  return;
}

