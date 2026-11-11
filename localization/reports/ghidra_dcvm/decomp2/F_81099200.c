
undefined4 FUN_81099200(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x14) + 1;
  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x14) * 8 + 4);
  if (iVar1 < 0) {
    func_0x81094a54(param_1,2);
  }
  else if (*(int *)(param_1 + 0x1c) < 2) {
    func_0x81094a54(param_1,3);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  iVar1 = FUN_810949a0(param_1,iVar2,4);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0xc) = iVar2;
    *(undefined4 *)(param_1 + 0x38) =
         *(undefined4 *)
          (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + iVar2 + 1) * 0xc);
  }
  return 1;
}

