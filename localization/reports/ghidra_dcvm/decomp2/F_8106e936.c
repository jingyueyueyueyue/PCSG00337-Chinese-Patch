
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106e936(int param_1,short param_2,short param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined8 uVar5;
  short sStack_20;
  short sStack_1e;
  int *piStack_1c;
  
  piStack_1c = _UNK_8111a5b0;
  if (*(int *)(param_1 + 0x20) == 0) {
    uVar1 = 0;
  }
  else {
    FUN_8106e4ec(&sStack_20,param_1);
    uVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 8))
                      (*(int **)(param_1 + 0x20),(int)sStack_20,(int)sStack_1e,(int)param_2,
                       (int)param_3);
  }
  if (_UNK_8111a5b0 == piStack_1c) {
    return;
  }
  piVar4 = piStack_1c;
  uVar5 = func_0x811185a0(uVar1);
  puVar2 = (undefined4 *)func_0x81005a98(0x14);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = &UNK_81145574;
    puVar2[1] = 0;
    iVar3 = *piVar4;
    puVar2[2] = iVar3;
    if (iVar3 == 0) {
      puVar2[3] = 0;
      puVar2[4] = 0;
    }
    else {
      puVar2[3] = piVar4;
      puVar2[4] = piVar4[2];
      piVar4[2] = (int)(puVar2 + 2);
      *(undefined4 **)(puVar2[4] + 4) = puVar2 + 2;
    }
    FUN_81080a56((int)uVar5 + 0xc,(int)((ulonglong)uVar5 >> 0x20),puVar2);
  }
  return;
}

