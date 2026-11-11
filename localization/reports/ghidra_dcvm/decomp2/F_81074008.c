
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81074008(undefined4 *param_1)

{
  uint uVar1;
  byte bVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int *piVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint in_fpscr;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined8 uVar20;
  undefined4 uVar21;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
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
  float fStack_1c0;
  float fStack_1bc;
  int iStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  float fStack_180;
  float fStack_17c;
  float fStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  undefined4 uStack_134;
  float fStack_130;
  float fStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  float fStack_120;
  float fStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  float fStack_f0;
  undefined4 uStack_ec;
  float fStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  float fStack_d0;
  undefined4 uStack_cc;
  float fStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  float fStack_9c;
  float fStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  float fStack_8c;
  float fStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  int iStack_70;
  undefined4 *puStack_54;
  undefined *puStack_50;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 *puStack_24;
  undefined *puStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  
  iStack_10 = _UNK_8111a5b0;
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
  uVar13 = 0x8107405b;
  puVar3 = (undefined4 *)func_0x811185a0();
  puStack_20 = &UNK_8111a5b0;
  iStack_28 = _UNK_8111a5b0;
  *puVar3 = 0;
  puVar3[1] = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  puStack_24 = param_1;
  uStack_1c = uVar13;
  if (puVar3 != &uStack_30) {
    FUN_8107db94(puVar3);
    *puVar3 = uStack_30;
    puVar3[1] = uStack_2c;
  }
  uStack_2c = 0;
  uStack_30 = 0;
  FUN_8107db94(&uStack_30);
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  if (_UNK_8111a5b0 != iStack_28) {
    iVar7 = iStack_28;
    uVar20 = func_0x811185a0(puVar3);
    piVar4 = (int *)uVar20;
    puStack_50 = &UNK_8111a5b0;
    iStack_70 = _UNK_8111a5b0;
    piVar11 = piVar4 + 1;
    piVar4[0x39] = (int)((ulonglong)uVar20 >> 0x20);
    puStack_54 = puVar3;
    if ((piVar4[0x3a] != iVar7) &&
       (puVar3 = (undefined4 *)piVar4[0x3c], puVar3 != (undefined4 *)0x0)) {
      uStack_210 = 0;
      uStack_20c = 0;
      if (puVar3 != &uStack_210) {
        FUN_8107db94(puVar3);
        puVar3[1] = uStack_20c;
        *puVar3 = uStack_210;
      }
      uStack_20c = 0;
      uStack_210 = 0;
      FUN_8107db94(&uStack_210);
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[5] = 0;
    }
    piVar4[0x3a] = iVar7;
    iVar7 = piVar4[0x37];
    (**(code **)(*piVar4 + 0xc))(piVar4);
    if ((piVar4[0x22] & 2U) != 0) {
      piVar4[0x12] = 0;
      piVar4[0x11] = 0x3f800000;
      piVar4[0x22] = piVar4[0x22] | 1;
      piVar4[0x13] = 0;
      piVar4[0x14] = 0;
      piVar4[0x15] = 0;
      piVar4[0x16] = 0x3f800000;
      piVar4[0x17] = 0;
      piVar4[0x18] = 0;
      piVar12 = piVar4 + 0x11;
      piVar4[0x19] = 0;
      uVar10 = 0;
      piVar4[0x1a] = 0;
      piVar4[0x1b] = 0x3f800000;
      piVar4[0x1c] = 0;
      piVar4[0x1d] = 0;
      piVar4[0x1e] = 0;
      uVar9 = piVar4[0x21];
      piVar4[0x1f] = 0;
      piVar4[0x20] = 0x3f800000;
      do {
        uVar5 = uVar9 & 3;
        if (uVar5 < 2) {
          if (uVar5 == 0) {
            if ((piVar4[0x21] & 0x20000000U) != 0) {
              fVar17 = (float)piVar4[0x2b];
              fVar15 = (float)func_0x81118490(fVar17,0,0);
              fVar16 = SQRT(1.0 - fVar15 * fVar15);
              uVar5 = in_fpscr & 0xfffffff | 0x40000000;
              if ((byte)(uVar5 >> 0x1e) == 0) {
                fVar16 = (float)func_0x811184a0();
              }
              uVar1 = uVar5 & 0xfffffff | (uint)(fVar17 < -1.570796) << 0x1f;
              in_fpscr = uVar1 | (uint)NAN(fVar17) << 0x1c;
              if (((byte)(uVar1 >> 0x1f) != ((byte)(in_fpscr >> 0x1c) & 1)) ||
                 (in_fpscr = uVar5 & 0xfffffff | (uint)(fVar17 == 1.570796) << 0x1e |
                             (uint)(1.570796 <= fVar17) << 0x1d, bVar2 = (byte)(in_fpscr >> 0x18),
                 (bool)(bVar2 >> 5 & 1) && !(bool)(bVar2 >> 6))) {
                fVar16 = -fVar16;
              }
              fStack_8c = -fVar15;
              uStack_b0 = 0x3f800000;
              uStack_ac = 0;
              uStack_a8 = 0;
              uStack_a4 = 0;
              uStack_a0 = 0;
              uStack_94 = 0;
              uStack_90 = 0;
              uStack_84 = 0;
              uStack_80 = 0;
              uStack_7c = 0;
              uStack_78 = 0;
              uStack_74 = 0x3f800000;
              fStack_9c = fVar16;
              fStack_98 = fVar15;
              fStack_88 = fVar16;
              func_0x810cfcc4(piVar12,piVar12,&uStack_b0);
            }
          }
          else if ((piVar4[0x21] & 0x10000000U) != 0) {
            fVar17 = (float)piVar4[0x2c];
            fVar15 = (float)func_0x81118490(fVar17,0,0);
            fVar16 = SQRT(1.0 - fVar15 * fVar15);
            uVar5 = in_fpscr & 0xfffffff | 0x40000000;
            if ((byte)(uVar5 >> 0x1e) == 0) {
              fVar16 = (float)func_0x811184a0();
            }
            uVar1 = uVar5 & 0xfffffff | (uint)(fVar17 < -1.570796) << 0x1f;
            in_fpscr = uVar1 | (uint)NAN(fVar17) << 0x1c;
            if (((byte)(uVar1 >> 0x1f) != ((byte)(in_fpscr >> 0x1c) & 1)) ||
               (in_fpscr = uVar5 & 0xfffffff | (uint)(fVar17 == 1.570796) << 0x1e |
                           (uint)(1.570796 <= fVar17) << 0x1d, bVar2 = (byte)(in_fpscr >> 0x18),
               (bool)(bVar2 >> 5 & 1) && !(bool)(bVar2 >> 6))) {
              fVar16 = -fVar16;
            }
            fStack_e8 = -fVar15;
            uStack_ec = 0;
            uStack_e4 = 0;
            uStack_e0 = 0;
            uStack_dc = 0x3f800000;
            uStack_d8 = 0;
            uStack_d4 = 0;
            uStack_cc = 0;
            uStack_c4 = 0;
            uStack_c0 = 0;
            uStack_bc = 0;
            uStack_b8 = 0;
            uStack_b4 = 0x3f800000;
            fStack_f0 = fVar16;
            fStack_d0 = fVar15;
            fStack_c8 = fVar16;
            func_0x810cfcc4(piVar12,piVar12,&fStack_f0);
          }
        }
        else if ((uVar5 < 3) && ((piVar4[0x21] & 0x8000000U) != 0)) {
          fVar17 = (float)piVar4[0x2d];
          fVar15 = (float)func_0x81118490(fVar17,0,0);
          fVar16 = SQRT(1.0 - fVar15 * fVar15);
          uVar5 = in_fpscr & 0xfffffff | 0x40000000;
          if ((byte)(uVar5 >> 0x1e) == 0) {
            fVar16 = (float)func_0x811184a0();
          }
          uVar1 = uVar5 & 0xfffffff | (uint)(fVar17 < -1.570796) << 0x1f;
          in_fpscr = uVar1 | (uint)NAN(fVar17) << 0x1c;
          if (((byte)(uVar1 >> 0x1f) != ((byte)(in_fpscr >> 0x1c) & 1)) ||
             (in_fpscr = uVar5 & 0xfffffff | (uint)(fVar17 == 1.570796) << 0x1e |
                         (uint)(1.570796 <= fVar17) << 0x1d, bVar2 = (byte)(in_fpscr >> 0x18),
             (bool)(bVar2 >> 5 & 1) && !(bool)(bVar2 >> 6))) {
            fVar16 = -fVar16;
          }
          fStack_120 = -fVar15;
          uStack_128 = 0;
          uStack_124 = 0;
          uStack_118 = 0;
          uStack_114 = 0;
          uStack_110 = 0;
          uStack_10c = 0;
          uStack_108 = 0x3f800000;
          uStack_104 = 0;
          uStack_100 = 0;
          uStack_fc = 0;
          uStack_f8 = 0;
          uStack_f4 = 0x3f800000;
          fStack_130 = fVar16;
          fStack_12c = fVar15;
          fStack_11c = fVar16;
          func_0x810cfcc4(piVar12,piVar12,&fStack_130);
        }
        uVar10 = uVar10 + 1;
        uVar9 = uVar9 >> 2;
      } while (uVar10 < 3);
    }
    if ((piVar4[0x22] & 1U) != 0) {
      fVar15 = (float)piVar4[0x29];
      fVar16 = (float)piVar4[0x2a];
      piVar4[4] = 0;
      piVar4[7] = 0;
      fVar17 = (float)VectorSignedToFloat(piVar4[0x34],(byte)(in_fpscr >> 0x15) & 3);
      piVar4[8] = 0;
      fVar18 = (float)VectorSignedToFloat(piVar4[0x35],(byte)(in_fpscr >> 0x15) & 3);
      piVar4[0xb] = 0x3f800000;
      piVar4[0xf] = piVar4[0x25];
      piVar4[1] = (int)(fVar15 * 1.0);
      piVar4[0xc] = 0;
      piVar4[2] = (int)(fVar16 * 0.0);
      fVar19 = (float)VectorSignedToFloat(piVar4[0x36],(byte)(in_fpscr >> 0x15) & 3);
      piVar4[0x10] = 0x3f800000;
      piVar4[5] = (int)(fVar15 * 0.0);
      piVar4[6] = (int)(fVar16 * 1.0);
      piVar4[3] = 0;
      piVar4[9] = (int)(fVar15 * 0.0);
      piVar4[10] = (int)(fVar16 * 0.0);
      piVar4[0xd] = (int)((float)piVar4[0x23] * fVar15);
      fStack_140 = -(fVar17 * fVar15);
      piVar4[0xe] = (int)((float)piVar4[0x24] * fVar16);
      fStack_13c = -(fVar18 * fVar16);
      fStack_138 = -fVar19;
      uStack_170 = 0x3f800000;
      uStack_16c = 0;
      uStack_168 = 0;
      uStack_164 = 0;
      uStack_160 = 0;
      uStack_15c = 0x3f800000;
      uStack_158 = 0;
      uStack_154 = 0;
      uStack_150 = 0;
      uStack_14c = 0;
      uStack_148 = 0x3f800000;
      uStack_144 = 0;
      uStack_134 = 0x3f800000;
      func_0x810cfcc4(piVar11,piVar11,&uStack_170);
      func_0x810cfcc4(piVar11,piVar11,piVar4 + 0x11);
      fStack_180 = fVar17 * fVar15;
      fStack_17c = fVar18 * fVar16;
      uStack_1b0 = 0x3f800000;
      uStack_1ac = 0;
      uStack_1a8 = 0;
      uStack_1a4 = 0;
      uStack_1a0 = 0;
      uStack_19c = 0x3f800000;
      uStack_198 = 0;
      uStack_194 = 0;
      uStack_190 = 0;
      uStack_18c = 0;
      uStack_188 = 0x3f800000;
      uStack_184 = 0;
      uStack_174 = 0x3f800000;
      fStack_178 = fVar19;
      func_0x810cfcc4(piVar11,piVar11,&uStack_1b0);
      fVar15 = (float)VectorSignedToFloat(piVar4[0x32],(byte)(in_fpscr >> 0x15) & 3);
      fVar16 = (float)VectorSignedToFloat(piVar4[0x33],(byte)(in_fpscr >> 0x15) & 3);
      iStack_1b8 = piVar4[0x28];
      uStack_1f0 = 0x3f800000;
      uStack_1ec = 0;
      uStack_1e8 = 0;
      fStack_1c0 = (float)piVar4[0x26] - fVar15 * (float)piVar4[0x29];
      uStack_1e4 = 0;
      uStack_1e0 = 0;
      fStack_1bc = (float)piVar4[0x27] - fVar16 * (float)piVar4[0x2a];
      uStack_1dc = 0x3f800000;
      uStack_1d8 = 0;
      uStack_1d4 = 0;
      uStack_1d0 = 0;
      uStack_1cc = 0;
      uStack_1c8 = 0x3f800000;
      uStack_1c4 = 0;
      uStack_1b4 = 0x3f800000;
      func_0x810cfcc4(piVar11,piVar11,&uStack_1f0);
    }
    func_0x810852f8(iVar7,piVar11);
    uStack_208 = 0;
    uStack_204 = 0;
    uStack_218 = 0;
    uStack_214 = 0;
    if (&uStack_208 != &uStack_218) {
      FUN_8107db94(&uStack_208);
      uStack_208 = uStack_218;
      uStack_204 = uStack_214;
    }
    uStack_214 = 0;
    uStack_218 = 0;
    FUN_8107db94(&uStack_218);
    uStack_200 = 0;
    uStack_1fc = 0;
    uStack_1f8 = 0;
    uStack_1f4 = 0;
    iVar6 = *piVar4;
    puVar3 = &uStack_208;
    if ((undefined4 *)piVar4[0x3c] != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)piVar4[0x3c];
    }
    if (puVar3[1] == 0) {
      (**(code **)(iVar6 + 0x10))(piVar4,puVar3);
      iVar6 = *piVar4;
    }
    (**(code **)(iVar6 + 0x14))(piVar4,puVar3);
    func_0x810767e0(iVar7);
    FUN_81075858(piVar4[0x38]);
    piVar4[0x22] = 0;
    FUN_8107db94(&uStack_208);
    if (_UNK_8111a5b0 != iStack_70) {
      uVar14 = 0x810745d9;
      iVar6 = func_0x811185a0();
      uVar21 = 0;
      uVar13 = *(undefined4 *)(iVar6 + 0xdc);
      uVar8 = *(undefined4 *)(iVar6 + 0xec);
      func_0x810767e0(uVar13);
      FUN_810767e2(uVar13,4,3,uVar8,puVar3,uVar21,iVar7,uVar14);
      iVar7 = *(int *)(iVar6 + 0xe0);
      if (*(char *)(iVar7 + 0x20) != '\0') {
        func_0x810846aa(iVar7);
        *(undefined *)(iVar7 + 0x20) = 0;
      }
      func_0x8108461e(iVar7,0,0);
      return;
    }
    return;
  }
  return;
}

