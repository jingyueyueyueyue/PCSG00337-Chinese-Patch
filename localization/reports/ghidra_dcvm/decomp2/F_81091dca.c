
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81091dca(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uStack_a0;
  undefined4 auStack_9c [18];
  undefined *puStack_54;
  undefined4 uStack_50;
  undefined4 uStack_40;
  int iStack_18;
  
  puVar3 = &uStack_a0;
  iStack_18 = _UNK_8111a5b0;
  func_0x81118610(&uStack_a0,0,0x88);
  uStack_a0 = 0x3000061;
  puStack_54 = &stack0xc0d1a06d;
  if (param_3 != (undefined4 *)0x0) {
    puVar4 = (undefined *)param_3[0x12];
    iVar5 = 9;
    do {
      uVar1 = *param_3;
      iVar5 = iVar5 + -1;
      uVar2 = param_3[1];
      param_3 = param_3 + 2;
      puVar3[1] = uVar1;
      puVar3 = puVar3 + 2;
      *puVar3 = uVar2;
      puStack_54 = puVar4;
    } while (iVar5 != 0);
  }
  *(undefined *)(param_1 + 0x44) = 4;
  uStack_50 = 4;
  uStack_40 = param_2;
  iVar5 = func_0x81116e50(&uStack_a0);
  if (iVar5 == 0) {
    if (_UNK_8111a5b0 != iStack_18) {
      func_0x811185a0();
      return;
    }
    return;
  }
  do {
    func_0x81118870(1000);
  } while( true );
}

