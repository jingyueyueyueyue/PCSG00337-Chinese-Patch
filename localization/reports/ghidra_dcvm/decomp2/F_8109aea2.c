
void FUN_8109aea2(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    if (param_1 + 0xc == *(int *)(param_1 + 0x14)) {
      func_0x8110ca84();
    }
    else {
      iVar1 = *(int *)(param_1 + 0x10);
      *(int *)(*(int *)(param_1 + 0x14) + 4) = iVar1;
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x14);
    }
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return;
}

