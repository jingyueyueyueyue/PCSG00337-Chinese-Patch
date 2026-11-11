
void FUN_810d67b2(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_r5;
  
  iVar1 = FUN_8109473e(param_1,0);
  uVar2 = 1 << (*(uint *)(iVar1 + 4) & 0xff);
  DAT_81181dac = DAT_81181dac & ~uVar2;
  DAT_81181db0 = DAT_81181db0 & ~uVar2;
  iVar1 = FUN_8109473e(unaff_r5,1);
  if (*(int *)(iVar1 + 4) != 0) {
    DAT_81181dac = DAT_81181dac | uVar2;
    DAT_81181db0 = DAT_81181db0 | uVar2;
  }
  return;
}

