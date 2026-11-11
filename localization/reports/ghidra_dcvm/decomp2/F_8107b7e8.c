
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8107b7e8(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  char *pcVar7;
  undefined8 uVar8;
  undefined auStack_48 [8];
  undefined4 uStack_40;
  int *piStack_3c;
  uint uStack_34;
  undefined *puStack_30;
  undefined4 uStack_18;
  int iStack_14;
  int *piStack_10;
  
  piStack_10 = _UNK_8111a5b0;
  if ((*(int *)(param_1 + 4) == 0) || (iVar4 = *(int *)(param_1 + 8), iVar4 == 0)) {
    iStack_14 = 0;
  }
  else if (param_2 < *(uint *)(iVar4 + 8)) {
    iStack_14 = *(int *)(iVar4 + param_2 * 4 + 0xc) + *(int *)(param_1 + 0x10);
  }
  else {
    iStack_14 = 0;
  }
  uStack_18 = 0;
  uVar3 = (uint)(iStack_14 != 0);
  FUN_8107db94(&uStack_18);
  if (_UNK_8111a5b0 == piStack_10) {
    return uVar3;
  }
  piVar5 = piStack_10;
  iVar4 = func_0x811185a0(uVar3);
  puStack_30 = &UNK_8111a5b0;
  piStack_3c = _UNK_8111a5b0;
  uStack_34 = uVar3;
  if ((*(int *)(iVar4 + 4) == 0) || (*(int *)(iVar4 + 8) == 0)) {
    uVar3 = 0;
  }
  else {
    uStack_40 = 0;
    FUN_81080bb2(auStack_48);
    uVar1 = uStack_40;
    pcVar7 = (char *)(*(int *)(iVar4 + 0xc) + 8);
    if (*(char *)(*(int *)(iVar4 + 0xc) + 8) != '\0') {
      iVar4 = 0;
      do {
        iVar2 = func_0x811181a0(pcVar7,uVar1);
        if (iVar2 == 0) {
          if (iVar4 != -1) {
            if (piVar5 != (int *)0x0) {
              *piVar5 = iVar4;
            }
            func_0x81005af0(uStack_40);
            uVar3 = 1;
            goto LAB_8107b8cc;
          }
          break;
        }
        iVar2 = func_0x81118330(pcVar7);
        pcVar7 = pcVar7 + iVar2 + 1;
        iVar4 = iVar4 + 1;
      } while (*pcVar7 != '\0');
    }
    func_0x81005af0(uStack_40);
    uVar3 = 0;
  }
LAB_8107b8cc:
  if (_UNK_8111a5b0 == piStack_3c) {
    return uVar3;
  }
  uVar8 = func_0x811185a0(uVar3);
  uVar3 = (uint)((ulonglong)uVar8 >> 0x20);
  iVar4 = (int)uVar8;
  if (((*(int *)(iVar4 + 4) != 0) && (*(int *)(iVar4 + 8) != 0)) && (*(int *)(iVar4 + 0xc) != 0)) {
    if (*(uint *)(*(int *)(iVar4 + 8) + 8) <= uVar3) {
      return 0;
    }
    uVar6 = *(int *)(iVar4 + 0xc) + 8;
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      iVar4 = func_0x81118330(uVar6);
      uVar6 = iVar4 + uVar6 + 1;
    }
    return uVar6;
  }
  return 0;
}

