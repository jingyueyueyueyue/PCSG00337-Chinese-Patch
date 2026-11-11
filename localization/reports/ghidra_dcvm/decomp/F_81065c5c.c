
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81065c5c(char *param_1,int param_2,undefined param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined auStack_30 [4];
  int iStack_2c;
  
  iVar3 = iRam811ae688;
  iStack_2c = _UNK_8111a5b0;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    uVar2 = 2;
    goto LAB_81065d68;
  }
  iVar7 = 0;
  if (iRam811ae688 != 0) {
    iVar7 = iRam811ae688 + 4;
  }
  iVar5 = iVar7 + 4;
  (**(code **)(*(int *)(iVar7 + 4) + 8))(iVar5);
  iVar6 = 0;
  if (iVar3 != 0) {
    iVar6 = iVar3 + 4;
  }
  iVar6 = *(int *)(iVar6 + 0x10);
  if (iVar6 == 0) {
    (**(code **)(*(int *)(iVar7 + 4) + 0xc))(iVar5);
    uVar2 = 0;
    goto LAB_81065d68;
  }
  iVar3 = func_0x8107b846(iVar3 + 100,param_1,auStack_30);
  if (iVar3 != 0) {
    (**(code **)(*(int *)(iVar7 + 4) + 0xc))(iVar5);
    uVar2 = 2;
    goto LAB_81065d68;
  }
  uVar2 = **(undefined4 **)(iVar6 + 0x1c);
  iVar3 = func_0x810a17ce(uVar2);
  if (iVar3 == 0) {
    (**(code **)(*(int *)(iVar7 + 4) + 0xc))(iVar5);
    uVar2 = 0;
    goto LAB_81065d68;
  }
  if (param_2 < 0) {
    if (param_2 < -1) {
LAB_81065d48:
      uVar2 = FUN_810a1a0e(uVar2,param_1,0x81191264,1,param_3);
      pcVar4 = *(code **)(*(int *)(iVar7 + 4) + 0xc);
    }
    else {
      uVar2 = FUN_810a1a0e(uVar2,param_1,0x81191264,2,param_3);
      pcVar4 = *(code **)(*(int *)(iVar7 + 4) + 0xc);
    }
  }
  else {
    if (0 < param_2) goto LAB_81065d48;
    uVar2 = FUN_810a1a0e(uVar2,param_1,0x81191264,0,param_3);
    pcVar4 = *(code **)(*(int *)(iVar7 + 4) + 0xc);
  }
  (*pcVar4)(iVar5);
LAB_81065d68:
  if (_UNK_8111a5b0 != iStack_2c) {
    uVar1 = func_0x811185a0(uVar2);
    iVar3 = iRam811ae688;
    iVar7 = 0;
    if (iRam811ae688 != 0) {
      iVar7 = iRam811ae688 + 4;
    }
    iVar6 = iVar7 + 4;
    (**(code **)(*(int *)(iVar7 + 4) + 8))(iVar6);
    iVar5 = 0;
    if (iVar3 != 0) {
      iVar5 = iVar3 + 4;
    }
    if (*(int *)(iVar5 + 0x10) == 0) {
      (**(code **)(*(int *)(iVar7 + 4) + 0xc))(iVar6);
    }
    else {
      func_0x810a2b2e(**(undefined4 **)(*(int *)(iVar5 + 0x10) + 0x1c),uVar1);
      (**(code **)(*(int *)(iVar7 + 4) + 0xc))(iVar6);
    }
    return;
  }
  return;
}

