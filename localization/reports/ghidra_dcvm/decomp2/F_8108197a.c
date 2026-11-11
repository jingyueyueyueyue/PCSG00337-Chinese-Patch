
void FUN_8108197a(int param_1)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x3c) = param_1;
  uVar1 = uRam8114a5cc;
  *(undefined4 *)(param_1 + 0x40) = uRam8114a5c8;
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  FUN_8107dfea(param_1 + 8,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x18));
  return;
}

