
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81091caa(int param_1,undefined4 param_2,undefined4 *param_3)

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
  undefined4 uStack_1e0;
  undefined4 auStack_1dc [18];
  undefined *puStack_194;
  undefined4 uStack_190;
  undefined4 uStack_180;
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
  undefined4 uStack_e4;
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
  undefined4 uStack_48;
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
  *(undefined *)(param_1 + 0x44) = 2;
  uStack_50 = 2;
  uStack_48 = param_2;
  iVar9 = func_0x81116e50(&uStack_a0);
  if (iVar9 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar2 = 0x81091d39;
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
  *(undefined *)((int)uVar10 + 0x44) = 3;
  uStack_f0 = 3;
  uStack_e4 = uVar1;
  iVar9 = func_0x81116e50(&uStack_140);
  if (iVar9 == 0) {
    if (_UNK_8111a5b0 == iStack_b8) {
      return;
    }
    uVar2 = 0x81091dc9;
    uVar11 = func_0x811185a0();
    puStack_148 = &UNK_8111a5b0;
    puVar6 = &uStack_1e0;
    iStack_158 = _UNK_8111a5b0;
    puStack_154 = puVar7;
    uStack_150 = uVar1;
    iStack_14c = (int)uVar10;
    uStack_144 = uVar2;
    func_0x81118610(&uStack_1e0,0,0x88);
    uStack_1e0 = 0x3000061;
    puStack_194 = &stack0xc0d19f2d;
    if (puVar5 != (undefined4 *)0x0) {
      puVar8 = (undefined *)puVar5[0x12];
      iVar9 = 9;
      do {
        uVar1 = *puVar5;
        iVar9 = iVar9 + -1;
        uVar2 = puVar5[1];
        puVar5 = puVar5 + 2;
        puVar6[1] = uVar1;
        puVar6 = puVar6 + 2;
        *puVar6 = uVar2;
        puStack_194 = puVar8;
      } while (iVar9 != 0);
    }
    *(undefined *)((int)uVar11 + 0x44) = 4;
    uStack_190 = 4;
    uStack_180 = (int)((ulonglong)uVar11 >> 0x20);
    iVar9 = func_0x81116e50(&uStack_1e0);
    if (iVar9 == 0) {
      if (_UNK_8111a5b0 != iStack_158) {
        func_0x811185a0();
        return;
      }
      return;
    }
    do {
      func_0x81118870(1000);
    } while( true );
  }
  do {
    func_0x81118870(1000);
  } while( true );
}

