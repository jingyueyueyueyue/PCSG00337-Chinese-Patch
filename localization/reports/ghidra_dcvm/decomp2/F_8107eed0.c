
undefined4 * FUN_8107eed0(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *param_1 = &UNK_81146088;
  if ((int *)param_1[3] != (int *)0x0) {
    (**(code **)(*(int *)param_1[3] + 4))();
  }
  piVar1 = (int *)0x0;
  param_1[3] = 0;
  if (param_1 != (undefined4 *)0x0) {
    piVar1 = param_1 + 1;
  }
  if (*piVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      puVar2 = param_1 + 1;
    }
    uRam811ae7a8 = puVar2[1];
  }
  else {
    puVar2 = (undefined4 *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      puVar2 = param_1 + 1;
    }
    piVar1 = (int *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      piVar1 = param_1 + 1;
    }
    *(undefined4 *)(*piVar1 + 8) = puVar2[1];
  }
  puVar2 = (undefined4 *)0x0;
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = param_1 + 1;
  }
  if (puVar2[1] == 0) {
    puVar2 = (undefined4 *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      puVar2 = param_1 + 1;
    }
    uRam811ae7ac = *puVar2;
  }
  else {
    puVar2 = (undefined4 *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      puVar2 = param_1 + 1;
    }
    puVar3 = (undefined4 *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      puVar3 = param_1 + 1;
    }
    *(undefined4 *)(puVar3[1] + 4) = *puVar2;
  }
  puVar2 = (undefined4 *)0x0;
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = param_1 + 1;
  }
  puVar2[1] = 0;
  puVar2 = (undefined4 *)0x0;
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = param_1 + 1;
  }
  *puVar2 = 0;
  return param_1;
}

