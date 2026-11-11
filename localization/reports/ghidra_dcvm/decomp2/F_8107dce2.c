
void FUN_8107dce2(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)func_0x8107d5fc();
  (**(code **)(*piVar1 + 8))();
  uVar2 = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar2;
  }
  (**(code **)(*piVar1 + 0xc))(piVar1);
  return;
}

