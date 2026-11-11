
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_8102198e(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  
  iStack_2c = _UNK_8111a5b0;
  piVar1 = (int *)func_0x810a15ac(**(undefined4 **)(*(int *)(param_1 + 0x14) + 0x1c));
  puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x20))();
  uVar6 = 0;
  iVar5 = -0x7eeb5dc0;
  do {
    piVar1 = (int *)0x0;
    iVar3 = func_0x81005a98(0x4c);
    if (iVar3 != 0) {
      piVar1 = (int *)func_0x81078a26();
    }
    if (piVar1 == (int *)0x0) {
      do {
        func_0x81118870(1000);
      } while( true );
    }
    iVar3 = func_0x81081a68(*(undefined4 *)(iVar5 + 4),&UNK_811358bc);
    if (iVar3 != 0) {
      func_0x8105fe7a(param_1 + 0x3c,0xff,piVar1);
    }
    func_0x81078c10(piVar1,*(undefined4 *)(iVar5 + 8));
    piVar1[0x11] = *(int *)(iVar5 + 4);
    FUN_810945c0(&iStack_34,*(undefined4 *)(iVar5 + 4),0x8119137c,0);
    (**(code **)(*piVar1 + 8))(piVar1);
    if (piVar1 + 3 != &iStack_34) {
      func_0x8107db94();
      piVar1[4] = iStack_30;
      piVar1[3] = iStack_34;
      iStack_34 = 0;
      iStack_30 = 0;
    }
    func_0x8107db94(&iStack_34);
    func_0x8107860c(piVar1);
    func_0x81078d56(*puVar2,piVar1);
    uVar6 = uVar6 + 1;
    iVar5 = iVar5 + 0x10;
  } while (uVar6 < 0xf);
  if (_UNK_8111a5b0 == iStack_2c) {
    return (undefined4 *)0x1;
  }
  puVar2 = (undefined4 *)func_0x811185a0(1);
  func_0x81000368();
  *puVar2 = &UNK_8113afb8;
  iVar5 = 3;
  puVar4 = (undefined2 *)0x8118124e;
  do {
    *puVar4 = 0;
    iVar5 = iVar5 + -1;
    puVar4 = puVar4 + -1;
  } while (-1 < iVar5);
  uRam81181248 = uRam81181248 | 0x4001;
  uRam8114a79c = 0x3f19999a;
  uRam8114a7a0 = 0x3f800000;
  return puVar2;
}

