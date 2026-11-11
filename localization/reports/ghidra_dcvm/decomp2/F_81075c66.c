
void FUN_81075c66(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  
  if (param_2 == 0) {
    param_2 = func_0x81082c5e(uRam811ae690);
  }
  *(int *)(param_1 + 8) = param_2;
  func_0x81083d92(param_1);
  if (param_3 == 0) {
    param_3 = func_0x81082c68(uRam811ae690);
  }
  *(int *)(param_1 + 0xc) = param_3;
  func_0x81083d94(param_1,param_3);
  iVar4 = *(int *)(param_1 + 0xc);
  if (param_3 == 0) {
    if (iVar4 == 0) {
      iVar4 = func_0x81082c68(uRam811ae690);
    }
    cVar3 = *(char *)(param_1 + 0x20);
    if (iVar4 != 0) {
      if (cVar3 != '\0') {
        func_0x810846aa(param_1);
        *(undefined *)(param_1 + 0x20) = 0;
      }
      FUN_81084038(param_1,0);
      cVar3 = *(char *)(param_1 + 0x20);
    }
    if (cVar3 != '\0') {
      func_0x810846aa(param_1);
      *(undefined *)(param_1 + 0x20) = 0;
    }
    FUN_81084586(param_1,1);
  }
  else {
    if (iVar4 == 0) {
      iVar4 = func_0x81082c68(uRam811ae690);
    }
    cVar3 = *(char *)(param_1 + 0x20);
    if (iVar4 != 0) {
      if (cVar3 != '\0') {
        func_0x810846aa(param_1);
        *(undefined *)(param_1 + 0x20) = 0;
      }
      FUN_81084038(param_1,1);
      cVar3 = *(char *)(param_1 + 0x20);
    }
    if (cVar3 != '\0') {
      func_0x810846aa(param_1);
      *(undefined *)(param_1 + 0x20) = 0;
    }
    FUN_81084586(param_1,7);
  }
  piVar5 = *(int **)(param_1 + 8);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)func_0x81082c5e(uRam811ae690);
  }
  uVar1 = (**(code **)(*piVar5 + 0x10))(piVar5);
  uVar2 = (**(code **)(*piVar5 + 0x14))(piVar5);
  func_0x8107575e(param_1,0,0,uVar1,uVar2);
  return;
}

