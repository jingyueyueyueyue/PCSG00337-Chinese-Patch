
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81079552(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  uint uStack_60;
  undefined auStack_5c [8];
  undefined4 uStack_54;
  int *piStack_50;
  undefined4 *puStack_48;
  undefined4 *puStack_44;
  undefined4 uStack_40;
  undefined *puStack_3c;
  uint uStack_20;
  int *piStack_1c;
  
  piStack_1c = _UNK_8111a5b0;
  *param_2 = 0;
  *param_3 = 0;
  iVar1 = FUN_81078eaa(param_1,param_2,&uStack_20);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    puVar7 = (undefined4 *)*param_2;
    param_2 = (undefined4 *)puVar7[0xe];
    if (param_2 == (undefined4 *)0x0) {
      uStack_20 = 0xffffffff;
    }
    puVar3 = (undefined4 *)0x0;
    param_4 = puVar7;
    if ((-1 < (int)uStack_20) &&
       (puVar3 = (undefined4 *)0x0, param_4 = puVar3, uStack_20 < *(uint *)(puVar7[0xd] + 8))) {
      puVar3 = param_2 + uStack_20 * 3;
      param_4 = puVar3;
    }
    uVar2 = 1;
    *param_3 = puVar3;
  }
  if (_UNK_8111a5b0 == piStack_1c) {
    return;
  }
  piVar6 = piStack_1c;
  uVar8 = func_0x811185a0(uVar2);
  piVar4 = (int *)((ulonglong)uVar8 >> 0x20);
  puStack_3c = &UNK_8111a5b0;
  uStack_40 = 0;
  piStack_50 = _UNK_8111a5b0;
  uStack_54 = 0;
  puStack_48 = param_3;
  puStack_44 = param_2;
  func_0x81080bb2(auStack_5c,param_4);
  *piVar4 = 0;
  *piVar6 = 0;
  iVar1 = FUN_81078eaa((int)uVar8,piVar4,&uStack_60,auStack_5c,param_5);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *(int *)(*piVar4 + 0x38);
    if (iVar1 == 0) {
      uStack_60 = 0xffffffff;
    }
    iVar5 = 0;
    if ((-1 < (int)uStack_60) && (iVar5 = 0, uStack_60 < *(uint *)(*(int *)(*piVar4 + 0x34) + 8))) {
      iVar5 = iVar1 + uStack_60 * 0xc;
    }
    *piVar6 = iVar5;
    uVar2 = 1;
  }
  func_0x81005af0(uStack_54);
  if (_UNK_8111a5b0 != piStack_50) {
    func_0x811185a0(uVar2);
    uRam81191264 = 0xffffffff;
    return;
  }
  return;
}

