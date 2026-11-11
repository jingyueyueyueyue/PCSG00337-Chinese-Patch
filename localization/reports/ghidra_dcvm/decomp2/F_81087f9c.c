
undefined4 * FUN_81087f9c(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  *param_1 = &UNK_811464bc;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar1 = func_0x81005a98(0x80a0);
  iVar4 = 0;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x68) = 0;
    *(undefined4 *)(iVar1 + 0x74) = 0;
    *(undefined4 *)(iVar1 + 0x78) = 0;
    *(undefined4 *)(iVar1 + 0x7c) = 0;
    *(undefined4 *)(iVar1 + 0x80) = 0;
    *(undefined4 *)(iVar1 + 0x84) = 0;
    *(undefined4 *)(iVar1 + 0x8098) = 0;
    *(undefined4 *)(iVar1 + 0x809c) = 0;
    iVar4 = iVar1;
  }
  param_1[0x27] = iVar4;
  func_0x81076eba(param_1);
  iVar4 = param_1[0x27];
  piVar2 = (int *)func_0x81005a98(8);
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    piVar2[1] = *(int *)(iRam811ae7b4 + 0x14);
    *piVar2 = (int)&UNK_81146504;
    piVar3 = piVar2;
  }
  piVar2 = *(int **)(iVar4 + 0x8098);
  *(int **)(iVar4 + 0x8098) = piVar3;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
  }
  iVar4 = param_1[0x27];
  piVar2 = (int *)func_0x81005a98(8);
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    piVar2[1] = *(int *)(iRam811ae7b4 + 0x20);
    *piVar2 = (int)&UNK_8114651c;
    piVar3 = piVar2;
  }
  piVar2 = *(int **)(iVar4 + 0x809c);
  *(int **)(iVar4 + 0x809c) = piVar3;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
  }
  return param_1;
}

