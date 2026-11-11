
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106e5f2(int *param_1,short param_2,short param_3)

{
  int *piVar1;
  int iVar2;
  undefined extraout_r1;
  code *pcVar3;
  short sStack_20;
  short sStack_1e;
  int iStack_1c;
  
  iStack_1c = _UNK_8111a5b0;
  if (param_1[0xe] == 0) {
    pcVar3 = *(code **)(*param_1 + 0x10);
  }
  else {
    FUN_8106e4ec(&sStack_20);
    param_2 = param_2 - sStack_20;
    param_3 = param_3 - sStack_1e;
    pcVar3 = *(code **)(*param_1 + 0x10);
  }
  (*pcVar3)(param_1,(int)param_2,(int)param_3);
  if (_UNK_8111a5b0 == iStack_1c) {
    return;
  }
  piVar1 = (int *)func_0x811185a0();
  iVar2 = (**(code **)(*piVar1 + 0x8c))(piVar1,extraout_r1);
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x50))(piVar1,extraout_r1);
  }
  return;
}

