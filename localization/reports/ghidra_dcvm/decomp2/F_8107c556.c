
int FUN_8107c556(int param_1,uint param_2)

{
  int iVar1;
  
  if (((uRam8119132c & 1) == 0) && (iVar1 = func_0x811183f0(0x8119132c), iVar1 != 0)) {
    uRam81191330 = uRam81191330 & 0xff00;
    func_0x81118240(0x8119132c);
  }
  iVar1 = -0x7ee6ecd0;
  if ((*(int *)(param_1 + 0x18) != 0) && (param_2 < *(uint *)(param_1 + 0x28))) {
    iVar1 = param_2 * *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18);
  }
  return iVar1;
}

