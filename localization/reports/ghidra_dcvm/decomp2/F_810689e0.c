
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_810689e0(void)

{
  int iVar1;
  int iVar2;
  int *piStack_28;
  undefined *puStack_24;
  undefined *puStack_20;
  undefined *puStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = _UNK_8111a5b0;
  puStack_24 = &UNK_81137104;
  puStack_20 = &UNK_8113712c;
  iVar2 = 0;
  puStack_1c = &UNK_81137168;
  uStack_18 = 0;
  func_0x81093d06(&puStack_24,&UNK_81137178,0x30c,0x1e0);
  iVar1 = func_0x81005a98(0x334);
  if (iVar1 != 0) {
    iVar2 = func_0x810218a0();
  }
  iVar1 = func_0x81005a98(0x80);
  piStack_28 = (int *)0x0;
  if (iVar1 != 0) {
    piStack_28 = (int *)func_0x81021a82(iVar1);
  }
  func_0x810a0c62(iVar2 + 4,&piStack_28);
  if (piStack_28 != (int *)0x0) {
    (**(code **)(*piStack_28 + 4))();
  }
  if (_UNK_8111a5b0 == iStack_14) {
    return;
  }
  func_0x811185a0();
  uRam81191074 = 0x80000001;
  uRam8119104c = 0x80000001;
  uRam81191050 = 0x80000002;
  uRam81191054 = 0x80000003;
  uRam81191058 = 0x80000003;
  uRam8119105c = 0x80000005;
  uRam81191060 = 0x80000006;
  uRam81191064 = 0x80000007;
  uRam81191068 = 0x80000008;
  uRam8119106c = 0x80000009;
  uRam81191070 = 0x8000000a;
  func_0x811184e0(0x81191048);
  func_0x81118450(0x81191048,&UNK_811184f0,0x811ae7e8);
  func_0x81118500(0x81191049);
  func_0x81118450(0x81191049,&UNK_811184d0,0x811ae7e8);
  return;
}

