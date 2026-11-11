
undefined4 * FUN_81084de4(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  
  *param_1 = &UNK_81146368;
  param_1[1] = 0;
  iVar1 = func_0x81005a98(0xe4);
  iVar5 = 0;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0xdc) = 0;
    *(undefined4 *)(iVar1 + 0xe0) = 0;
    iVar5 = iVar1;
  }
  param_1[9] = iVar5;
  func_0x8107682c(param_1);
  iVar5 = param_1[9];
  puVar2 = (undefined4 *)func_0x81005a98(8);
  puVar4 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = *(undefined4 *)(iRam811ae7b4 + 0x20);
    *puVar2 = &UNK_811463c0;
    puVar4 = puVar2;
  }
  piVar3 = *(int **)(iVar5 + 0xe0);
  *(undefined4 **)(iVar5 + 0xe0) = puVar4;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))();
  }
  *(undefined4 *)(param_1[9] + 0x10) = 8;
  return param_1;
}

