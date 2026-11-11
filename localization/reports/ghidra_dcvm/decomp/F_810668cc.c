
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_810668cc(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  short asStack_50 [2];
  undefined auStack_4c [4];
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  undefined auStack_38 [8];
  undefined4 uStack_30;
  int iStack_2c;
  int iStack_28;
  
  iVar3 = iRam811ae688;
  iStack_28 = _UNK_8111a5b0;
  iVar6 = 0;
  if (iRam811ae688 != 0) {
    iVar6 = iRam811ae688 + 4;
  }
  iVar5 = iVar6 + 4;
  (**(code **)(*(int *)(iVar6 + 4) + 8))(iVar5);
  iVar4 = 0;
  if (iVar3 != 0) {
    iVar4 = iVar3 + 4;
  }
  iVar4 = *(int *)(iVar4 + 0x10);
  iStack_2c = iVar5;
  if (iVar4 == 0) {
    (**(code **)(*(int *)(iVar6 + 4) + 0xc))();
    uVar1 = 0;
  }
  else {
    uStack_30 = 0;
    param_1[4] = 1;
    param_1[5] = 0;
    *(undefined *)((int)param_1 + 0x3e) = 0;
    iVar2 = func_0x8107b846(iVar3 + 100,param_2,auStack_4c);
    iVar5 = iStack_2c;
    if (iVar2 == 0) {
      uVar1 = **(undefined4 **)(iVar4 + 0x1c);
      if (iRam81191264 == param_1[0xc]) {
        iStack_48 = 0;
        uStack_44 = 0;
        iVar3 = FUN_810a15b8(uVar1,&iStack_48,&uStack_44,param_2,param_1 + 0xc);
        if (iVar3 != 0) {
          param_1[0xc] = *(undefined4 *)(iStack_48 + 0x28);
        }
      }
      FUN_810a2d78(asStack_50,uVar1,param_1 + 4,param_1 + 0xe,*param_1,param_2,param_1 + 0xc,0);
      *(short *)(param_1 + 3) = asStack_50[0];
      if (asStack_50[0] == 0) {
        (**(code **)(*(int *)(iVar6 + 4) + 0xc))(iVar5);
        uVar1 = 0;
      }
      else {
        *(undefined *)(param_1 + 0xf) = 1;
        param_1[6] = 2;
        (**(code **)(*(int *)(iVar6 + 4) + 0xc))(iVar5);
        uVar1 = 1;
      }
    }
    else {
      uStack_40 = *param_1;
      do {
        func_0x8107bd82(auStack_38,iVar3 + 100,param_2,uStack_40,param_1 + 7);
        iVar4 = func_0x8107db88(auStack_38);
        if (iVar4 == 0) {
          func_0x8108cfd4(100);
        }
        func_0x8107db94(auStack_38);
        uStack_40 = *param_1;
      } while (iVar4 == 0);
      iStack_3c = iVar4;
      if (param_1 + 1 != &uStack_40) {
        func_0x8107db94(param_1 + 1);
        param_1[1] = uStack_40;
        param_1[2] = iStack_3c;
        uStack_40 = 0;
        iStack_3c = 0;
      }
      func_0x8107db94(&uStack_40);
      param_1[4] = uStack_30;
      *(undefined *)((int)param_1 + 0x3e) = 1;
      param_1[5] = uStack_30;
      (**(code **)(*(int *)(iVar6 + 4) + 0xc))(iStack_2c);
      uVar1 = 1;
    }
  }
  if (_UNK_8111a5b0 == iStack_28) {
    return uVar1;
  }
  uVar7 = func_0x811185a0(uVar1);
  uVar1 = (undefined4)((ulonglong)uVar7 >> 0x20);
  iVar3 = (int)uVar7;
  func_0x81080bb2(iVar3 + 0x24);
  iVar6 = FUN_810668cc(iVar3,uVar1);
  if (iVar6 == 0) {
    uVar1 = FUN_81066642(iVar3,uVar1);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

