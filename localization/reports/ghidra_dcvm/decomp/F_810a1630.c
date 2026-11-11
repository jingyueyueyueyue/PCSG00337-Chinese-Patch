
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810a1630(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined auStack_30 [8];
  undefined4 uStack_28;
  uint uStack_24;
  
  uStack_24 = _UNK_8111a5b0;
  *param_2 = 0;
  piVar1 = *(int **)(*param_1 + 4);
  *param_3 = 0;
  piVar1 = (int *)(**(code **)(*piVar1 + 0x20))();
  iVar4 = *piVar1;
  if (iVar4 == 0) {
    uVar2 = 0;
  }
  else {
    uStack_28 = 0;
    func_0x81080bb2(auStack_30,param_4);
    uVar2 = FUN_81078eaa(iVar4,param_2,param_3,auStack_30,param_5);
    func_0x81005af0(uStack_28);
  }
  if (_UNK_8111a5b0 == uStack_24) {
    return;
  }
  uVar3 = uStack_24;
  uVar5 = func_0x811185a0(uVar2);
  iVar4 = (int)uVar5;
  (**(code **)(*(int *)(iVar4 + 0x14) + 8))(iVar4 + 0x14);
  func_0x8107e03a(iVar4,(int)((ulonglong)uVar5 >> 0x20),(uVar3 & 0xff) + 1);
  (**(code **)(*(int *)(iVar4 + 0x14) + 0xc))(iVar4 + 0x14);
  return;
}

