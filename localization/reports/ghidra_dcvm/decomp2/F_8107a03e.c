
void FUN_8107a03e(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_2 + 0x88) == '\0') {
    *param_1 = iRam811ae788;
    param_1[1] = iRam811ae78c;
  }
  else {
    iVar2 = *(int *)(param_2 + 0x58);
    iVar1 = *(int *)(param_2 + 0x60);
    *param_1 = *(int *)(param_2 + 0x5c) - *(int *)(param_2 + 0x54);
    param_1[1] = iVar1 - iVar2;
  }
  return;
}

