
int * FUN_81078d0a(int *param_1)

{
  int iVar1;
  
  FUN_8108ca06(param_1 + 1);
  iVar1 = *param_1;
  if (iVar1 != 0) {
    func_0x81005af0(*(undefined4 *)(iVar1 + 8));
    *(undefined4 *)(iVar1 + 8) = 0;
    func_0x81005af0(iVar1);
  }
  *param_1 = 0;
  return param_1;
}

