
void FUN_81075532(undefined4 param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  
  fVar1 = (float)func_0x81082140();
  fVar2 = (float)func_0x8108215c(param_1);
  fVar3 = (float)func_0x81082178(param_1);
  func_0x81082228(fVar2 * 0.587 + fVar1 * 0.299 + fVar3 * 0.114,param_1);
  if (param_2 != (undefined4 *)0x0) {
    uVar4 = *param_2;
    func_0x810821b0(uVar4,param_1);
    func_0x810821d8(uVar4,param_1);
    func_0x81082200(uVar4,param_1);
  }
  return;
}

