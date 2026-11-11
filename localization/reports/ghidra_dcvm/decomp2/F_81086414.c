
void FUN_81086414(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x22];
  *param_1 = &UNK_811463f4;
  if (iVar1 != 0) {
    if (*(int **)(iVar1 + 0x30) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x30) + 4))();
    }
    *(undefined4 *)(iVar1 + 0x30) = 0;
    if (*(int **)(iVar1 + 0x2c) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x2c) + 4))();
    }
    *(undefined4 *)(iVar1 + 0x2c) = 0;
    func_0x81005af0(iVar1);
  }
  param_1[0x22] = 0;
  func_0x81005af0(param_1);
  return;
}

