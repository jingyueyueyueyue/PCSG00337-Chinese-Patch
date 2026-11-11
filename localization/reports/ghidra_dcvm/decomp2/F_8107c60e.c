
int FUN_8107c60e(int param_1,uint param_2)

{
  int iVar1;
  
  if (((uRam81191334 & 1) == 0) && (iVar1 = func_0x811183f0(0x81191334), iVar1 != 0)) {
    uRam81191338 = 0;
    uRam8119133a = 0;
    uRam8119133c = 0;
    func_0x81118240(0x81191334);
  }
  iVar1 = -0x7ee6ecc8;
  if ((*(int *)(param_1 + 0x20) != 0) && (param_2 < *(uint *)(param_1 + 0x28))) {
    iVar1 = param_2 * *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x20);
  }
  return iVar1;
}

