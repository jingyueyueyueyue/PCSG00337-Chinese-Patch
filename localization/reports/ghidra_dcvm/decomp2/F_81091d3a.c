
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81091d3a(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 uStack_140;
  undefined4 auStack_13c [18];
  undefined *puStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_e0;
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
  undefined4 uStack_44;
  int iStack_18;
  
  puVar4 = &uStack_a0;
  iStack_18 = _UNK_8111a5b0;
  puVar3 = (undefined4 *)0x88;
  func_0x81118610(&uStack_a0,0);
  uStack_a0 = 0x3000061;
  puVar5 = param_3;
  puStack_54 = (undefined4 *)&stack0xc0d1a06d;
  if (param_3 != (undefined4 *)0x0) {
    puVar5 = (undefined4 *)param_3[0x12];
    iVar7 = 9;
    do {
      uVar1 = *param_3;
      iVar7 = iVar7 + -1;
      uVar2 = param_3[1];
      param_3 = param_3 + 2;
      puVar4[1] = uVar1;
      puVar4 = puVar4 + 2;
      *puVar4 = uVar2;
      puStack_54 = puVar5;
    } while (iVar7 != 0);
  }
  *(undefined *)(param_1 + 0x44) = 3;
  uStack_50 = 3;
  uStack_44 = param_2;
  iVar7 = func_0x81116e50(&uStack_a0);
  if (iVar7 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar1 = 0x81091dc9;
  uVar8 = func_0x811185a0();
  puStack_a8 = &UNK_8111a5b0;
  puVar4 = &uStack_140;
  iStack_b8 = _UNK_8111a5b0;
  puStack_b4 = puVar5;
  uStack_b0 = param_2;
  iStack_ac = param_1;
  uStack_a4 = uVar1;
  func_0x81118610(&uStack_140,0,0x88);
  uStack_140 = 0x3000061;
  puStack_f4 = &stack0xc0d19fcd;
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
      puStack_f4 = puVar6;
    } while (iVar7 != 0);
  }
  *(undefined *)((int)uVar8 + 0x44) = 4;
  uStack_f0 = 4;
  uStack_e0 = (int)((ulonglong)uVar8 >> 0x20);
  iVar7 = func_0x81116e50(&uStack_140);
  if (iVar7 == 0) {
    if (_UNK_8111a5b0 != iStack_b8) {
      func_0x811185a0();
      return;
    }
    return;
  }
  do {
    func_0x81118870(1000);
  } while( true );
}

