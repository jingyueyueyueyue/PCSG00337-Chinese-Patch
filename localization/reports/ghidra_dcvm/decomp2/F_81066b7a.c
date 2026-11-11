
void FUN_81066b7a(int param_1)

{
  int iVar1;
  char cVar2;
  
  cVar2 = *(char *)(param_1 + 0x3c);
  if (((cVar2 != '\0') && (*(char *)(param_1 + 0x3d) != '\0')) &&
     (*(char *)(param_1 + 0x3e) == '\0')) {
    FUN_8108d144();
    cVar2 = *(char *)(param_1 + 0x3c);
  }
  if (cVar2 != '\0') {
    while (iVar1 = func_0x81066a7a(param_1), iVar1 != 0) {
      FUN_8108cfd4(10);
    }
  }
  return;
}

