
undefined4 FUN_810708bc(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  bVar1 = *(byte *)((int)param_1 + 0x11);
  uVar5 = 0;
  if (bVar1 != 0) {
    if (bVar1 < 2) {
      (**(code **)(*(int *)param_1[2] + 0xc))();
      iVar2 = (**(code **)(*(int *)param_1[2] + 0x10))();
      if (iVar2 != 0) {
        *(undefined *)((int)param_1 + 0x11) = 2;
      }
    }
    else if (bVar1 < 3) {
      uVar5 = 1;
      if ((*(char *)((int)param_1 + 0x12) == '\0') &&
         (piVar3 = (int *)param_1[2], piVar3 != (int *)0x0)) {
        param_1[2] = 0;
        (**(code **)(*piVar3 + 4))();
        *(undefined *)((int)param_1 + 0x12) = 0;
      }
      *(undefined *)((int)param_1 + 0x11) = 0;
      if (*(byte *)(param_1 + 4) - 1 < 5) {
        uVar4 = *param_1;
        switch(*(byte *)(param_1 + 4)) {
        case 1:
          FUN_810702d6(uVar4,*(undefined2 *)((int)param_1 + 0xe));
          break;
        case 2:
          FUN_8107037c(uVar4,*(undefined2 *)((int)param_1 + 0xe));
          break;
        case 3:
          FUN_8107026c(uVar4,*(undefined2 *)((int)param_1 + 0xe));
          break;
        case 4:
          FUN_8107040c();
          break;
        case 5:
          FUN_810704bc(uVar4,*(undefined2 *)((int)param_1 + 0xe));
        }
      }
      *(undefined *)(param_1 + 4) = 0;
    }
  }
  return uVar5;
}

