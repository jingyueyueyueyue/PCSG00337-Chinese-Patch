
void FUN_81099eba(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x14) + 1;
  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x14) * 8 + 4);
  if (iVar1 < 0) {
    func_0x81094a54(param_1,2);
  }
  else if (*(int *)(param_1 + 0x1c) < 2) {
    func_0x81094a54(param_1,3);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  (**(code **)(iVar2 * 4 + -0x7eeb581c))(param_1);
  return;
}

