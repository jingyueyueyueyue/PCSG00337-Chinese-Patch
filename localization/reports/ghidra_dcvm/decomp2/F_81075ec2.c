
void FUN_81075ec2(int param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  *(uint *)(param_1 + 0x10) = param_2;
  uVar1 = *(ushort *)(*(int *)(param_1 + 0x20) + 8);
  if (param_2 < 0x8140) {
    if (0xff < param_2) {
      param_2 = param_2 + 0x7ec0;
    }
  }
  else {
    param_2 = param_2 - 0x8040;
  }
  *(uint *)(param_1 + 0x14) = param_2;
  *(undefined *)(param_1 + 0x1c) = 1;
  if ((((param_2 < uVar1) &&
       (uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x28) + (param_2 >> 4) * 2 + 8),
       uVar2 != 0xffff)) &&
      (iVar3 = *(int *)(param_1 + 0x24) + (uVar2 + (param_2 & 0xf)) * 2, iVar3 != -8)) &&
     (uVar2 = (uint)*(ushort *)(iVar3 + 8), uVar2 != 0xffff)) {
    *(undefined *)(param_1 + 0x1c) = 0;
  }
  else {
    uVar2 = 0;
  }
  *(uint *)(param_1 + 0x18) = uVar2;
  return;
}

