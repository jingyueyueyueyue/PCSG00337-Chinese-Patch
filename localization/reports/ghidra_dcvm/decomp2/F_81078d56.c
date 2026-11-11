
void FUN_81078d56(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  (**(code **)(*(int *)(param_1 + 4) + 8))(param_1 + 4);
  iVar2 = *(int *)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 4);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (param_2 != 0) {
      iVar2 = param_2 + 4;
    }
    *(undefined4 *)(iVar2 + 4) = 0;
    puVar5 = (undefined4 *)0x0;
    if (param_2 != 0) {
      puVar5 = (undefined4 *)(param_2 + 4);
    }
    *puVar5 = 0;
    *(int *)(param_1 + 0x10) = param_2;
  }
  else {
    iVar4 = 0;
    if (param_2 != 0) {
      iVar4 = param_2 + 4;
    }
    *(int *)(iVar4 + 4) = iVar2;
    *(int *)(iVar2 + 4) = param_2;
    puVar5 = (undefined4 *)0x0;
    if (param_2 != 0) {
      puVar5 = (undefined4 *)(param_2 + 4);
    }
    *puVar5 = 0;
  }
  pcVar1 = *(code **)(iVar3 + 0xc);
  *(int *)(param_1 + 0xc) = param_2;
  (*pcVar1)(param_1 + 4);
  return;
}

