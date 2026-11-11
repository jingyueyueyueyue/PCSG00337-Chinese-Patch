
undefined4 * FUN_810796dc(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *param_1 = &UNK_81145af4;
  if (0xf < (uint)param_1[10]) {
    func_0x81005af0(param_1[5]);
  }
  piVar1 = (int *)0x0;
  param_1[9] = 0;
  param_1[10] = 0xf;
  *(undefined *)(param_1 + 5) = 0;
  if (param_1 != (undefined4 *)0x0) {
    piVar1 = param_1 + 1;
  }
  if (*piVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      puVar2 = param_1 + 1;
    }
    uRam811ae77c = puVar2[1];
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
    uRam811ae780 = *puVar2;
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

