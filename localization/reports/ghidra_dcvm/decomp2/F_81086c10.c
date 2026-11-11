
int * FUN_81086c10(int *param_1)

{
  int iVar1;
  
  if (param_1[3] != 0) {
    func_0x8108769e();
    func_0x81005af0();
  }
  param_1[3] = 0;
  if (param_1[2] != 0) {
    FUN_8108a29e();
    func_0x81005af0();
  }
  param_1[2] = 0;
  iVar1 = param_1[1];
  if (*param_1 != 0) {
    *(int *)(*param_1 + 4) = param_1[1];
    iVar1 = iRam811ae7b8;
  }
  iRam811ae7b8 = iVar1;
  iVar1 = *param_1;
  if ((int *)param_1[1] != (int *)0x0) {
    *(int *)param_1[1] = *param_1;
    iVar1 = iRam811ae7bc;
  }
  iRam811ae7bc = iVar1;
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

