
void FUN_8109477c(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = *param_1;
  uVar4 = param_2 + 7U >> 3;
  iVar1 = -uVar4;
  iVar3 = *(int *)(iVar2 + 0x14) + iVar1;
  if (iVar3 < 0) {
    func_0x81094a54(iVar2,2);
  }
  else {
    iVar5 = *(int *)(iVar2 + 0x1c);
    if (iVar5 == iVar1 || (int)(iVar5 + uVar4) < 0 != SBORROW4(iVar5,iVar1)) {
      func_0x81094a54(iVar2,3);
    }
    else {
      *(int *)(iVar2 + 0x14) = iVar3;
    }
  }
  return;
}

