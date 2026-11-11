
void FUN_81086c66(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = *(int *)(iVar2 + 8);
  *(undefined4 *)(iVar2 + 8) = 0;
  if (iVar1 != 0) {
    FUN_8108a29e();
    func_0x81005af0();
    iVar2 = *(int *)(param_1 + 4);
  }
  iVar1 = *(int *)(iVar2 + 0xc);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  if (iVar1 != 0) {
    func_0x8108769e();
    func_0x81005af0();
  }
  return;
}

