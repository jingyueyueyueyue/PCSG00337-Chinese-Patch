
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_810949a0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 0x48) <= param_2)) {
    uVar2 = 0;
  }
  else {
    uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x44) + param_2 + 1);
    if ((*(char *)(*(int *)(param_1 + 0x44) + param_2) == -0x3d) && (uVar3 < 0x50)) {
      if (param_3 == 0) {
        uVar2 = 1;
      }
      else {
        uVar2 = FUN_810949a0(param_1,param_2 + *(int *)(&UNK_8113846c + uVar3 * 0xc),param_3 + -1);
      }
    }
    else {
      func_0x8109b02e(*(undefined4 *)(param_1 + 0x28));
      uVar1 = _UNK_81138470;
      uVar2 = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x38) = uVar1;
    }
  }
  return uVar2;
}

