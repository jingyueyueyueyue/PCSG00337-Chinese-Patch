
void FUN_810745da(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = *(undefined4 *)(param_1 + 0xdc);
  uVar3 = *(undefined4 *)(param_1 + 0xec);
  func_0x810767e0(uVar2);
  FUN_810767e2(uVar2,4,3,uVar3);
  iVar1 = *(int *)(param_1 + 0xe0);
  if (*(char *)(iVar1 + 0x20) != '\0') {
    func_0x810846aa(iVar1);
    *(undefined *)(iVar1 + 0x20) = 0;
  }
  func_0x8108461e(iVar1,0,0);
  return;
}

