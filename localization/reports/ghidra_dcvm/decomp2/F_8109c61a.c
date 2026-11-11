
int FUN_8109c61a(int param_1)

{
  int iVar1;
  
  FUN_8109c5b0();
  func_0x81005b02(*(undefined4 *)(param_1 + 0x50));
  if (*(int **)(param_1 + 100) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 100) + 4))();
  }
  *(undefined4 *)(param_1 + 100) = 0;
  if (*(int **)(param_1 + 0x60) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x60) + 4))();
  }
  *(undefined4 *)(param_1 + 0x60) = 0;
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x5c) + 4))();
  }
  iVar1 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x5c) = 0;
  if (iVar1 != 0) {
    if (0xf < *(uint *)(iVar1 + 0x6c)) {
      func_0x81005af0(*(undefined4 *)(iVar1 + 0x58));
    }
    *(undefined4 *)(iVar1 + 0x68) = 0;
    *(undefined4 *)(iVar1 + 0x6c) = 0xf;
    *(undefined *)(iVar1 + 0x58) = 0;
    if (0xf < *(uint *)(iVar1 + 0x50)) {
      func_0x81005af0(*(undefined4 *)(iVar1 + 0x3c));
    }
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    *(undefined4 *)(iVar1 + 0x50) = 0xf;
    *(undefined *)(iVar1 + 0x3c) = 0;
    if (0xf < *(uint *)(iVar1 + 0x34)) {
      func_0x81005af0(*(undefined4 *)(iVar1 + 0x20));
    }
    *(undefined4 *)(iVar1 + 0x30) = 0;
    *(undefined4 *)(iVar1 + 0x34) = 0xf;
    *(undefined *)(iVar1 + 0x20) = 0;
    if (0xf < *(uint *)(iVar1 + 0x18)) {
      func_0x81005af0(*(undefined4 *)(iVar1 + 4));
    }
    *(undefined *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x18) = 0xf;
    func_0x81005af0(iVar1);
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  if (*(int *)(param_1 + 0x34) != 0) {
    if (param_1 + 0x34 == *(int *)(param_1 + 0x3c)) {
      func_0x810c881c();
    }
    else {
      iVar1 = *(int *)(param_1 + 0x38);
      *(int *)(*(int *)(param_1 + 0x3c) + 4) = iVar1;
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x3c);
    }
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if (*(int *)(param_1 + 0x28) != 0) {
    if (param_1 + 0x28 == *(int *)(param_1 + 0x30)) {
      func_0x810c881c();
    }
    else {
      iVar1 = *(int *)(param_1 + 0x2c);
      *(int *)(*(int *)(param_1 + 0x30) + 4) = iVar1;
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x30);
    }
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    if (param_1 + 0x1c == *(int *)(param_1 + 0x24)) {
      func_0x810f937c();
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      *(int *)(*(int *)(param_1 + 0x24) + 4) = iVar1;
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x24);
    }
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    if (param_1 + 0x10 == *(int *)(param_1 + 0x18)) {
      func_0x810f936c();
    }
    else {
      iVar1 = *(int *)(param_1 + 0x14);
      *(int *)(*(int *)(param_1 + 0x18) + 4) = iVar1;
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x18);
    }
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return param_1;
}

