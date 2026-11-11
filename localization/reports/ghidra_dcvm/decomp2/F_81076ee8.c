
void FUN_81076ee8(uint *param_1)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  piVar3 = (int *)param_1[2];
  if (piVar3 != (int *)0x0) {
    uVar4 = param_1[3];
    uVar1 = uVar4;
    while (uVar4 != 0) {
      if (*(int *)(uVar4 + 0x10) != 0) {
        (**(code **)(*piVar3 + 0x10))(piVar3);
        piVar3 = (int *)param_1[2];
        uVar4 = uVar1;
      }
      if (uVar4 != 0) {
        uVar4 = *(uint *)(uVar4 + 4);
        uVar1 = uVar4;
      }
    }
  }
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  uVar4 = *param_1;
  param_1[6] = 0;
  if (uVar4 != 0) {
    iVar5 = 0;
    uVar1 = 0;
    piVar3 = (int *)0x0;
    do {
      uVar6 = param_1[1];
      piVar2 = (int *)(uVar6 + iVar5);
      piVar2[4] = 0;
      piVar2[5] = 0;
      piVar2[6] = 0;
      if (piVar3 == (int *)0x0) {
        piVar2[1] = 0;
        param_1[6] = (uint)piVar2;
      }
      else {
        piVar2[1] = (int)piVar3;
        *piVar3 = (int)piVar2;
      }
      *(undefined4 *)(uVar6 + iVar5) = 0;
      uVar1 = uVar1 + 1;
      param_1[5] = (uint)piVar2;
      iVar5 = iVar5 + 0x20;
      piVar3 = piVar2;
    } while (uVar1 < uVar4);
  }
  return;
}

