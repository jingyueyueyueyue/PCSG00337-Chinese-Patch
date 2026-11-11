
bool FUN_8109c93c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  *(int *)(param_1 + 0x4c) = param_2;
  *(undefined *)(param_1 + 0x54) = 0;
  uVar2 = param_2 + 8U >> 3;
  iVar1 = func_0x81005aaa(uVar2);
  *(int *)(param_1 + 0x50) = iVar1;
  if (iVar1 != 0) {
    func_0x8108d650(iVar1,0,uVar2);
    **(byte **)(param_1 + 0x50) = **(byte **)(param_1 + 0x50) | 1;
  }
  return iVar1 != 0;
}

