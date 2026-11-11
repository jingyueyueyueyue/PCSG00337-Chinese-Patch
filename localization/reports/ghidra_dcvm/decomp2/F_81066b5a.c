
void FUN_81066b5a(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  if ((*(char *)(param_2 + 0x3c) != '\0') && (*(int *)(param_2 + 0x18) == 4)) {
    uVar2 = *(undefined4 *)(param_2 + 0x10);
    uVar1 = *(undefined4 *)(param_2 + 0x14);
  }
  *param_1 = uVar2;
  param_1[1] = uVar1;
  return;
}

