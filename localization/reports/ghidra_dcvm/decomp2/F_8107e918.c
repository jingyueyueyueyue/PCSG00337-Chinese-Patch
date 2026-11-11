
undefined4 FUN_8107e918(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_2;
  if (((iVar2 < 0) || (7 < iVar2)) || (param_1[iVar2 * 6 + 4] == 0)) {
    uVar1 = 0;
  }
  else {
    do {
      iVar2 = (**(code **)(*param_1 + 0x14))(param_1,param_2);
    } while (iVar2 != 0);
    uVar1 = 2;
    if ((param_1[*param_2 * 6 + 4] != -99) && (uVar1 = 3, param_1[*param_2 * 6 + 4] == -100)) {
      uVar1 = 1;
    }
  }
  return uVar1;
}

