
void FUN_8108eb80(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = func_0x81005a98(8);
  if (iVar1 != 0) {
    uVar2 = func_0x810942ac();
  }
  iVar1 = *(int *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  if (iVar1 != 0) {
    func_0x810942c4(iVar1);
    func_0x81005af0();
    uVar2 = *(undefined4 *)(param_1 + 0x10);
  }
  FUN_810942c8(uVar2,&UNK_81137c38,&UNK_8108efbd,0x40,0x20000,0,0x70000,0);
  FUN_81094306(*(undefined4 *)(param_1 + 0x10),param_1);
  return;
}

