
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_811014f4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint in_fpscr;
  uint uVar8;
  float fVar9;
  float fVar10;
  undefined auStack_c8 [8];
  undefined auStack_c0 [8];
  undefined auStack_b8 [4];
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  uint uStack_74;
  uint uStack_70;
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
  iVar7 = *(int *)(param_1 + 4);
  if (iVar7 == 0) {
    iVar7 = 1;
  }
  iVar1 = func_0x81082928(param_2);
  fVar10 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x15) & 3);
  fVar9 = (float)VectorUnsignedToFloat(*(undefined4 *)(param_1 + 8),(byte)(in_fpscr >> 0x15) & 3);
  fVar9 = fVar9 / fVar10;
  uVar2 = in_fpscr & 0xfffffff | (uint)(fVar9 < 0.8) << 0x1f;
  uVar8 = uVar2 | (uint)NAN(fVar9) << 0x1c;
  if ((byte)(uVar2 >> 0x1f) == ((byte)(uVar8 >> 0x1c) & 1)) {
    if (*(char *)(param_1 + 0x10) == '\0') {
      *(undefined *)(param_1 + 0x10) = 1;
      func_0x81082bb6(param_2);
      uVar5 = func_0x81082c5e(param_2);
      func_0x81076ae4(uVar5,iVar1,param_5,0,0,0,0,0,0);
      func_0x810829d8(param_2,0,0);
    }
    uVar5 = 0x81190e7c;
    if (0xf < uRam81190e90) {
      uVar5 = uRam81190e7c;
    }
    func_0x811007fc((fVar9 - 0.8) / 0.2,0x3f800000,auStack_c8,uVar5,0x81190e54,0x81190e4c);
  }
  else {
    uVar5 = 0x81190e7c;
    if (0xf < uRam81190e90) {
      uVar5 = uRam81190e7c;
    }
    func_0x811007fc(fVar9 / 0.8,0x3f800000,auStack_c0,uVar5,0x81190e4c,0x81190e54);
  }
  func_0x8108631c(auStack_b8);
  func_0x81076840(auStack_b8);
  FUN_81064908(param_1,param_2);
  if (*(char *)(iVar1 + 0x20) != '\0') {
    func_0x810846aa(iVar1);
    *(undefined *)(iVar1 + 0x20) = 0;
  }
  func_0x81084610(iVar1,1,1);
  uVar2 = func_0x81087722(param_5);
  uVar3 = func_0x81087736(param_5);
  iVar7 = func_0x81087722(param_5);
  iVar4 = func_0x81087736(param_5);
  if ((iStack_4c != iVar7) || (iStack_48 != iVar4)) {
    uStack_34 = uStack_34 | 0x80000000;
  }
  iStack_4c = iVar7;
  iStack_48 = iVar4;
  uVar5 = func_0x81087722(param_5);
  uStack_50 = func_0x81087736(param_5);
  uStack_34 = uStack_34 | 0x80000060;
  uStack_74 = uVar2 >> 1;
  uStack_70 = uVar3 >> 1;
  uStack_54 = uVar5;
  func_0x81075bca(iVar1,param_5);
  uStack_b4 = 0x3f800000;
  uStack_44 = VectorSignedToFloat(uVar2 >> 1,(byte)(uVar8 >> 0x15) & 3);
  uStack_40 = VectorSignedToFloat(uVar3 >> 1,(byte)(uVar8 >> 0x15) & 3);
  uStack_b0 = 0x3f800000;
  uStack_ac = 0x3f800000;
  uStack_a8 = 0x3f800000;
  uStack_34 = uStack_34 & 0xdfffffff | 0x40000002;
  uStack_3c = 0;
  func_0x810868f4(auStack_b8,iVar1);
  func_0x810863d0(auStack_b8);
  if (_UNK_8111a5b0 == iStack_2c) {
    return;
  }
  puVar6 = (undefined4 *)func_0x811185a0();
  *puVar6 = &UNK_81144964;
  func_0x81064852(puVar6);
  func_0x81005af0(puVar6);
  return;
}

