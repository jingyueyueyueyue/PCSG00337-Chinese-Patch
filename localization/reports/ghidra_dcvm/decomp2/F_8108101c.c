
undefined4 FUN_8108101c(int **param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  piVar3 = param_1[6];
  *param_1 = (int *)0x0;
  param_1[1] = (int *)0x0;
  param_1[2] = (int *)0x0;
  param_1[3] = (int *)0x0;
  param_1[4] = (int *)0x0;
  if ((piVar3 != (int *)0x0) && (*piVar3 == 0x4d504344)) {
    piVar1 = piVar3 + 2;
    iVar4 = piVar3[1];
    uVar5 = iVar4 - 8;
    if (iVar4 == 8) {
      piVar3 = (int *)0x0;
    }
    else {
      uVar2 = 0;
      piVar3 = piVar1;
      while ((piVar3 != (int *)0x0 && (*piVar3 != 0x2059454b))) {
        iVar6 = piVar3[1];
        uVar2 = uVar2 + iVar6;
        if ((uVar2 < uVar5) && (iVar6 != -1)) {
          piVar3 = (int *)((int)piVar3 + iVar6);
        }
        else {
          piVar3 = (int *)0x0;
        }
      }
    }
    *param_1 = piVar3;
    if (piVar3 != (int *)0x0) {
      if (iVar4 == 8) {
        piVar3 = (int *)0x0;
      }
      else {
        uVar2 = 0;
        piVar3 = piVar1;
        while ((piVar3 != (int *)0x0 && (*piVar3 != 0x20524944))) {
          iVar6 = piVar3[1];
          uVar2 = uVar2 + iVar6;
          if ((uVar2 < uVar5) && (iVar6 != -1)) {
            piVar3 = (int *)((int)piVar3 + iVar6);
          }
          else {
            piVar3 = (int *)0x0;
          }
        }
      }
      param_1[2] = piVar3;
      if (piVar3 != (int *)0x0) {
        if (iVar4 == 8) {
          piVar3 = (int *)0x0;
        }
        else {
          uVar2 = 0;
          piVar3 = piVar1;
          while ((piVar3 != (int *)0x0 && (*piVar3 != 0x52544e45))) {
            iVar6 = piVar3[1];
            uVar2 = uVar2 + iVar6;
            if ((uVar2 < uVar5) && (iVar6 != -1)) {
              piVar3 = (int *)((int)piVar3 + iVar6);
            }
            else {
              piVar3 = (int *)0x0;
            }
          }
        }
        param_1[1] = piVar3;
        if (piVar3 != (int *)0x0) {
          if (iVar4 == 8) {
            piVar3 = (int *)0x0;
          }
          else {
            uVar2 = 0;
            piVar3 = piVar1;
            while ((piVar3 != (int *)0x0 && (*piVar3 != 0x41544144))) {
              iVar6 = piVar3[1];
              uVar2 = uVar2 + iVar6;
              if ((uVar2 < uVar5) && (iVar6 != -1)) {
                piVar3 = (int *)((int)piVar3 + iVar6);
              }
              else {
                piVar3 = (int *)0x0;
              }
            }
          }
          param_1[3] = piVar3;
          if (piVar3 != (int *)0x0) {
            if (iVar4 == 8) {
              piVar1 = (int *)0x0;
            }
            else {
              uVar2 = 0;
              while ((piVar1 != (int *)0x0 && (*piVar1 != 0x58454449))) {
                iVar4 = piVar1[1];
                uVar2 = uVar2 + iVar4;
                if ((uVar2 < uVar5) && (iVar4 != -1)) {
                  piVar1 = (int *)((int)piVar1 + iVar4);
                }
                else {
                  piVar1 = (int *)0x0;
                }
              }
            }
            param_1[4] = piVar1;
            if (piVar1 != (int *)0x0) {
              return 1;
            }
          }
        }
      }
    }
  }
  FUN_8107db94(param_1 + 5);
  *param_1 = (int *)0x0;
  param_1[1] = (int *)0x0;
  param_1[2] = (int *)0x0;
  param_1[3] = (int *)0x0;
  param_1[4] = (int *)0x0;
  return 0;
}

