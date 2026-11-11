
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81077774(ushort *param_1,int *param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,int param_8,int param_9)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined auStack_48 [8];
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  ushort *puStack_30;
  int iStack_2c;
  
  iStack_2c = _UNK_8111a5b0;
  iStack_38 = param_9;
  iStack_34 = param_8;
  iStack_3c = param_3;
  puStack_30 = param_1;
  piVar1 = (int *)(**(code **)(*param_2 + 0x20))(param_2);
  iVar6 = *piVar1;
  uStack_40 = 0;
  func_0x81080bb2(auStack_48,param_5);
  if (iVar6 != 0) {
    iVar6 = FUN_81078eaa(iVar6,&uStack_50,&uStack_4c,auStack_48,param_6);
    if (iVar6 != 0) {
      uVar2 = func_0x810783d6(uStack_50,uStack_4c);
      func_0x8107766c(puStack_30,param_2,iStack_3c,param_4,uStack_50,uVar2,param_7,iStack_34,
                      iStack_38);
      func_0x81005af0(uStack_40);
      goto LAB_810778fa;
    }
  }
  (**(code **)(param_2[0xb] + 8))(param_2 + 0xb);
  uVar5 = 0;
  iVar6 = (**(code **)(param_2[2] + 8))(param_2 + 2,param_7);
  if (iVar6 != 0) {
    uVar7 = (int)((iVar6 - param_2[0x32]) + ((uint)(iVar6 - param_2[0x32] >> 3) >> 0x1d)) >> 3;
    if (((int)uVar7 < 0) || (param_2[0x35] <= (int)uVar7)) {
      uVar8 = 0;
      uVar7 = 0;
    }
    else {
      uVar8 = (uint)*(byte *)(param_2[0x37] + uVar7) | (uVar7 & 0xff) << 8;
    }
    piVar1 = param_2 + 0x739;
    if (uVar8 != 0) {
      piVar1 = param_2 + (uVar7 & 0xff) * 7 + 0x39;
    }
    func_0x8108d650(piVar1,0,0x1c);
    piVar1[1] = iStack_38;
    piVar1[2] = iStack_34;
    piVar1[3] = param_4;
    *piVar1 = iStack_3c;
    iVar3 = func_0x81118330(param_5);
    iVar4 = func_0x81005aaa(iVar3 + 1);
    piVar1[4] = iVar4;
    func_0x8109d75c(iVar4,iVar3 + 1,param_5);
    uVar7 = (int)((iVar6 - param_2[0x32]) + ((uint)(iVar6 - param_2[0x32] >> 3) >> 0x1d)) >> 3;
    if (((int)uVar7 < 0) || (param_2[0x35] <= (int)uVar7)) {
      uVar5 = 0;
    }
    else {
      uVar5 = (ushort)*(byte *)(param_2[0x37] + uVar7) | (ushort)((uVar7 & 0xff) << 8);
    }
    func_0x8108cc5c(param_2 + 0xd);
  }
  *puStack_30 = uVar5;
  (**(code **)(param_2[0xb] + 0xc))(param_2 + 0xb);
  func_0x81005af0(uStack_40);
LAB_810778fa:
  if (_UNK_8111a5b0 == iStack_2c) {
    return;
  }
  func_0x811185a0();
  func_0x8107766c();
  return;
}

