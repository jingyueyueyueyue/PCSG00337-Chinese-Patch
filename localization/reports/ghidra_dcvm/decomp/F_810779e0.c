
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810779e0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined auStack_38 [8];
  int iStack_30;
  undefined auStack_2c [8];
  int iStack_24;
  int iStack_20;
  
  iStack_20 = _UNK_8111a5b0;
  piVar1 = (int *)(**(code **)(*param_1 + 0x20))(param_1);
  iVar6 = *piVar1;
  iStack_30 = 0;
  func_0x81080bb2(auStack_38,param_2);
  if ((iVar6 == 0) ||
     (iVar6 = FUN_81078eaa(iVar6,&uStack_40,&uStack_3c,auStack_38,param_3), iVar6 == 0)) {
    piVar7 = param_1 + 0xb;
    (**(code **)(param_1[0xb] + 8))(piVar7);
    for (piVar1 = *(int **)param_1[4]; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      uVar3 = (int)(((int)piVar1 - param_1[0x32]) +
                   ((uint)((int)piVar1 - param_1[0x32] >> 3) >> 0x1d)) >> 3;
      if (((int)uVar3 < 0) || (param_1[0x35] <= (int)uVar3)) {
        uVar4 = 0;
        uVar3 = 0;
      }
      else {
        uVar4 = (uint)*(byte *)(param_1[0x37] + uVar3) | (uVar3 & 0xff) << 8;
      }
      piVar5 = param_1 + 0x739;
      if (uVar4 != 0) {
        piVar5 = param_1 + (uVar3 & 0xff) * 7 + 0x39;
      }
      if (*(char *)(piVar5 + 6) == '\0') {
        iStack_24 = 0;
        func_0x81080bb2(auStack_2c,piVar5[4]);
        if (((iStack_24 != 0) && (iStack_30 != 0)) && (iVar6 = func_0x811181a0(), iVar6 == 0)) {
          func_0x81005af0(iStack_24);
          iStack_24 = 0;
          (**(code **)(param_1[0xb] + 0xc))(piVar7);
          func_0x81005af0(iStack_30);
          uVar2 = 1;
          goto LAB_81077af2;
        }
        func_0x81005af0(iStack_24);
        iStack_24 = 0;
      }
    }
    (**(code **)(param_1[0xb] + 0xc))(piVar7);
    func_0x81005af0(iStack_30);
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x810783d6(uStack_40,uStack_3c);
    uVar2 = func_0x81077938(param_1,uStack_40,uVar2);
    func_0x81005af0(iStack_30);
  }
LAB_81077af2:
  if (_UNK_8111a5b0 != iStack_20) {
    func_0x811185a0(uVar2);
    func_0x81077938();
    return;
  }
  return;
}

