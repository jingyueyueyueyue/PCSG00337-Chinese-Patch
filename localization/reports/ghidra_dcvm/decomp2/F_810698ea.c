
uint FUN_810698ea(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(int *)(param_1 + 8) + 7;
  uVar1 = uVar2 & 0xfffffff8;
  *(uint *)(param_1 + 8) = uVar1;
  if (*(uint *)(param_1 + 4) < uVar1) {
    *(uint *)(param_1 + 4) = uVar1;
  }
  if (param_2 != 0) {
    func_0x8108d65a(param_2,*(int *)(param_1 + 0xc) + (uVar2 >> 3),param_3);
    uVar1 = *(int *)(param_1 + 8) + param_3 * 8;
    *(uint *)(param_1 + 8) = uVar1;
    if (*(uint *)(param_1 + 4) < uVar1) {
      *(uint *)(param_1 + 4) = uVar1;
    }
  }
  return uVar1;
}

