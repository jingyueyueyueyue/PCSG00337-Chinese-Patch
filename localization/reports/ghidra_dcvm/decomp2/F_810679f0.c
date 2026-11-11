
void FUN_810679f0(int **param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0x81082928(param_2);
  if (*param_1 != (int *)0x0) {
    FUN_810757f6(iVar1);
    if (*(char *)(iVar1 + 0x10) != '\x01') {
      *(undefined *)(iVar1 + 0x10) = 1;
      if (*(char *)(iVar1 + 0x20) != '\0') {
        func_0x810846aa(iVar1);
        *(undefined *)(iVar1 + 0x20) = 0;
      }
      func_0x81084028(iVar1,1);
    }
    if (*(char *)(iVar1 + 0x20) != '\0') {
      func_0x810846aa(iVar1);
      *(undefined *)(iVar1 + 0x20) = 0;
    }
    FUN_81084586(iVar1,1);
    iVar2 = FUN_8107587c(iVar1);
    if (iVar2 != 0) {
      if (*(char *)(iVar1 + 0x20) != '\0') {
        func_0x810846aa(iVar1);
        *(undefined *)(iVar1 + 0x20) = 0;
      }
      FUN_81084038(iVar1,0);
    }
    if (*(int *)(iVar1 + 0x14) != 0) {
      *(undefined4 *)(iVar1 + 0x14) = 0;
      if (*(char *)(iVar1 + 0x20) != '\0') {
        func_0x810846aa(iVar1);
        *(undefined *)(iVar1 + 0x20) = 0;
      }
      func_0x810845d0(iVar1,0);
    }
    (**(code **)(**param_1 + 0xc))(*param_1,iVar1);
    if (((uint)param_1[10] & 1) != 0) {
      func_0x81067730(param_1,param_2);
    }
  }
  func_0x81075bca(iVar1,0);
  return;
}

