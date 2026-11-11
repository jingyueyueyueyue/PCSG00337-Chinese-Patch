
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8108ebe0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  iVar1 = func_0x81116d50(0xb);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  func_0x810a0444();
  iVar4 = iRam8114a780 + iRam8114a788 + iRam8114a784 + iRam8114a790 + iRam8114a78c;
  iStack_34 = iRam8114a78c * 10 + iRam8114a790 * 10 + iRam8114a784 * 10 + iRam8114a788 * 10 +
              iRam8114a780 * 10;
  uStack_44 = 10;
  iStack_40 = iVar4 + 1;
  uStack_3c = 0x200;
  uStack_38 = 48000;
  iVar1 = func_0x81116fd0(&uStack_44,&uStack_48);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  iVar1 = func_0x81118390(0x100,uStack_48);
  *(int *)(param_1 + 0xc) = iVar1;
  if (iVar1 == 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  iVar1 = func_0x81117090(iVar1,uStack_48,&uStack_44,param_1 + 8);
  if (iVar1 != 0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  func_0x810a0480(*(undefined4 *)(param_1 + 8),&UNK_81137c4c);
  func_0x81116fb0(*(undefined4 *)(param_1 + 8),0);
  iVar1 = func_0x81005a98(0x58);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = func_0x8109f39c(iVar1,&UNK_81137c50,*(undefined4 *)(param_1 + 0x14));
  }
  piVar5 = *(int **)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = uVar2;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))(piVar5);
    uVar2 = *(undefined4 *)(param_1 + 0x18);
  }
  func_0x8109f4b0(uVar2,*(undefined4 *)(param_1 + 8),0,iVar4);
  uStack_30 = 0;
  iStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 1;
  uStack_1c = 0;
  iVar1 = func_0x81005a98(0x40);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_8108efc8(iVar1,&UNK_81137c5c,*(undefined4 *)(param_1 + 0x14));
  }
  piVar5 = *(int **)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))();
  }
  iStack_2c = iRam8114a784;
  uStack_28 = 1;
  uStack_30 = func_0x81117080();
  func_0x8108f06a(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 8),&uStack_30);
  iVar4 = func_0x81005a98(0x40);
  uVar2 = 0;
  if (iVar4 != 0) {
    uVar2 = FUN_8108efc8(iVar4,&UNK_81137c68,*(undefined4 *)(param_1 + 0x14));
  }
  piVar5 = *(int **)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))();
  }
  iStack_2c = iRam8114a788;
  uStack_28 = 2;
  uStack_30 = func_0x81117080();
  func_0x8108f06a(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 8),&uStack_30);
  iVar4 = func_0x81005a98(0x40);
  uVar2 = 0;
  if (iVar4 != 0) {
    uVar2 = FUN_8108efc8(iVar4,&UNK_81137c74,*(undefined4 *)(param_1 + 0x14));
  }
  piVar5 = *(int **)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))();
  }
  iStack_2c = iRam8114a78c;
  uStack_28 = 1;
  uStack_30 = func_0x81116f10();
  func_0x8108f06a(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 8),&uStack_30);
  iVar4 = func_0x81005a98(0x40);
  uVar2 = 0;
  if (iVar4 != 0) {
    uVar2 = FUN_8108efc8(iVar4,&UNK_81137c80,*(undefined4 *)(param_1 + 0x14));
  }
  piVar5 = *(int **)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))();
  }
  iStack_2c = iRam8114a790;
  uStack_28 = 2;
  uStack_30 = func_0x81116f10();
  func_0x8108f06a(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 8),&uStack_30);
  iVar4 = func_0x81005a98(0x40);
  uVar2 = 0;
  if (iVar4 != 0) {
    uVar2 = FUN_8108efc8(iVar4,&UNK_81137c8c,*(undefined4 *)(param_1 + 0x14));
  }
  piVar5 = *(int **)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x2c) = uVar2;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))();
  }
  iStack_2c = iRam8114a780;
  uStack_28 = 2;
  uStack_30 = func_0x81116f10();
  func_0x8108f06a(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 8),&uStack_30);
  if (_UNK_8111a5b0 == iStack_18) {
    return;
  }
  uVar6 = 0x8108eed5;
  iVar4 = func_0x811185a0();
  uVar7 = 0;
  FUN_8108ebe0();
  uVar2 = 0;
  iVar3 = func_0x81005a98(8);
  if (iVar3 != 0) {
    uVar2 = func_0x810942ac();
  }
  iVar3 = *(int *)(iVar4 + 0x10);
  *(undefined4 *)(iVar4 + 0x10) = uVar2;
  if (iVar3 != 0) {
    func_0x810942c4(iVar3);
    func_0x81005af0();
    uVar2 = *(undefined4 *)(iVar4 + 0x10);
  }
  FUN_810942c8(uVar2,&UNK_81137c38,&UNK_8108efbd,0x40,0x20000,0,0x70000,0,param_1,iVar1,uVar7,uVar6)
  ;
  FUN_81094306(*(undefined4 *)(iVar4 + 0x10),iVar4);
  return;
}

