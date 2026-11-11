
void FUN_8109676c(uint *param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = func_0x81069828(param_2,4);
  *param_1 = *param_1 & 0xffffff0f | (uVar1 & 0xf) << 4;
  if ((uVar1 & 0xf) != 1) {
    uVar1 = func_0x81069828(param_2,4);
    *param_1 = uVar1 & 0xf | *param_1 & 0xfffffff0;
    FUN_810965b4(param_1,param_2);
    return;
  }
  uVar1 = func_0x81069828(param_2,3);
  uVar1 = uVar1 & 0xf;
  *param_1 = *param_1 & 0xfffffff0 | uVar1;
  if (uVar1 < 3) {
    if (uVar1 == 0) {
      return;
    }
    if (uVar1 < 2) {
      iVar2 = func_0x81069828(param_2,1);
      if (iVar2 != 0) {
        param_1[1] = 0xffffffff;
        return;
      }
      param_1[1] = 0;
      iVar2 = func_0x81069828(param_2,1);
      if (iVar2 != 0) {
        param_1[1] = param_1[1] | 0x80000000;
      }
      iVar2 = func_0x81069828(param_2,1);
      uVar1 = param_1[1];
      if (iVar2 != 0) {
        uVar1 = uVar1 | 0x40000000;
        param_1[1] = uVar1;
      }
      uVar3 = func_0x81069828(param_2,8);
      param_1[1] = uVar3 | uVar1;
      return;
    }
  }
  else {
    if (uVar1 < 4) {
      iVar2 = func_0x81069828(param_2,1);
      if (iVar2 != 0) {
        param_1[1] = 0xffffffff;
        return;
      }
      uVar1 = func_0x81069828(param_2,0x18);
      param_1[1] = uVar1;
      return;
    }
    if (4 < uVar1) {
      return;
    }
  }
  if (*(uint *)(param_3 + 0x1c) < 0x10000) {
    uVar1 = func_0x81069828(param_2,0x10);
    param_1[1] = uVar1;
  }
  else {
    uVar1 = func_0x81069828(param_2,0x20);
    param_1[1] = uVar1;
  }
  return;
}

