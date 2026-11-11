
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81077416(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iStack_48;
  undefined4 uStack_44;
  undefined auStack_40 [8];
  int iStack_38;
  undefined auStack_34 [8];
  int iStack_2c;
  int iStack_28;
  
  iStack_28 = _UNK_8111a5b0;
  iStack_38 = 0;
  func_0x81080bb2(auStack_40);
  piVar1 = (int *)(**(code **)(*param_1 + 0x20))(param_1);
  piVar7 = param_1 + 0xb;
  if ((*piVar1 == 0) ||
     (iVar2 = FUN_81078eaa(*piVar1,&iStack_48,&uStack_44,auStack_40,param_3), iVar2 == 0)) {
    (**(code **)(param_1[0xb] + 8))(piVar7);
    iVar2 = 0;
    piVar1 = *(int **)param_1[4];
    if (piVar1 != (int *)0x0) {
      iVar2 = 0;
      do {
        uVar4 = (int)(((int)piVar1 - param_1[0x32]) +
                     ((uint)((int)piVar1 - param_1[0x32] >> 3) >> 0x1d)) >> 3;
        if (((int)uVar4 < 0) || (param_1[0x35] <= (int)uVar4)) {
          uVar5 = 0;
          uVar4 = 0;
        }
        else {
          uVar5 = (uint)*(byte *)(param_1[0x37] + uVar4) | (uVar4 & 0xff) << 8;
        }
        piVar6 = param_1 + 0x739;
        if (uVar5 != 0) {
          piVar6 = param_1 + (uVar4 & 0xff) * 7 + 0x39;
        }
        if (*(char *)(piVar6 + 6) == '\0') {
          iStack_2c = 0;
          func_0x81080bb2(auStack_34,piVar6[4]);
          if ((((iStack_2c != 0) && (iStack_38 != 0)) && (iVar3 = func_0x811181a0(), iVar3 == 0)) &&
             ((piVar1[1] = piVar1[1] | 1, iVar2 == 0 && (iVar2 = 0, (piVar1[1] & 2U) == 0)))) {
            iVar2 = 1;
          }
          func_0x81005af0(iStack_2c);
          iStack_2c = 0;
        }
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)0x0);
    }
    (**(code **)(param_1[0xb] + 0xc))(piVar7);
  }
  else {
    (**(code **)(param_1[0xb] + 8))(piVar7);
    iVar2 = 0;
    piVar1 = *(int **)param_1[4];
    if (piVar1 != (int *)0x0) {
      iVar2 = 0;
      do {
        uVar4 = (int)(((int)piVar1 - param_1[0x32]) +
                     ((uint)((int)piVar1 - param_1[0x32] >> 3) >> 0x1d)) >> 3;
        if (((int)uVar4 < 0) || (param_1[0x35] <= (int)uVar4)) {
          uVar5 = 0;
          uVar4 = 0;
        }
        else {
          uVar5 = (uint)*(byte *)(param_1[0x37] + uVar4) | (uVar4 & 0xff) << 8;
        }
        piVar6 = param_1 + 0x739;
        if (uVar5 != 0) {
          piVar6 = param_1 + (uVar4 & 0xff) * 7 + 0x39;
        }
        if ((((*(char *)(piVar6 + 6) != '\0') &&
             (iVar3 = func_0x810783d6(iStack_48,uStack_44), piVar6[4] == iStack_48)) &&
            (*(int *)(iVar3 + 4) == *(int *)(piVar6[5] + 4))) &&
           ((piVar1[1] = piVar1[1] | 1, iVar2 == 0 && (iVar2 = 0, (piVar1[1] & 2U) == 0)))) {
          iVar2 = 1;
        }
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)0x0);
    }
    (**(code **)(param_1[0xb] + 0xc))(piVar7);
  }
  func_0x81005af0(iStack_38);
  if (_UNK_8111a5b0 != iStack_28) {
    iVar2 = func_0x811185a0(iVar2);
    (**(code **)(*(int *)(iVar2 + 0x2c) + 8))(iVar2 + 0x2c);
    iVar3 = *(int *)(iVar2 + 0x2c);
    piVar1 = (int *)**(int **)(iVar2 + 0x10);
    while (piVar1 != (int *)0x0) {
      piVar1[1] = piVar1[1] | 1;
      piVar1 = (int *)*piVar1;
    }
    (**(code **)(iVar3 + 0xc))(iVar2 + 0x2c);
    return;
  }
  return;
}

