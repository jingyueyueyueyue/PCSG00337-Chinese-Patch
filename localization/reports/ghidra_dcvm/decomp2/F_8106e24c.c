
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8106e24c(int *param_1,undefined4 param_2,code *param_3)

{
  short sVar1;
  short sVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined *puStack_28;
  undefined4 uStack_24;
  int *piStack_20;
  int iStack_1c;
  
  iStack_1c = _UNK_8111a5b0;
  sVar1 = *(short *)((int)param_1 + 0x5a);
  sVar2 = 0;
  *(undefined2 *)(param_1 + 0x16) = 0;
  *(undefined2 *)((int)param_1 + 0x5a) = 0;
  if (param_1[0x13] != 0) {
    iVar5 = param_1[0x15];
    param_3 = (code *)param_1[0x12];
    if ((param_1[0x14] & 1U) == 0) {
      uVar3 = func_0x810c8324((int)(short)(*(short *)(iVar5 + 8) - *(short *)(iVar5 + 4)) *
                              (int)param_3);
      *(undefined2 *)(param_1 + 0x16) = uVar3;
    }
    else {
      sVar2 = func_0x810c8324((int)(short)(*(short *)(iVar5 + 10) - *(short *)(iVar5 + 6)) *
                              (int)param_3);
      *(short *)((int)param_1 + 0x5a) = sVar2;
    }
  }
  if (sVar1 != sVar2) {
    uStack_24 = 0x8000001b;
    puStack_28 = &UNK_8114516c;
    param_3 = *(code **)(*param_1 + 0x44);
    piStack_20 = param_1;
    (*param_3)(param_1,&puStack_28);
  }
  if (_UNK_8111a5b0 != iStack_1c) {
    uVar6 = func_0x811185a0();
    iVar5 = (int)uVar6;
    if (*(int *)(param_3 + 4) == -0x7fffffea) {
      uVar4 = *(undefined4 *)(param_3 + 0x10);
      *(undefined4 *)(iVar5 + 0x48) = *(undefined4 *)(param_3 + 0xc);
      *(undefined4 *)(iVar5 + 0x4c) = uVar4;
      FUN_8106e24c(iVar5);
    }
    FUN_8106ed52(iVar5,(int)((ulonglong)uVar6 >> 0x20),param_3);
    return;
  }
  return;
}

