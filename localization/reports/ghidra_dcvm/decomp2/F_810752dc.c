
void FUN_810752dc(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  uVar1 = func_0x81082140();
  uVar2 = func_0x8108215c(param_1);
  uVar3 = func_0x81082178(param_1);
  fVar4 = (float)func_0x81118470(uVar1,*param_2);
  fVar5 = (float)func_0x81118470(uVar2,param_2[1]);
  fVar6 = (float)func_0x81118470(uVar3,param_2[2]);
  if (fVar4 != 0.0 && 0.0 < fVar4 == NAN(fVar4)) {
    fVar4 = 0.0;
  }
  if ((int)((uint)(1.0 < fVar4) << 0x1f) < 0) {
    fVar4 = 1.0;
  }
  if (fVar5 != 0.0 && 0.0 < fVar5 == NAN(fVar5)) {
    fVar5 = 0.0;
  }
  if ((int)((uint)(1.0 < fVar5) << 0x1f) < 0) {
    fVar5 = 1.0;
  }
  if (fVar6 != 0.0 && 0.0 < fVar6 == NAN(fVar6)) {
    fVar6 = 0.0;
  }
  if ((int)((uint)(1.0 < fVar6) << 0x1f) < 0) {
    fVar6 = 1.0;
  }
  func_0x810821b0(fVar4,param_1);
  func_0x810821d8(fVar5,param_1);
  func_0x81082200(fVar6,param_1);
  return;
}

