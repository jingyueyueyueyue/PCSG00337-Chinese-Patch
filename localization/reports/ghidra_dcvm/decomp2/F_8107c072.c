
undefined4 * FUN_8107c072(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *param_1 = &UNK_81145d60;
  func_0x81005b02(param_1[8]);
  param_1[8] = 0;
  func_0x81005b02(param_1[6]);
  param_1[6] = 0;
  func_0x81005b02(param_1[4]);
  param_1[4] = 0;
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
    uRam811ae79c = puVar2[1];
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
    uRam811ae7a0 = *puVar2;
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

