
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8108c4b2(void)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined auStack_a0 [32];
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  func_0x8107debc();
  uVar2 = 0;
  iVar1 = func_0x81005a98(8);
  if (iVar1 != 0) {
    uVar2 = FUN_8108c97e();
  }
  func_0x8107d5f0(uVar2);
  uVar4 = 0;
  puVar3 = (uint *)&UNK_81137b50;
  do {
    iVar1 = func_0x81116d50(*puVar3 & 0xffff);
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    uVar4 = uVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar4 < 2);
  FUN_8108d0da();
  FUN_8108d024(0x2d);
  FUN_810944a8();
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  iVar1 = func_0x811172a0(&uStack_58,&uStack_80);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  uStack_b0 = 0x10;
  uStack_ac = 0;
  uStack_a8 = 0;
  uStack_a4 = 0;
  func_0x811187c0(&uStack_b0);
  func_0x81118340(uRam811913d8,auStack_a0);
  if (iRam811913e8 != 0) {
    func_0x81118340(iRam811913e8,auStack_a0);
  }
  if (iRam811913f8 != 0) {
    func_0x81118340(iRam811913f8,auStack_a0);
  }
  if (_UNK_8111a5b0 == iStack_18) {
    return _UNK_8111a5b0;
  }
  func_0x811185a0();
  return 0;
}

