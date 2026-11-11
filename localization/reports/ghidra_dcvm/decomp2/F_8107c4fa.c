
int FUN_8107c4fa(int param_1,uint param_2)

{
  int iVar1;
  
  if (((uRam81191324 & 1) == 0) && (iVar1 = func_0x811183f0(0x81191324), iVar1 != 0)) {
    uRam81191329 = 0;
    uRam81191328 = 0;
    func_0x81118240(0x81191324);
  }
  iVar1 = -0x7ee6ecd8;
  if ((*(int *)(param_1 + 0x10) != 0) && (param_2 < *(uint *)(param_1 + 0x2c))) {
    iVar1 = param_2 * *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x10);
  }
  return iVar1;
}

