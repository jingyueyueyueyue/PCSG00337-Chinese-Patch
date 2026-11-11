
void FUN_81096504(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  
  func_0x810697dc(param_2,(*param_1 << 0x18) >> 0x1c,4);
  func_0x810697dc(param_2,*param_1 & 0xf,4);
  uVar1 = *param_1;
  if ((uVar1 & 0xf0) == 0x40) {
    func_0x810697dc(param_2,uVar1 >> 8,0x18);
    uVar1 = *param_1;
  }
  switch(uVar1 & 0xf) {
  case 0:
  case 6:
    break;
  case 1:
  case 4:
    uVar1 = param_1[1];
    if (uVar1 == 0) {
      func_0x810697dc(param_2,0,2);
    }
    else if (uVar1 == 1) {
      func_0x810697dc(param_2,1,2);
    }
    else if (uVar1 < 0x10000) {
      func_0x810697dc(param_2,2,2);
      func_0x810697dc(param_2,param_1[1],0x10);
    }
    else {
      func_0x810697dc(param_2,3,2);
      func_0x810697dc(param_2,param_1[1],0x20);
    }
    break;
  default:
    func_0x810697dc(param_2,param_1[1],0x20);
  }
  return;
}

