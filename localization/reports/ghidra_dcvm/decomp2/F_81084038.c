
void FUN_81084038(int param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_8107587c();
  if (iVar1 == 0) {
    param_2 = '\0';
  }
  uVar2 = 0x100000;
  if (param_2 != '\0') {
    uVar2 = 0;
  }
  func_0x81116c90(*(undefined4 *)(**(int **)(param_1 + 4) + 4),uVar2);
  return;
}

