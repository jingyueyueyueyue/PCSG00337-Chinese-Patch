
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810685ec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined auStack_118 [256];
  undefined4 uStack_18;
  int iStack_14;
  
  puVar5 = auStack_118;
  iStack_14 = _UNK_8111a5b0;
  func_0x81051aee(param_3,auStack_118,param_2);
  func_0x810697dc(param_1,uStack_18,8);
  func_0x8106986a(param_1,auStack_118,uStack_18);
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  uVar3 = uStack_18;
  uVar4 = func_0x811185a0();
  iVar2 = (int)((ulonglong)uVar4 >> 0x20);
  puVar6 = &UNK_8111a5b0;
  iVar1 = func_0x81069828(iVar2,8);
  func_0x81051c4e(uVar3,(int)uVar4,*(int *)(iVar2 + 0xc) + (*(int *)(iVar2 + 8) + 7U >> 3),param_4,
                  param_1,puVar5,puVar6);
  func_0x81069928(iVar2,(iVar1 + (*(int *)(iVar2 + 8) + 7U >> 3)) * 8);
  return;
}

