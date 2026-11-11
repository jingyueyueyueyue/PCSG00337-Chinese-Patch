
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106e69a(int *param_1,byte param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  char extraout_r1;
  uint uVar5;
  undefined4 uVar6;
  undefined *puStack_40;
  undefined4 uStack_3c;
  int *piStack_38;
  int iStack_34;
  int *piStack_30;
  uint uStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  undefined *puStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  uVar5 = (uint)param_2;
  iVar1 = (**(code **)(*param_1 + 0x90))(param_1,uVar5);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x54))(param_1,uVar5);
    piVar2 = (int *)param_1[0xe];
    uStack_1c = 0x8000000f;
    puStack_20 = &UNK_81145420;
    piVar3 = (int *)0x0;
    if (uVar5 != 0) {
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
  uVar6 = 0x8106e70b;
  piVar3 = (int *)func_0x811185a0();
  puStack_28 = &UNK_8111a5b0;
  iStack_34 = _UNK_8111a5b0;
  piStack_30 = param_1;
  uStack_2c = uVar5;
  uStack_24 = uVar6;
  iVar1 = (**(code **)(*piVar3 + 0x94))(piVar3,extraout_r1);
  if (iVar1 != 0) {
    (**(code **)(*piVar3 + 0x58))(piVar3,extraout_r1);
    piVar4 = (int *)piVar3[0xe];
    uStack_3c = 0x80000010;
    puStack_40 = &UNK_81145448;
    piVar2 = (int *)0x0;
    if (extraout_r1 != '\0') {
      piVar2 = piVar3;
    }
    if (piVar4 != (int *)0x0) {
      piStack_38 = piVar2;
      (**(code **)(*piVar4 + 0xac))(piVar4,piVar3,&puStack_40);
    }
  }
  if (_UNK_8111a5b0 == iStack_34) {
    return;
  }
  iVar1 = func_0x811185a0();
  *(byte *)(iVar1 + 0x42) = *(byte *)(iVar1 + 0x42) | 1;
  return;
}

