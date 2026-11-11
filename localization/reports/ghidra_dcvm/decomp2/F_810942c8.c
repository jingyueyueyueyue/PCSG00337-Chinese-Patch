
void FUN_810942c8(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  
  param_1[1] = param_3;
  iVar1 = func_0x811186d0(param_2,0x81094489,param_4,param_5,param_6,param_7,param_8);
  *param_1 = iVar1;
  if (iVar1 < 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  return;
}

