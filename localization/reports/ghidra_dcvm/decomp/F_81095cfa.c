
void FUN_81095cfa(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 *param_5,
                 uint param_6,char param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  uVar2 = func_0x81095bac(param_1);
  if (param_4 != 0) {
    if (param_7 == '\0') {
      puVar4 = param_5 + param_4 * 2;
      if (param_5 != puVar4) {
        do {
          iVar3 = *(int *)(param_1 + 0x14);
          iVar5 = iVar3 + -1;
          if (iVar5 < 0) {
            *(undefined4 *)(param_1 + 0x34) = 3;
            *(undefined **)(param_1 + 0x38) = &UNK_81096439;
            iVar5 = iVar3;
          }
          else if (*(int *)(param_1 + 0x1c) < 0) {
            *(undefined4 *)(param_1 + 0x34) = 3;
            *(undefined **)(param_1 + 0x38) = &UNK_81096439;
            iVar5 = iVar3;
          }
          else {
            *(int *)(param_1 + 0x14) = iVar5;
          }
          iVar3 = *(int *)(param_1 + 0x24);
          *(undefined4 *)(iVar3 + iVar5 * 8) = *param_5;
          puVar1 = param_5 + 1;
          param_5 = param_5 + 2;
          *(undefined4 *)(iVar3 + iVar5 * 8 + 4) = *puVar1;
        } while (param_5 != puVar4);
      }
    }
    else {
      for (puVar4 = param_5 + param_4 * 2 + -2; puVar4 != param_5 + -2; puVar4 = puVar4 + -2) {
        iVar3 = *(int *)(param_1 + 0x14);
        iVar5 = iVar3 + -1;
        if (iVar5 < 0) {
          *(undefined4 *)(param_1 + 0x34) = 3;
          *(undefined **)(param_1 + 0x38) = &UNK_81096439;
          iVar5 = iVar3;
        }
        else if (*(int *)(param_1 + 0x1c) < 0) {
          *(undefined4 *)(param_1 + 0x34) = 3;
          *(undefined **)(param_1 + 0x38) = &UNK_81096439;
          iVar5 = iVar3;
        }
        else {
          *(int *)(param_1 + 0x14) = iVar5;
        }
        iVar3 = *(int *)(param_1 + 0x24);
        *(undefined4 *)(iVar3 + iVar5 * 8) = *puVar4;
        *(undefined4 *)(iVar3 + iVar5 * 8 + 4) = puVar4[1];
      }
    }
  }
  iVar5 = FUN_8109b50a(param_2,param_3,3);
  if (iVar5 == -1) {
    *(undefined **)(param_1 + 0x38) = &UNK_81096439;
    *(undefined4 *)(param_1 + 0x34) = 3;
  }
  else {
    FUN_810959ea(param_1,iVar5,param_4,param_6 | uVar2);
  }
  return;
}

