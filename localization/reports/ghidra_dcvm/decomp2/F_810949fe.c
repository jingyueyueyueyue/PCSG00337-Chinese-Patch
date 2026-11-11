
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810949fe(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  *(int *)(param_1 + 0x34) = param_2;
  if (param_2 == 1) {
    iVar2 = *(int *)(param_1 + 0xc);
    if (iVar2 < 0) {
      *(undefined4 *)(param_1 + 0x38) = _UNK_81138470;
    }
    else {
      iVar1 = FUN_810949a0(param_1,iVar2,4);
      if (iVar1 != 0) {
        *(int *)(param_1 + 0xc) = iVar2;
        *(undefined4 *)(param_1 + 0x38) =
             *(undefined4 *)
              (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar2 + 1) * 0xc);
      }
    }
  }
  else {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
  }
  return;
}

