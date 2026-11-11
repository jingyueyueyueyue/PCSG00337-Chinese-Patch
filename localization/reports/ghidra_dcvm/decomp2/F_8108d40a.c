
void FUN_8108d40a(int *param_1)

{
  int iVar1;
  
  if (param_1[1] != 0) {
    iVar1 = func_0x81118200();
    if (iVar1 != 0) {
      software_bkpt(0);
    }
    param_1[1] = 0;
  }
  if (-1 < *param_1) {
    iVar1 = func_0x811187d0();
    if (iVar1 < 0) {
      software_bkpt(0);
    }
    param_1[2] = 0;
    param_1[3] = 0;
    *param_1 = -1;
  }
  return;
}

