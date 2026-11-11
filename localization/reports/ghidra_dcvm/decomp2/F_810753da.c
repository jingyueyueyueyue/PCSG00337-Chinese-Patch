
void FUN_810753da(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)func_0x81082140();
  fVar2 = (float)func_0x8108215c(param_1);
  fVar3 = (float)func_0x81082178(param_1);
  fVar1 = fVar2 * 0.587 + fVar1 * 0.299 + fVar3 * 0.114;
  func_0x810821b0(fVar1 * 1.2,param_1);
  func_0x810821d8(fVar1 * 1.1,param_1);
  func_0x81082200(fVar1 * 0.9,param_1);
  return;
}

