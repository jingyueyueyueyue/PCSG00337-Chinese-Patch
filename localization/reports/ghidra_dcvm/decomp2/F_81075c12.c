
void FUN_81075c12(int param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((param_2 != 0) && ((*(byte *)(param_2 + 0xc) & 2) != 0)) {
    bVar1 = true;
  }
  if ((*(int *)(param_1 + 0x1c) != param_2) || (bVar1)) {
    *(int *)(param_1 + 0x1c) = param_2;
    if (*(char *)(param_1 + 0x20) != '\0') {
      func_0x810846aa(param_1);
      *(undefined *)(param_1 + 0x20) = 0;
    }
    func_0x8108467e(param_1,param_2);
  }
  return;
}

