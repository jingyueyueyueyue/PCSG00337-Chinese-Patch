
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106e9d0(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined *puStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  
  iStack_1c = _UNK_8111a5b0;
  puStack_28 = &UNK_81145588;
  uStack_24 = param_2;
  iStack_20 = param_1;
  func_0x810809d4(param_1 + 0xc,&puStack_28);
  piVar1 = *(int **)(param_1 + 0x24);
  if (piVar1 != (int *)0x0) {
    puStack_28 = &UNK_81145498;
    (**(code **)(*piVar1 + 8))(piVar1,param_1,param_2);
  }
  if (_UNK_8111a5b0 != iStack_1c) {
    uVar3 = func_0x811185a0();
    piVar1 = (int *)uVar3;
    if (piVar1[0xe] == 0) {
      bVar2 = false;
      if ((*(byte *)((int)piVar1 + 0x42) & 4) != 0) {
        bVar2 = true;
      }
    }
    else {
      bVar2 = false;
      if (((*(byte *)(piVar1[0xe] + 0x42) & 4) != 0) && ((*(byte *)((int)piVar1 + 0x42) & 4) != 0))
      {
        bVar2 = true;
      }
    }
    if (bVar2) {
      (**(code **)(*piVar1 + 0x98))(piVar1);
      (**(code **)(*piVar1 + 0x9c))(piVar1,(int)((ulonglong)uVar3 >> 0x20));
      (**(code **)(*piVar1 + 0xa0))(piVar1);
    }
    return;
  }
  return;
}

