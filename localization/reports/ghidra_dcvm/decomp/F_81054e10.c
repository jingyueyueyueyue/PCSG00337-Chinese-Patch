
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81054e10(int param_1,undefined4 *param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  int **ppiVar9;
  uint in_fpscr;
  float fVar10;
  uint uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined8 uVar15;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  int iStack_4c;
  undefined4 uStack_3c;
  undefined4 *puStack_38;
  undefined4 uStack_34;
  undefined *puStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  *(undefined4 *)(param_1 + 0x18c) = 0x3f800000;
  *(undefined4 *)(param_1 + 400) = 4000;
  fVar10 = (float)VectorUnsignedToFloat
                            ((uint)*(byte *)(*(int *)(param_1 + 0xa4) + 0x16),
                             (byte)(in_fpscr >> 0x15) & 3);
  uVar11 = VectorFloatToUnsigned((fVar10 / 100.0) * 1.0 * 16383.0,3);
  uVar7 = uVar11;
  if (0x3fff < uVar11) {
    uVar7 = 0x3fff;
  }
  uStack_1c = (undefined2)uVar7;
  if (0x3fff < uVar11) {
    uVar11 = 0x3fff;
  }
  uStack_1a = (undefined2)uVar11;
  iVar2 = (**(code **)(***(int ***)(param_1 + 0x178) + 8))();
  func_0x8107f3c8(*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8)
                  ,&uStack_1c);
  func_0x81042cb8(*(undefined4 *)(param_1 + 0x160));
  func_0x81059516(param_1 + 0xb4);
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  func_0x8107cc9c(param_1 + 0x90);
  func_0x8105a3cc(param_1 + 4);
  *(undefined *)(param_1 + 0x65) = 1;
  uVar6 = 0x1000;
  if (*(int *)(*(int *)(param_1 + 0xac) + 0x48) == 0) {
    uVar6 = 0;
  }
  *(undefined4 *)(param_1 + 0x60) = uVar6;
  puVar3 = (undefined4 *)func_0x8109ca34(*(undefined4 *)(param_1 + 0xa0));
  func_0x8109c214(*puVar3,*param_2,0);
  uVar8 = *(undefined4 *)(param_1 + 0xa0);
  uVar6 = func_0x8109ceba(uVar8,uRam81182c2c);
  uStack_28 = 0;
  FUN_8109cace(uVar8,uVar6,*param_2,0);
  *param_2 = 0;
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar6 = 0x81054f2b;
  uVar15 = func_0x811185a0();
  iVar5 = (int)((ulonglong)uVar15 >> 0x20);
  iVar2 = (int)uVar15;
  puStack_30 = &UNK_8111a5b0;
  uStack_34 = 0;
  iStack_4c = _UNK_8111a5b0;
  fVar14 = *(float *)(iVar2 + 0x18c);
  fVar13 = (float)VectorUnsignedToFloat(iVar5,(byte)(in_fpscr >> 0x15) & 3);
  fVar10 = (float)VectorUnsignedToFloat
                            ((uint)*(byte *)(*(int *)(iVar2 + 0xa4) + 0x1a),
                             (byte)(in_fpscr >> 0x15) & 3);
  fVar10 = fVar10 / 100.0;
  fVar13 = (fVar13 / 1000.0) * 5.0 * (1.0 - fVar10);
  uStack_3c = uVar8;
  puStack_38 = param_2;
  uStack_2c = uVar6;
  iVar4 = (**(code **)(**(int **)(*(int *)(iVar2 + 0x178) + 4) + 0x18))();
  if ((iVar4 == 0) &&
     (iVar4 = (**(code **)(**(int **)(*(int *)(iVar2 + 0x178) + 0xc) + 0x18))(), iVar4 == 0)) {
    fVar12 = *(float *)(iVar2 + 0x18c);
    uVar7 = *(int *)(iVar2 + 400) + iVar5;
    *(uint *)(iVar2 + 400) = uVar7;
    if (uVar7 < 0xfa1) {
      if (uVar7 < 4000) goto LAB_81055054;
    }
    else {
      *(undefined4 *)(iVar2 + 400) = 4000;
    }
    fVar12 = fVar12 + fVar13;
    *(float *)(iVar2 + 0x18c) = fVar12;
    uVar7 = in_fpscr & 0xfffffff | (uint)(fVar12 < 1.0) << 0x1f;
    in_fpscr = uVar7 | (uint)NAN(fVar12) << 0x1c;
    if ((byte)(uVar7 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
      fVar12 = 1.0;
      *(undefined4 *)(iVar2 + 0x18c) = 0x3f800000;
    }
  }
  else {
    fVar12 = *(float *)(iVar2 + 0x18c);
    *(undefined4 *)(iVar2 + 400) = 0;
    if (fVar10 < fVar12) {
      fVar12 = fVar12 - fVar13;
      uVar7 = in_fpscr & 0xfffffff | (uint)(fVar10 < fVar12) << 0x1f;
      in_fpscr = uVar7 | (uint)(NAN(fVar10) || NAN(fVar12)) << 0x1c;
      *(float *)(iVar2 + 0x18c) = fVar12;
      if ((byte)(uVar7 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
        *(float *)(iVar2 + 0x18c) = fVar10;
        fVar12 = fVar10;
      }
    }
    else {
      fVar12 = fVar12 + fVar13;
      in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar10 == fVar12) << 0x1e |
                 (uint)(fVar12 <= fVar10) << 0x1d;
      *(float *)(iVar2 + 0x18c) = fVar12;
      bVar1 = (byte)(in_fpscr >> 0x18);
      if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) {
        *(float *)(iVar2 + 0x18c) = fVar10;
        fVar12 = fVar10;
      }
    }
  }
LAB_81055054:
  if ((int)(fVar12 * 1000.0) != (int)(fVar14 * 1000.0)) {
    fVar10 = (float)VectorUnsignedToFloat
                              ((uint)*(byte *)(*(int *)(iVar2 + 0xa4) + 0x16),
                               (byte)(in_fpscr >> 0x15) & 3);
    uVar11 = VectorFloatToUnsigned((fVar10 / 100.0) * fVar12 * 16383.0,3);
    uVar7 = uVar11;
    if (0x3fff < uVar11) {
      uVar7 = 0x3fff;
    }
    uStack_50 = (undefined2)uVar7;
    if (0x3fff < uVar11) {
      uVar11 = 0x3fff;
    }
    uStack_4e = (undefined2)uVar11;
    iVar2 = (**(code **)(***(int ***)(iVar2 + 0x178) + 8))();
    func_0x8107f3c8(*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar2 + 0xc),
                    *(undefined4 *)(iVar2 + 8),&uStack_50);
  }
  if (_UNK_8111a5b0 != iStack_4c) {
    iVar2 = func_0x811185a0();
    ppiVar9 = *(int ***)(iVar2 + 0x178);
    (**(code **)(*ppiVar9[1] + 0x14))();
    (**(code **)(**ppiVar9 + 0x14))();
    return;
  }
  return;
}

