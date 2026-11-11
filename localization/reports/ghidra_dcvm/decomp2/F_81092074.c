
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81092074(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uStack_b8;
  undefined4 auStack_b4 [18];
  undefined *puStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_54;
  int iStack_1c;
  
  puVar3 = &uStack_b8;
  iStack_1c = _UNK_8111a5b0;
  func_0x81118610(&uStack_b8,0,0x9c);
  uStack_b8 = 0x3000061;
  puStack_6c = &stack0xc0d1a055;
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
      puStack_6c = puVar4;
    } while (iVar5 != 0);
  }
  uStack_64 = *(undefined4 *)(param_1 + 0x18);
  uStack_68 = 4;
  *(undefined4 *)(param_1 + 0x54) = 4;
  uStack_54 = param_2;
  iVar5 = func_0x81116ed0(&uStack_b8);
  if (iVar5 == 0) {
    if (_UNK_8111a5b0 != iStack_1c) {
      func_0x811185a0();
      return;
    }
    return;
  }
  do {
    func_0x81118870(1000);
  } while( true );
}

