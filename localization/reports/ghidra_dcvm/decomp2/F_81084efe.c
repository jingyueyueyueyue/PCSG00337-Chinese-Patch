
undefined4 * FUN_81084efe(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[9];
  *param_1 = &UNK_81146368;
  if (iVar1 != 0) {
    if (*(int **)(iVar1 + 0xe0) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0xe0) + 4))();
    }
    *(undefined4 *)(iVar1 + 0xe0) = 0;
    if (*(int **)(iVar1 + 0xdc) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0xdc) + 4))();
    }
    *(undefined4 *)(iVar1 + 0xdc) = 0;
    func_0x81005af0(iVar1);
  }
  param_1[9] = 0;
  return param_1;
}

