
void FUN_8107e8d8(int param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  *param_3 = 0;
  *param_2 = 0;
  iVar2 = *param_4;
  if (((-1 < iVar2) && (iVar2 < 8)) && (iVar2 = param_1 + iVar2 * 0x18, *(int *)(iVar2 + 0x10) != 0)
     ) {
    *param_3 = *(undefined4 *)(iVar2 + 8);
    iVar1 = *param_4;
    *param_2 = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(param_1 + iVar1 * 0x18 + 4) = 0;
  }
  return;
}

