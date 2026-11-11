
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81091fe2(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 uStack_170;
  undefined4 auStack_16c [18];
  undefined *puStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_10c;
  int iStack_d4;
  undefined4 *puStack_cc;
  undefined4 uStack_c8;
  int iStack_c4;
  undefined *puStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 auStack_b4 [18];
  undefined4 *puStack_6c;
  undefined4 uStack_68;
  undefined4 *puStack_64;
  undefined4 uStack_50;
  int iStack_1c;
  
  puVar3 = &uStack_b8;
  iStack_1c = _UNK_8111a5b0;
  func_0x81118610(&uStack_b8,0,0x9c);
  uStack_b8 = 0x3000061;
  puVar5 = param_3;
  puStack_6c = (undefined4 *)&stack0xc0d1a055;
  if (param_3 != (undefined4 *)0x0) {
    puVar5 = (undefined4 *)param_3[0x12];
    iVar7 = 9;
    do {
      uVar1 = *param_3;
      iVar7 = iVar7 + -1;
      uVar2 = param_3[1];
      param_3 = param_3 + 2;
      puVar3[1] = uVar1;
      puVar3 = puVar3 + 2;
      *puVar3 = uVar2;
      puStack_6c = puVar5;
    } while (iVar7 != 0);
  }
  puVar3 = *(undefined4 **)(param_1 + 0x18);
  uStack_68 = 5;
  *(undefined4 *)(param_1 + 0x54) = 5;
  puStack_64 = puVar3;
  uStack_50 = param_2;
  iVar7 = func_0x81116ed0(&uStack_b8);
  if (iVar7 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_1c) {
    return;
  }
  uVar1 = 0x81092073;
  uVar8 = func_0x811185a0();
  puStack_c0 = &UNK_8111a5b0;
  puVar4 = &uStack_170;
  iStack_d4 = _UNK_8111a5b0;
  puStack_cc = puVar5;
  uStack_c8 = param_2;
  iStack_c4 = param_1;
  uStack_bc = uVar1;
  func_0x81118610(&uStack_170,0,0x9c);
  uStack_170 = 0x3000061;
  puStack_124 = &stack0xc0d19f9d;
  if (puVar3 != (undefined4 *)0x0) {
    puVar6 = (undefined *)puVar3[0x12];
    iVar7 = 9;
    do {
      uVar1 = *puVar3;
      iVar7 = iVar7 + -1;
      uVar2 = puVar3[1];
      puVar3 = puVar3 + 2;
      puVar4[1] = uVar1;
      puVar4 = puVar4 + 2;
      *puVar4 = uVar2;
      puStack_124 = puVar6;
    } while (iVar7 != 0);
  }
  uStack_11c = *(undefined4 *)((int)uVar8 + 0x18);
  uStack_120 = 4;
  *(undefined4 *)((int)uVar8 + 0x54) = 4;
  uStack_10c = (int)((ulonglong)uVar8 >> 0x20);
  iVar7 = func_0x81116ed0(&uStack_170);
  if (iVar7 == 0) {
    if (_UNK_8111a5b0 != iStack_d4) {
      func_0x811185a0();
      return;
    }
    return;
  }
  do {
    func_0x81118870(1000);
  } while( true );
}

