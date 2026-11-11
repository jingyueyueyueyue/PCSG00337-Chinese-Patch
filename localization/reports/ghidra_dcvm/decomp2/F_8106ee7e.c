
void FUN_8106ee7e(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = param_2;
  do {
    if (*(int *)(param_1 + 0x28) == param_2) {
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(iVar1 + 0x28);
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 4;
    iVar1 = iVar1 + 4;
  } while (iVar2 < 4);
  return;
}

