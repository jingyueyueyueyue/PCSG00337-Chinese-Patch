
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810944a8(void)

{
  int iVar1;
  uint *puVar2;
  uint uStack_78;
  uint uStack_74;
  undefined auStack_70 [2];
  undefined2 uStack_6e;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  func_0x811182b0(auStack_70,0x8114a70c,0x5c);
  uStack_4c = 0x81191df8;
  uStack_48 = 0xa010;
  uStack_34 = 0x8119be08;
  uStack_30 = 0x10008;
  uStack_44 = 0x811abe10;
  uStack_40 = 0x1808;
  uStack_3c = 0x811abe10;
  uStack_38 = 0x608;
  uStack_6e = 0x100;
  uStack_24 = 0xab;
  uStack_20 = 0xaf;
  uStack_1c = 0x70000;
  uStack_18 = 0x70000;
  iVar1 = func_0x81117130(auStack_70);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  uRam8114a778 = uRam8114a778 + 0x1fff & 0xffffe000;
  uStack_78 = uRam8114a778 * iRam8114a77c;
  if (uStack_78 != 0) {
    uStack_74 = 0x20000;
    puVar2 = &uStack_74;
    if (0x20000 < uStack_78) {
      puVar2 = &uStack_78;
    }
    uRam8114a6ec = *puVar2;
    uRam8114a6f0 = uRam8114a778;
    uStack_78 = uRam8114a6ec;
    uRam8114a6f4 = func_0x81118390(8);
    iVar1 = func_0x811171a0(0,&UNK_811170e0,0x8114a6e8);
    if (iVar1 != 0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
  }
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  func_0x811185a0();
  func_0x811170d0();
  return;
}

