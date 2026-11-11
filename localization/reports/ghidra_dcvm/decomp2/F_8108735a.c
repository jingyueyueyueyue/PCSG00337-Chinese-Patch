
void FUN_8108735a(int param_1)

{
  int iVar1;
  
  iVar1 = **(int **)(param_1 + 4);
  **(int **)(param_1 + 4) = 0;
  if (iVar1 != 0) {
    FUN_8108a4ce();
    func_0x81005af0();
  }
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  *(undefined4 *)(*(int *)(param_1 + 4) + 4) = 0;
  if (iVar1 != 0) {
    func_0x8108769e();
    func_0x81005af0();
  }
  return;
}

