
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8107405c(undefined4 *param_1)

{
  uint uVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  undefined4 uVar14;
  uint in_fpscr;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined8 uVar20;
  undefined4 uVar21;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  float fStack_1a8;
  float fStack_1a4;
  int iStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  float fStack_168;
  float fStack_164;
  float fStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  undefined4 uStack_11c;
  float fStack_118;
  float fStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  float fStack_108;
  float fStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  float fStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  float fStack_b8;
  undefined4 uStack_b4;
  float fStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  float fStack_84;
  float fStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  float fStack_74;
  float fStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  undefined4 *puStack_3c;
  undefined *puStack_38;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  
  iStack_10 = _UNK_8111a5b0;
  *param_1 = 0;
  param_1[1] = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 != &uStack_18) {
    FUN_8107db94(param_1);
    *param_1 = uStack_18;
    param_1[1] = uStack_14;
  }
  uStack_14 = 0;
  uStack_18 = 0;
  FUN_8107db94(&uStack_18);
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (_UNK_8111a5b0 == iStack_10) {
    return;
  }
  iVar8 = iStack_10;
  uVar20 = func_0x811185a0(param_1);
  piVar3 = (int *)uVar20;
  puStack_38 = &UNK_8111a5b0;
  iStack_58 = _UNK_8111a5b0;
  piVar12 = piVar3 + 1;
  piVar3[0x39] = (int)((ulonglong)uVar20 >> 0x20);
  puStack_3c = param_1;
  if ((piVar3[0x3a] != iVar8) && (puVar6 = (undefined4 *)piVar3[0x3c], puVar6 != (undefined4 *)0x0))
  {
    uStack_1f8 = 0;
    uStack_1f4 = 0;
    if (puVar6 != &uStack_1f8) {
      FUN_8107db94(puVar6);
      puVar6[1] = uStack_1f4;
      *puVar6 = uStack_1f8;
    }
    uStack_1f4 = 0;
    uStack_1f8 = 0;
    FUN_8107db94(&uStack_1f8);
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = 0;
    puVar6[5] = 0;
  }
  piVar3[0x3a] = iVar8;
  iVar8 = piVar3[0x37];
  (**(code **)(*piVar3 + 0xc))(piVar3);
  if ((piVar3[0x22] & 2U) != 0) {
    piVar3[0x12] = 0;
    piVar3[0x11] = 0x3f800000;
    piVar3[0x22] = piVar3[0x22] | 1;
    piVar3[0x13] = 0;
    piVar3[0x14] = 0;
    piVar3[0x15] = 0;
    piVar3[0x16] = 0x3f800000;
    piVar3[0x17] = 0;
    piVar3[0x18] = 0;
    piVar13 = piVar3 + 0x11;
    piVar3[0x19] = 0;
    uVar11 = 0;
    piVar3[0x1a] = 0;
    piVar3[0x1b] = 0x3f800000;
    piVar3[0x1c] = 0;
    piVar3[0x1d] = 0;
    piVar3[0x1e] = 0;
    uVar10 = piVar3[0x21];
    piVar3[0x1f] = 0;
    piVar3[0x20] = 0x3f800000;
    do {
      uVar4 = uVar10 & 3;
      if (uVar4 < 2) {
        if (uVar4 == 0) {
          if ((piVar3[0x21] & 0x20000000U) != 0) {
            fVar17 = (float)piVar3[0x2b];
            fVar15 = (float)func_0x81118490(fVar17,0,0);
            fVar16 = SQRT(1.0 - fVar15 * fVar15);
            uVar4 = in_fpscr & 0xfffffff | 0x40000000;
            if ((byte)(uVar4 >> 0x1e) == 0) {
              fVar16 = (float)func_0x811184a0();
            }
            uVar1 = uVar4 & 0xfffffff | (uint)(fVar17 < -1.570796) << 0x1f;
            in_fpscr = uVar1 | (uint)NAN(fVar17) << 0x1c;
            if (((byte)(uVar1 >> 0x1f) != ((byte)(in_fpscr >> 0x1c) & 1)) ||
               (in_fpscr = uVar4 & 0xfffffff | (uint)(fVar17 == 1.570796) << 0x1e |
                           (uint)(1.570796 <= fVar17) << 0x1d, bVar2 = (byte)(in_fpscr >> 0x18),
               (bool)(bVar2 >> 5 & 1) && !(bool)(bVar2 >> 6))) {
              fVar16 = -fVar16;
            }
            fStack_74 = -fVar15;
            uStack_98 = 0x3f800000;
            uStack_94 = 0;
            uStack_90 = 0;
            uStack_8c = 0;
            uStack_88 = 0;
            uStack_7c = 0;
            uStack_78 = 0;
            uStack_6c = 0;
            uStack_68 = 0;
            uStack_64 = 0;
            uStack_60 = 0;
            uStack_5c = 0x3f800000;
            fStack_84 = fVar16;
            fStack_80 = fVar15;
            fStack_70 = fVar16;
            func_0x810cfcc4(piVar13,piVar13,&uStack_98);
          }
        }
        else if ((piVar3[0x21] & 0x10000000U) != 0) {
          fVar17 = (float)piVar3[0x2c];
          fVar15 = (float)func_0x81118490(fVar17,0,0);
          fVar16 = SQRT(1.0 - fVar15 * fVar15);
          uVar4 = in_fpscr & 0xfffffff | 0x40000000;
          if ((byte)(uVar4 >> 0x1e) == 0) {
            fVar16 = (float)func_0x811184a0();
          }
          uVar1 = uVar4 & 0xfffffff | (uint)(fVar17 < -1.570796) << 0x1f;
          in_fpscr = uVar1 | (uint)NAN(fVar17) << 0x1c;
          if (((byte)(uVar1 >> 0x1f) != ((byte)(in_fpscr >> 0x1c) & 1)) ||
             (in_fpscr = uVar4 & 0xfffffff | (uint)(fVar17 == 1.570796) << 0x1e |
                         (uint)(1.570796 <= fVar17) << 0x1d, bVar2 = (byte)(in_fpscr >> 0x18),
             (bool)(bVar2 >> 5 & 1) && !(bool)(bVar2 >> 6))) {
            fVar16 = -fVar16;
          }
          fStack_d0 = -fVar15;
          uStack_d4 = 0;
          uStack_cc = 0;
          uStack_c8 = 0;
          uStack_c4 = 0x3f800000;
          uStack_c0 = 0;
          uStack_bc = 0;
          uStack_b4 = 0;
          uStack_ac = 0;
          uStack_a8 = 0;
          uStack_a4 = 0;
          uStack_a0 = 0;
          uStack_9c = 0x3f800000;
          fStack_d8 = fVar16;
          fStack_b8 = fVar15;
          fStack_b0 = fVar16;
          func_0x810cfcc4(piVar13,piVar13,&fStack_d8);
        }
      }
      else if ((uVar4 < 3) && ((piVar3[0x21] & 0x8000000U) != 0)) {
        fVar17 = (float)piVar3[0x2d];
        fVar15 = (float)func_0x81118490(fVar17,0,0);
        fVar16 = SQRT(1.0 - fVar15 * fVar15);
        uVar4 = in_fpscr & 0xfffffff | 0x40000000;
        if ((byte)(uVar4 >> 0x1e) == 0) {
          fVar16 = (float)func_0x811184a0();
        }
        uVar1 = uVar4 & 0xfffffff | (uint)(fVar17 < -1.570796) << 0x1f;
        in_fpscr = uVar1 | (uint)NAN(fVar17) << 0x1c;
        if (((byte)(uVar1 >> 0x1f) != ((byte)(in_fpscr >> 0x1c) & 1)) ||
           (in_fpscr = uVar4 & 0xfffffff | (uint)(fVar17 == 1.570796) << 0x1e |
                       (uint)(1.570796 <= fVar17) << 0x1d, bVar2 = (byte)(in_fpscr >> 0x18),
           (bool)(bVar2 >> 5 & 1) && !(bool)(bVar2 >> 6))) {
          fVar16 = -fVar16;
        }
        fStack_108 = -fVar15;
        uStack_110 = 0;
        uStack_10c = 0;
        uStack_100 = 0;
        uStack_fc = 0;
        uStack_f8 = 0;
        uStack_f4 = 0;
        uStack_f0 = 0x3f800000;
        uStack_ec = 0;
        uStack_e8 = 0;
        uStack_e4 = 0;
        uStack_e0 = 0;
        uStack_dc = 0x3f800000;
        fStack_118 = fVar16;
        fStack_114 = fVar15;
        fStack_104 = fVar16;
        func_0x810cfcc4(piVar13,piVar13,&fStack_118);
      }
      uVar11 = uVar11 + 1;
      uVar10 = uVar10 >> 2;
    } while (uVar11 < 3);
  }
  if ((piVar3[0x22] & 1U) != 0) {
    fVar15 = (float)piVar3[0x29];
    fVar16 = (float)piVar3[0x2a];
    piVar3[4] = 0;
    piVar3[7] = 0;
    fVar17 = (float)VectorSignedToFloat(piVar3[0x34],(byte)(in_fpscr >> 0x15) & 3);
    piVar3[8] = 0;
    fVar18 = (float)VectorSignedToFloat(piVar3[0x35],(byte)(in_fpscr >> 0x15) & 3);
    piVar3[0xb] = 0x3f800000;
    piVar3[0xf] = piVar3[0x25];
    piVar3[1] = (int)(fVar15 * 1.0);
    piVar3[0xc] = 0;
    piVar3[2] = (int)(fVar16 * 0.0);
    fVar19 = (float)VectorSignedToFloat(piVar3[0x36],(byte)(in_fpscr >> 0x15) & 3);
    piVar3[0x10] = 0x3f800000;
    piVar3[5] = (int)(fVar15 * 0.0);
    piVar3[6] = (int)(fVar16 * 1.0);
    piVar3[3] = 0;
    piVar3[9] = (int)(fVar15 * 0.0);
    piVar3[10] = (int)(fVar16 * 0.0);
    piVar3[0xd] = (int)((float)piVar3[0x23] * fVar15);
    fStack_128 = -(fVar17 * fVar15);
    piVar3[0xe] = (int)((float)piVar3[0x24] * fVar16);
    fStack_124 = -(fVar18 * fVar16);
    fStack_120 = -fVar19;
    uStack_158 = 0x3f800000;
    uStack_154 = 0;
    uStack_150 = 0;
    uStack_14c = 0;
    uStack_148 = 0;
    uStack_144 = 0x3f800000;
    uStack_140 = 0;
    uStack_13c = 0;
    uStack_138 = 0;
    uStack_134 = 0;
    uStack_130 = 0x3f800000;
    uStack_12c = 0;
    uStack_11c = 0x3f800000;
    func_0x810cfcc4(piVar12,piVar12,&uStack_158);
    func_0x810cfcc4(piVar12,piVar12,piVar3 + 0x11);
    fStack_168 = fVar17 * fVar15;
    fStack_164 = fVar18 * fVar16;
    uStack_198 = 0x3f800000;
    uStack_194 = 0;
    uStack_190 = 0;
    uStack_18c = 0;
    uStack_188 = 0;
    uStack_184 = 0x3f800000;
    uStack_180 = 0;
    uStack_17c = 0;
    uStack_178 = 0;
    uStack_174 = 0;
    uStack_170 = 0x3f800000;
    uStack_16c = 0;
    uStack_15c = 0x3f800000;
    fStack_160 = fVar19;
    func_0x810cfcc4(piVar12,piVar12,&uStack_198);
    fVar15 = (float)VectorSignedToFloat(piVar3[0x32],(byte)(in_fpscr >> 0x15) & 3);
    fVar16 = (float)VectorSignedToFloat(piVar3[0x33],(byte)(in_fpscr >> 0x15) & 3);
    iStack_1a0 = piVar3[0x28];
    uStack_1d8 = 0x3f800000;
    uStack_1d4 = 0;
    uStack_1d0 = 0;
    fStack_1a8 = (float)piVar3[0x26] - fVar15 * (float)piVar3[0x29];
    uStack_1cc = 0;
    uStack_1c8 = 0;
    fStack_1a4 = (float)piVar3[0x27] - fVar16 * (float)piVar3[0x2a];
    uStack_1c4 = 0x3f800000;
    uStack_1c0 = 0;
    uStack_1bc = 0;
    uStack_1b8 = 0;
    uStack_1b4 = 0;
    uStack_1b0 = 0x3f800000;
    uStack_1ac = 0;
    uStack_19c = 0x3f800000;
    func_0x810cfcc4(piVar12,piVar12,&uStack_1d8);
  }
  func_0x810852f8(iVar8,piVar12);
  uStack_1f0 = 0;
  uStack_1ec = 0;
  uStack_200 = 0;
  uStack_1fc = 0;
  if (&uStack_1f0 != &uStack_200) {
    FUN_8107db94(&uStack_1f0);
    uStack_1f0 = uStack_200;
    uStack_1ec = uStack_1fc;
  }
  uStack_1fc = 0;
  uStack_200 = 0;
  FUN_8107db94(&uStack_200);
  uStack_1e8 = 0;
  uStack_1e4 = 0;
  uStack_1e0 = 0;
  uStack_1dc = 0;
  iVar5 = *piVar3;
  puVar6 = &uStack_1f0;
  if ((undefined4 *)piVar3[0x3c] != (undefined4 *)0x0) {
    puVar6 = (undefined4 *)piVar3[0x3c];
  }
  if (puVar6[1] == 0) {
    (**(code **)(iVar5 + 0x10))(piVar3,puVar6);
    iVar5 = *piVar3;
  }
  (**(code **)(iVar5 + 0x14))(piVar3,puVar6);
  func_0x810767e0(iVar8);
  FUN_81075858(piVar3[0x38]);
  piVar3[0x22] = 0;
  FUN_8107db94(&uStack_1f0);
  if (_UNK_8111a5b0 != iStack_58) {
    uVar14 = 0x810745d9;
    iVar5 = func_0x811185a0();
    uVar21 = 0;
    uVar7 = *(undefined4 *)(iVar5 + 0xdc);
    uVar9 = *(undefined4 *)(iVar5 + 0xec);
    func_0x810767e0(uVar7);
    FUN_810767e2(uVar7,4,3,uVar9,puVar6,uVar21,iVar8,uVar14);
    iVar8 = *(int *)(iVar5 + 0xe0);
    if (*(char *)(iVar8 + 0x20) != '\0') {
      func_0x810846aa(iVar8);
      *(undefined *)(iVar8 + 0x20) = 0;
    }
    func_0x8108461e(iVar8,0,0);
    return;
  }
  return;
}

