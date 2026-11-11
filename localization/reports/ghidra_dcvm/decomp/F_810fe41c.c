
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810fe41c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint in_fpscr;
  float fVar6;
  undefined auStack_b0 [4];
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_2c;
  int iStack_24;
  
  iStack_24 = _UNK_8111a5b0;
  uVar1 = func_0x81082928(param_2,0xb0);
  func_0x8108631c(auStack_b0);
  func_0x81076840(auStack_b0);
  FUN_81064908(param_1,param_2);
  iVar2 = func_0x81087722(param_5);
  iVar3 = func_0x81087736(param_5);
  if ((iStack_44 != iVar2) || (iStack_40 != iVar3)) {
    uStack_2c = uStack_2c | 0x80000000;
  }
  iStack_44 = iVar2;
  iStack_40 = iVar3;
  uVar4 = func_0x81087722(param_5);
  uStack_48 = func_0x81087736(param_5);
  uStack_4c = uVar4;
  func_0x81075bca(uVar1,param_5);
  uStack_ac = 0x3f800000;
  uStack_a8 = 0x3f800000;
  uStack_a4 = 0x3f800000;
  uStack_a0 = 0x3f800000;
  uStack_2c = uStack_2c & 0xdfffffff | 0x40000002;
  uVar4 = func_0x81082c42();
  fVar6 = (float)VectorUnsignedToFloat(uVar4,(byte)(in_fpscr >> 0x15) & 3);
  uStack_3c = 0;
  uStack_34 = 0;
  uStack_38 = VectorSignedToFloat((int)-(fVar6 * *(float *)(param_1 + 0x10)),
                                  (byte)(in_fpscr >> 0x15) & 3);
  func_0x810868f4(auStack_b0,uVar1);
  func_0x810863d0(auStack_b0);
  if (_UNK_8111a5b0 == iStack_24) {
    return;
  }
  puVar5 = (undefined4 *)func_0x811185a0();
  *puVar5 = &UNK_811448f4;
  func_0x81064852(puVar5);
  func_0x81005af0(puVar5);
  return;
}

