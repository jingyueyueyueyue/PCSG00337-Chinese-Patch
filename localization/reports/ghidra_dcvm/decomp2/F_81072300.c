
void FUN_81072300(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 2) {
    iVar2 = *param_1;
    if (((0 < param_1[6]) && (param_1[7] < 0)) && (-1 < param_1[8])) {
      param_1[7] = param_1[8];
      (**(code **)(iVar2 + 0x34))(param_1);
      iVar2 = *param_1;
    }
    iVar2 = (**(code **)(iVar2 + 0x24))(param_1);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*param_1 + 0x28))(param_1);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*param_1 + 0x2c))(param_1);
        if (iVar2 == 0) {
          iVar2 = (**(code **)(*param_1 + 0x30))(param_1);
          if (iVar2 != 0) {
            (**(code **)(*param_1 + 0x40))(param_1);
          }
        }
        else {
          (**(code **)(*param_1 + 0x3c))(param_1);
        }
      }
      else {
        iVar4 = param_1[7];
        iVar2 = iVar4 + 1;
        iVar3 = param_1[6];
        param_1[7] = iVar2;
        if (iVar3 <= iVar2) {
          do {
            iVar1 = iVar3 + -1;
            if (*(char *)(param_1 + 9) != '\0') {
              iVar1 = iVar2 - iVar3;
            }
            iVar2 = iVar1;
            param_1[7] = iVar2;
          } while (iVar3 <= iVar2);
        }
        if (iVar4 != iVar2) {
          (**(code **)(*param_1 + 0x38))(param_1);
          (**(code **)(*param_1 + 0x34))(param_1,param_1[7]);
        }
      }
    }
    else {
      iVar2 = param_1[7];
      iVar3 = iVar2 + -1;
      param_1[7] = iVar3;
      if (iVar3 < 0) {
        do {
          iVar4 = 0;
          if (*(char *)(param_1 + 9) != '\0') {
            iVar4 = iVar3 + param_1[6];
          }
          iVar3 = iVar4;
          param_1[7] = iVar3;
        } while (iVar3 < 0);
      }
      if (iVar2 != iVar3) {
        (**(code **)(*param_1 + 0x38))(param_1,iVar3);
        (**(code **)(*param_1 + 0x34))(param_1,param_1[7]);
      }
    }
  }
  return;
}

