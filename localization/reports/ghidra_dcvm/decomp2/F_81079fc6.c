
void FUN_81079fc6(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar1 = FUN_8107b460(*(undefined4 *)(param_1 + 0x50));
  *(undefined *)(param_1 + 0x8a) = 0;
  *(undefined *)(param_1 + 0x89) = 0;
  *(undefined *)(param_1 + 0x88) = 0;
  if ((*(char *)(param_1 + 0xc) == '\0') || (uVar1 == 0)) {
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  else if (uVar1 != 0) {
    uVar3 = 0;
    do {
      uVar2 = FUN_8107b3aa(*(undefined4 *)(param_1 + 0x50),uVar3);
      func_0x81079d88(param_1,uVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

