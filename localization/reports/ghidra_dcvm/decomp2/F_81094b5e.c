
void FUN_81094b5e(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_810949a0(param_1,param_2,4);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0xc) = param_2;
    *(undefined4 *)(param_1 + 0x38) =
         *(undefined4 *)
          (&UNK_81138470 + (uint)*(byte *)(*(int *)(param_1 + 0x44) + param_2 + 1) * 0xc);
  }
  while( true ) {
    (**(code **)(param_1 + 0x38))(param_1);
    if (*(char *)(*(int *)(param_1 + 0x40) + 0x54) != '\0') {
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0xc) + 1) == '\b') break;
    if (*(int *)(param_1 + 0x34) != 1) {
      return;
    }
  }
  return;
}

