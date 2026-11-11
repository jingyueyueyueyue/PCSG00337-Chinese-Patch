
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810fd20c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint in_fpscr;
  float fVar6;
  float fVar7;
  undefined auStack_b8 [4];
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  float fStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  float fStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  float fStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  float fStack_78;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_34;
  int iStack_2c;
  
  iStack_2c = _UNK_8111a5b0;
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 == 0) {
    iVar5 = 1;
  }
  fVar6 = (float)VectorUnsignedToFloat(*(undefined4 *)(param_1 + 8),(byte)(in_fpscr >> 0x15) & 3);
  fVar7 = (float)VectorUnsignedToFloat(iVar5,(byte)(in_fpscr >> 0x15) & 3);
  fVar6 = (1.0 - fVar6 / fVar7) * 2.0;
  fVar7 = fVar6 + -1.0;
  if (fVar6 < 1.0 == NAN(fVar6)) {
    fVar6 = 1.0;
  }
  if (fVar7 <= 0.0) {
    fVar7 = 0.0;
  }
  uVar1 = func_0x81082928(param_2);
  func_0x8108631c(auStack_b8);
  func_0x81076840(auStack_b8);
  FUN_81064908(param_1,param_2);
  iVar5 = func_0x81087722(param_5);
  iVar2 = func_0x81087736(param_5);
  if ((iStack_4c != iVar5) || (iStack_48 != iVar2)) {
    uStack_34 = uStack_34 | 0x80000000;
  }
  iStack_4c = iVar5;
  iStack_48 = iVar2;
  uVar3 = func_0x81087722(param_5);
  uStack_50 = func_0x81087736(param_5);
  uStack_54 = uVar3;
  func_0x81075bca(uVar1,param_5);
  uStack_b4 = 0x3f800000;
  uStack_b0 = 0x3f800000;
  uStack_ac = 0x3f800000;
  uStack_a4 = 0x3f800000;
  uStack_a0 = 0x3f800000;
  uStack_9c = 0x3f800000;
  uStack_94 = 0x3f800000;
  uStack_34 = uStack_34 & 0xbffffffd | 0x20000000;
  uStack_90 = 0x3f800000;
  uStack_8c = 0x3f800000;
  uStack_84 = 0x3f800000;
  uStack_80 = 0x3f800000;
  uStack_7c = 0x3f800000;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  fStack_a8 = fVar6;
  fStack_98 = fVar7;
  fStack_88 = fVar6;
  fStack_78 = fVar7;
  func_0x810868f4(auStack_b8,uVar1);
  func_0x810863d0(auStack_b8);
  if (_UNK_8111a5b0 != iStack_2c) {
    puVar4 = (undefined4 *)func_0x811185a0();
    *puVar4 = &UNK_81144790;
    func_0x81064852(puVar4);
    func_0x81005af0(puVar4);
    return;
  }
  return;
}

