
void FUN_8106b25e(int param_1,short param_2,short param_3)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    if ((*(uint *)(iVar1 + 8) & 1) == 0) {
      *(short *)(iVar1 + 4) = *(short *)(iVar1 + 4) + param_2;
      *(short *)(iVar1 + 6) = *(short *)(iVar1 + 6) + param_3;
    }
  }
  return;
}

