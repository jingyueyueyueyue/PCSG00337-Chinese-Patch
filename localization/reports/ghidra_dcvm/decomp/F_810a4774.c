
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810a4774(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined2 uStack_28;
  undefined2 uStack_26;
  int iStack_24;
  
  iStack_24 = _UNK_8111a5b0;
  puVar7 = *(undefined4 **)(param_1 + *param_2 * 0x18 + 0xc);
  *(undefined2 *)(param_1 + *param_2 * 2 + 0xcc) = 0;
  iVar4 = *param_2;
  iVar2 = param_1 + iVar4 * 0x18;
  if (puVar7[2] == 3) {
    FUN_810a1fa2(&uStack_28,*(undefined4 *)(param_1 + 200),iVar2 + 0x14,*(undefined4 *)(iVar2 + 4),
                 *puVar7,0x81191264,0,1);
    *(undefined2 *)(param_1 + *param_2 * 2 + 0xcc) = uStack_28;
    iVar4 = *param_2;
  }
  else if (puVar7[2] == 2) {
    uVar5 = *puVar7;
    uVar6 = *(undefined4 *)(param_1 + 200);
    uVar3 = *(undefined4 *)(iVar2 + 4);
    uVar1 = func_0x810783d6(uVar5,puVar7[1]);
    func_0x810a1e48(&uStack_26,uVar6,iVar2 + 0x14,uVar3,uVar5,uVar1,0,1);
    *(undefined2 *)(param_1 + *param_2 * 2 + 0xcc) = uStack_26;
    iVar4 = *param_2;
  }
  if (_UNK_8111a5b0 == iStack_24) {
    return;
  }
  uVar8 = func_0x811185a0(*(short *)(param_1 + iVar4 * 2 + 0xcc) != 0);
  func_0x810a2916(*(undefined4 *)((int)uVar8 + 200),
                  (int)uVar8 + *(int *)((ulonglong)uVar8 >> 0x20) * 2 + 0xcc);
  return;
}

