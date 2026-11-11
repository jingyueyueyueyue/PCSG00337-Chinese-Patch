
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810960d8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0x1c);
  while ((iVar2 != iVar1 && (func_0x81094bac(param_1), *(int *)(param_1 + 0x28) != 0))) {
    iVar1 = *(int *)(param_1 + 0x10);
  }
  if (*(int *)(param_1 + 0x34) != 3) {
    iVar1 = *(int *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x34) = 1;
    if (iVar1 < 0) {
      *(undefined4 *)(param_1 + 0x38) = _UNK_81138470;
    }
    else {
      iVar2 = func_0x810949a0(param_1,iVar1,4);
      if (iVar2 != 0) {
        *(int *)(param_1 + 0xc) = iVar1;
        *(undefined4 *)(param_1 + 0x38) =
             *(undefined4 *)
              (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar1 + 1) * 0xc);
      }
    }
    FUN_81096066(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}

