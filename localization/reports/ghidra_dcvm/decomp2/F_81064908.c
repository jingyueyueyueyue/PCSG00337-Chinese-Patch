
void FUN_81064908(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = func_0x81082928(param_2);
  if (*(char *)(iVar1 + 0x10) != '\x01') {
    *(undefined *)(iVar1 + 0x10) = 1;
    if (*(char *)(iVar1 + 0x20) != '\0') {
      func_0x810846aa(iVar1);
      *(undefined *)(iVar1 + 0x20) = 0;
    }
    func_0x81084028(iVar1,1);
  }
  if (*(int *)(iVar1 + 0x14) != 0) {
    *(undefined4 *)(iVar1 + 0x14) = 0;
    if (*(char *)(iVar1 + 0x20) != '\0') {
      func_0x810846aa(iVar1);
      *(undefined *)(iVar1 + 0x20) = 0;
    }
    func_0x810845d0(iVar1,0);
  }
  FUN_810757f6(iVar1);
  if (*(char *)(iVar1 + 0x20) != '\0') {
    func_0x810846aa(iVar1);
    *(undefined *)(iVar1 + 0x20) = 0;
  }
  func_0x81084610(iVar1,0,0);
  if (*(char *)(iVar1 + 0x20) != '\0') {
    func_0x810846aa(iVar1);
    *(undefined *)(iVar1 + 0x20) = 0;
  }
  func_0x8108461e(iVar1,0,0);
  func_0x81075bca(iVar1,0);
  return;
}

