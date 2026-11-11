
void FUN_8107e03a(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  puVar3 = (undefined4 *)*param_1;
  if ((undefined4 *)puVar3[param_3] == (undefined4 *)0x0) {
    if (param_3 != 1) {
      puVar2 = puVar3 + param_3;
      uVar4 = param_3;
      do {
        puVar2 = puVar2 + -1;
        puVar5 = (undefined4 *)*puVar2;
        uVar4 = uVar4 - 1;
        if (puVar5 != (undefined4 *)0x0) {
          *param_2 = *puVar5;
          *puVar5 = param_2;
          goto LAB_8107e07c;
        }
      } while (1 < uVar4);
    }
    *param_2 = *puVar3;
    *puVar3 = param_2;
    puVar3 = (undefined4 *)*param_1;
  }
  else {
    *param_2 = *(undefined4 *)puVar3[param_3];
    *(undefined4 **)puVar3[param_3] = param_2;
  }
LAB_8107e07c:
  puVar3[param_3] = param_2;
  iVar1 = *(int *)(param_1[1] + param_3 * 4);
  if (iVar1 != -1) {
    *(int *)(param_1[1] + param_3 * 4) = iVar1 + 1;
  }
  param_1[3] = param_1[3] + 1;
  return;
}

