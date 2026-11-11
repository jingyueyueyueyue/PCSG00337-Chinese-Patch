
void FUN_8106848e(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (iRam811ae688 != 0) {
    iVar1 = iRam811ae688 + 4;
  }
  iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0x18) + 8) + 0xc);
  FUN_8107f4ee(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 0xc));
  func_0x8107f486(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 0xc),10);
  return;
}

