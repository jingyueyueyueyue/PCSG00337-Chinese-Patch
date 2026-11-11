
int FUN_810819c8(char *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 != (char *)0x0) {
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      cVar2 = param_1[1];
      iVar3 = (**(code **)(&UNK_81138ee4 + iRam811913c8 * 4))(cVar1);
      if ((iVar3 == 0) ||
         (iVar3 = (**(code **)(&UNK_81138eec + iRam811913c8 * 4))(cVar2), iVar3 == 0)) {
        param_1 = param_1 + 1;
      }
      else {
        param_1 = param_1 + 2;
      }
      iVar4 = iVar4 + 1;
      cVar1 = *param_1;
    }
  }
  return iVar4;
}

