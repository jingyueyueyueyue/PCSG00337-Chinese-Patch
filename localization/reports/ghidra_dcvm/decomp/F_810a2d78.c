
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810a2d78(undefined2 *param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined param_8)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined auStack_40 [8];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined uStack_30;
  int iStack_2c;
  
  iStack_2c = _UNK_8111a5b0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_30 = param_8;
  uStack_34 = param_5;
  piVar1 = (int *)(**(code **)(**(int **)(*param_2 + 4) + 0x20))(*(int **)(*param_2 + 4));
  iVar6 = *piVar1;
  if (iVar6 != 0) {
    uStack_38 = 0;
    func_0x81080bb2(auStack_40,param_6);
    iVar6 = FUN_81079552(iVar6,&uStack_48,&uStack_44,auStack_40,param_7);
    func_0x81005af0(uStack_38);
    if (iVar6 != 0) {
      uStack_38 = 0;
      func_0x810a21f2(param_1,param_2,param_3,param_4,uStack_34,uStack_48,uStack_44,uStack_30);
      goto LAB_810a2e18;
    }
  }
  *param_1 = 0;
LAB_810a2e18:
  if (_UNK_8111a5b0 == iStack_2c) {
    return;
  }
  uVar7 = func_0x811185a0();
  pcVar2 = (char *)((ulonglong)uVar7 >> 0x20);
  iVar6 = (int)uVar7;
  (**(code **)(*(int *)(iVar6 + 0x24) + 8))(iVar6 + 0x24);
  uVar4 = (uint)(byte)pcVar2[1];
  iVar3 = *(int *)(iVar6 + 0x24);
  if ((*pcVar2 == *(char *)(*(int *)(iVar6 + 0x18) + uVar4)) &&
     (iVar5 = uVar4 * 0x34 + *(int *)(iVar6 + 4), iVar5 != 0)) {
    *(undefined *)(iVar5 + 0x27) = 1;
  }
  (**(code **)(iVar3 + 0xc))(iVar6 + 0x24);
  return;
}

