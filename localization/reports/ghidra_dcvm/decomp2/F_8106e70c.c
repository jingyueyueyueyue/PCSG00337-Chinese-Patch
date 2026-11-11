
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106e70c(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined *puStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  iVar1 = (**(code **)(*param_1 + 0x94))(param_1,param_2);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x58))(param_1,param_2);
    piVar2 = (int *)param_1[0xe];
    uStack_1c = 0x80000010;
    puStack_20 = &UNK_81145448;
    piVar3 = (int *)0x0;
    if (param_2 != '\0') {
      piVar3 = param_1;
    }
    if (piVar2 != (int *)0x0) {
      piStack_18 = piVar3;
      (**(code **)(*piVar2 + 0xac))(piVar2,param_1,&puStack_20);
    }
  }
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  iVar1 = func_0x811185a0();
  *(byte *)(iVar1 + 0x42) = *(byte *)(iVar1 + 0x42) | 1;
  return;
}

