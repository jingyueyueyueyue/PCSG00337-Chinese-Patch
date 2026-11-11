
void FUN_81080042(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[2] == 3) {
    func_0x81005b02(*param_1);
  }
  func_0x8108d650(param_1,0,8);
  param_1[2] = 3;
  iVar1 = func_0x81118330(param_2);
  uVar2 = func_0x81005aaa(iVar1 + 1);
  *param_1 = uVar2;
  func_0x8109d75c(uVar2,iVar1 + 1,param_2);
  return;
}

