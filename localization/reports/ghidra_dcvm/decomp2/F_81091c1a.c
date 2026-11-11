
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81091c1a(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uStack_280;
  undefined4 auStack_27c [18];
  undefined *puStack_234;
  undefined4 uStack_230;
  undefined4 uStack_220;
  int iStack_1f8;
  undefined4 *puStack_1f4;
  undefined4 uStack_1f0;
  int iStack_1ec;
  undefined *puStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 auStack_1dc [18];
  undefined4 *puStack_194;
  undefined4 uStack_190;
  undefined4 uStack_184;
  int iStack_158;
  undefined4 *puStack_154;
  undefined4 uStack_150;
  int iStack_14c;
  undefined *puStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 auStack_13c [18];
  undefined4 *puStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_e8;
  int iStack_b8;
  undefined4 *puStack_b4;
  undefined4 uStack_b0;
  int iStack_ac;
  undefined *puStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 auStack_9c [18];
  undefined4 *puStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_18;
  
  puVar6 = &uStack_a0;
  iStack_18 = _UNK_8111a5b0;
  puVar4 = (undefined4 *)0x88;
  func_0x81118610(&uStack_a0,0);
  uStack_a0 = 0x3000061;
  puVar7 = param_3;
  puStack_54 = (undefined4 *)&stack0xc0d1a06d;
  if (param_3 != (undefined4 *)0x0) {
    puVar7 = (undefined4 *)param_3[0x12];
    iVar9 = 9;
    do {
      uVar1 = *param_3;
      iVar9 = iVar9 + -1;
      uVar2 = param_3[1];
      param_3 = param_3 + 2;
      puVar6[1] = uVar1;
      puVar6 = puVar6 + 2;
      *puVar6 = uVar2;
      puStack_54 = puVar7;
    } while (iVar9 != 0);
  }
  *(undefined *)(param_1 + 0x44) = 1;
  uStack_50 = 1;
  uStack_4c = param_2;
  iVar9 = func_0x81116e50(&uStack_a0);
  if (iVar9 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar2 = 0x81091ca9;
  uVar10 = func_0x811185a0();
  uVar1 = (undefined4)((ulonglong)uVar10 >> 0x20);
  puStack_a8 = &UNK_8111a5b0;
  puVar6 = &uStack_140;
  iStack_b8 = _UNK_8111a5b0;
  puVar5 = (undefined4 *)0x88;
  puStack_b4 = puVar7;
  uStack_b0 = param_2;
  iStack_ac = param_1;
  uStack_a4 = uVar2;
  func_0x81118610(&uStack_140,0);
  uStack_140 = 0x3000061;
  puVar7 = puVar4;
  puStack_f4 = (undefined4 *)&stack0xc0d19fcd;
  if (puVar4 != (undefined4 *)0x0) {
    puVar7 = (undefined4 *)puVar4[0x12];
    iVar9 = 9;
    do {
      uVar2 = *puVar4;
      iVar9 = iVar9 + -1;
      uVar3 = puVar4[1];
      puVar4 = puVar4 + 2;
      puVar6[1] = uVar2;
      puVar6 = puVar6 + 2;
      *puVar6 = uVar3;
      puStack_f4 = puVar7;
    } while (iVar9 != 0);
  }
  *(undefined *)((int)uVar10 + 0x44) = 2;
  uStack_f0 = 2;
  uStack_e8 = uVar1;
  iVar9 = func_0x81116e50(&uStack_140);
  if (iVar9 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_b8) {
    return;
  }
  uVar3 = 0x81091d39;
  uVar11 = func_0x811185a0();
  uVar2 = (undefined4)((ulonglong)uVar11 >> 0x20);
  puStack_148 = &UNK_8111a5b0;
  puVar6 = &uStack_1e0;
  iStack_158 = _UNK_8111a5b0;
  puVar4 = (undefined4 *)0x88;
  puStack_154 = puVar7;
  uStack_150 = uVar1;
  iStack_14c = (int)uVar10;
  uStack_144 = uVar3;
  func_0x81118610(&uStack_1e0,0);
  uStack_1e0 = 0x3000061;
  puVar7 = puVar5;
  puStack_194 = (undefined4 *)&stack0xc0d19f2d;
  if (puVar5 != (undefined4 *)0x0) {
    puVar7 = (undefined4 *)puVar5[0x12];
    iVar9 = 9;
    do {
      uVar1 = *puVar5;
      iVar9 = iVar9 + -1;
      uVar3 = puVar5[1];
      puVar5 = puVar5 + 2;
      puVar6[1] = uVar1;
      puVar6 = puVar6 + 2;
      *puVar6 = uVar3;
      puStack_194 = puVar7;
    } while (iVar9 != 0);
  }
  *(undefined *)((int)uVar11 + 0x44) = 3;
  uStack_190 = 3;
  uStack_184 = uVar2;
  iVar9 = func_0x81116e50(&uStack_1e0);
  if (iVar9 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_158) {
    return;
  }
  uVar1 = 0x81091dc9;
  uVar10 = func_0x811185a0();
  puStack_1e8 = &UNK_8111a5b0;
  puVar6 = &uStack_280;
  iStack_1f8 = _UNK_8111a5b0;
  puStack_1f4 = puVar7;
  uStack_1f0 = uVar2;
  iStack_1ec = (int)uVar11;
  uStack_1e4 = uVar1;
  func_0x81118610(&uStack_280,0,0x88);
  uStack_280 = 0x3000061;
  puStack_234 = &stack0xc0d19e8d;
  if (puVar4 != (undefined4 *)0x0) {
    puVar8 = (undefined *)puVar4[0x12];
    iVar9 = 9;
    do {
      uVar1 = *puVar4;
      iVar9 = iVar9 + -1;
      uVar2 = puVar4[1];
      puVar4 = puVar4 + 2;
      puVar6[1] = uVar1;
      puVar6 = puVar6 + 2;
      *puVar6 = uVar2;
      puStack_234 = puVar8;
    } while (iVar9 != 0);
  }
  *(undefined *)((int)uVar10 + 0x44) = 4;
  uStack_230 = 4;
  uStack_220 = (int)((ulonglong)uVar10 >> 0x20);
  iVar9 = func_0x81116e50(&uStack_280);
  if (iVar9 == 0) {
    if (_UNK_8111a5b0 != iStack_1f8) {
      func_0x811185a0();
      return;
    }
    return;
  }
  do {
    func_0x81118870(1000);
  } while( true );
}

