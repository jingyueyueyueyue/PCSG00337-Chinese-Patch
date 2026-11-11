
undefined4 * FUN_810d6294(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  *param_1 = &UNK_8113bce0;
  (**(code **)(*(int *)(iVar2 + 0xb0) + 8))(iVar2 + 0xb0);
  piVar1 = *(int **)(iVar2 + 0x80);
  if (*(int *)(iVar2 + 0x84) != 0) {
    (**(code **)(*piVar1 + 0x14))();
    piVar1 = *(int **)(iVar2 + 0x80);
  }
  *(undefined4 *)(iVar2 + 0x84) = 0;
  (**(code **)(*piVar1 + 8))(piVar1);
  (**(code **)(*(int *)(iVar2 + 0xb0) + 0xc))(iVar2 + 0xb0);
  return param_1;
}

