
undefined4 * FUN_8108807a(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x27];
  *param_1 = &UNK_811464bc;
  if (iVar1 != 0) {
    if (*(int **)(iVar1 + 0x809c) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x809c) + 4))();
    }
    *(undefined4 *)(iVar1 + 0x809c) = 0;
    if (*(int **)(iVar1 + 0x8098) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x8098) + 4))();
    }
    *(undefined4 *)(iVar1 + 0x8098) = 0;
    func_0x81005af0(iVar1);
  }
  param_1[0x27] = 0;
  return param_1;
}

