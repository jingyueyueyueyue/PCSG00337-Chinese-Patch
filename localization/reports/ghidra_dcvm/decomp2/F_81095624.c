
bool FUN_81095624(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_2 >> 3;
  piVar1 = (int *)func_0x8109ce56(*(undefined4 *)(param_1 + 0x40));
  param_2 = param_2 & 0xfffffff8;
  if (param_2 == 0) {
    param_2 = 1;
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_2,piVar1 + 9,piVar1[1]);
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x24) = iVar2;
    *(uint *)(param_1 + 0x18) = uVar3;
    *(uint *)(param_1 + 0x1c) = uVar3;
    *(uint *)(param_1 + 0x10) = uVar3;
    *(uint *)(param_1 + 0x14) = uVar3;
  }
  return iVar2 != 0;
}

