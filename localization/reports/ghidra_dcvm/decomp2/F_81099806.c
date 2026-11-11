
undefined4 FUN_81099806(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_81099794();
  iVar2 = *(int *)(param_1 + 0x14) + 1;
  if (iVar2 < 0) {
    func_0x81094a54(param_1,2);
  }
  else if (*(int *)(param_1 + 0x1c) < 2) {
    func_0x81094a54(param_1,3);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar2;
  }
  return uVar1;
}

