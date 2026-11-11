
void FUN_8107c7b4(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = 0;
  func_0x81005b02(uVar2);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = 0;
  func_0x81005b02(uVar2);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x20) = 0;
  func_0x81005b02(uVar2);
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return;
}

