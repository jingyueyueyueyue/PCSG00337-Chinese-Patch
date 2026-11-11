
void FUN_810965b4(uint *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = 0;
  if ((uVar2 & 0xf0) == 0x40) {
    iVar1 = func_0x81069828(param_2,0x18);
    uVar2 = *param_1;
  }
  *param_1 = uVar2 & 0xff | iVar1 << 8;
  switch(uVar2 & 0xf) {
  case 0:
    param_1[1] = 0;
    break;
  case 1:
  case 4:
    uVar2 = func_0x81069828(param_2,2);
    if (uVar2 < 2) {
      if (uVar2 == 0) {
        param_1[1] = 0;
      }
      else {
        param_1[1] = 1;
      }
    }
    else if (uVar2 < 3) {
      uVar2 = func_0x81069828(param_2,0x10);
      param_1[1] = uVar2;
    }
    else if (uVar2 < 4) {
      uVar2 = func_0x81069828(param_2,0x20);
      param_1[1] = uVar2;
    }
    break;
  default:
    uVar2 = func_0x81069828(param_2,0x20);
    param_1[1] = uVar2;
    break;
  case 6:
    break;
  }
  return;
}

