
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81089054(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  
  iStack_1c = _UNK_8111a5b0;
  puVar1 = (undefined4 *)func_0x81005a98(0x58);
  puVar5 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    func_0x8107d66a(puVar1,0);
    *(undefined *)((int)puVar1 + 0x56) = 0;
    *puVar1 = &UNK_81146540;
    puVar1[1] = &UNK_81146554;
    puVar5 = puVar1;
  }
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_2c = 0x10;
  uVar6 = uRam8114a7a4 & 0xfffc0000;
  uStack_20 = 0;
  puRam811ae68c = puVar5;
  iVar2 = func_0x811187c0(&uStack_2c);
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (uVar6 < uStack_24) {
    uVar6 = uStack_24;
  }
  iVar2 = func_0x810c8324(uVar6,uRam8114a7a8);
  iVar3 = func_0x811187f0(&UNK_81137a50,0x9408060,uVar6,0);
  if (iVar3 < 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  uStack_30 = 0;
  iVar3 = func_0x811187e0(iVar3,&uStack_30);
  if (iVar3 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  uVar4 = func_0x81118390(4,iVar2 << 1);
  func_0x8107d746(puRam811ae68c,uStack_30,uVar4,uRam8114a7a8,iVar2 - 1U & 0xffff,uVar6,uRam8114a7a8)
  ;
  iVar2 = func_0x81116b50(uStack_30,uVar6,3);
  if (iVar2 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  if (_UNK_8111a5b0 == iStack_1c) {
    return;
  }
  func_0x811185a0();
  return;
}

