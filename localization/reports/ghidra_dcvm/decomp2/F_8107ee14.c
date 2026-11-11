
undefined4 * FUN_8107ee14(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  
  param_1[1] = 0;
  param_1[2] = 0;
  if (puRam811ae7ac == (undefined4 *)0x0) {
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
    puRam811ae7a8 = param_1;
  }
  else {
    puVar2 = (undefined4 *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      puVar2 = param_1 + 1;
    }
    puVar2[1] = 0;
    piVar3 = (int *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      piVar3 = param_1 + 1;
    }
    *piVar3 = (int)puRam811ae7ac;
    *(undefined4 **)((int)puRam811ae7ac + 8) = param_1;
  }
  puRam811ae7ac = param_1;
  *param_1 = &UNK_81146088;
  uVar4 = 0;
  iVar1 = func_0x81005a98(8);
  if (iVar1 != 0) {
    uVar4 = func_0x8108c77a(iVar1,1,1);
  }
  param_1[3] = uVar4;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *(undefined *)(param_1 + 9) = 0;
  *(undefined *)((int)param_1 + 0x25) = 0;
  *(undefined *)((int)param_1 + 0x26) = 1;
  param_1[10] = &UNK_8113742c;
  return param_1;
}

