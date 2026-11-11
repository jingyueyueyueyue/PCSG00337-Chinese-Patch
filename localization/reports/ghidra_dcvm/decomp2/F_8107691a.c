
void FUN_8107691a(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x84) & 4) == 0) {
    *param_2 = *(int *)(param_1 + 0x5c);
    *param_4 = *(int *)(param_1 + 100);
    uVar1 = *(uint *)(param_1 + 0x84);
  }
  else {
    *param_2 = *(int *)(param_1 + 0x5c) + *(int *)(param_1 + 100);
    *param_4 = -*(int *)(param_1 + 100);
    uVar1 = *(uint *)(param_1 + 0x84);
  }
  if ((uVar1 & 8) == 0) {
    *param_3 = *(int *)(param_1 + 0x60);
    iVar2 = *(int *)(param_1 + 0x68);
  }
  else {
    *param_3 = *(int *)(param_1 + 0x60) + *(int *)(param_1 + 0x68);
    iVar2 = -*(int *)(param_1 + 0x68);
  }
  *param_5 = iVar2;
  return;
}

