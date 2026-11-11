
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_81087be2(int *param_1,int *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int **ppiVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  int *piStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  undefined4 uStack_44;
  int *piStack_40;
  int iStack_3c;
  undefined *puStack_38;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  iStack_20 = *param_2;
  uVar6 = 0;
  iStack_1c = param_2[1];
  *param_2 = 0;
  param_2[1] = 0;
  func_0x810874e4(*param_1);
  iVar8 = *param_1;
  if ((int *)(iVar8 + 0x1c) != &iStack_20) {
    FUN_8107db94();
    *(int *)(iVar8 + 0x20) = iStack_1c;
    *(int *)(iVar8 + 0x1c) = iStack_20;
    iStack_20 = 0;
    iStack_1c = 0;
  }
  uVar1 = func_0x810877ba(param_1,param_3);
  FUN_8107db94(&iStack_20);
  if (_UNK_8111a5b0 == iStack_18) {
    return uVar1;
  }
  iVar3 = iStack_18;
  uVar10 = func_0x811185a0(uVar1);
  iVar4 = (int)((ulonglong)uVar10 >> 0x20);
  ppiVar2 = (int **)uVar10;
  puStack_38 = &UNK_8111a5b0;
  iStack_4c = _UNK_8111a5b0;
  iVar9 = iStack_20;
  if (iStack_20 == 0) {
    iVar9 = -0x7ee523b8;
  }
  iStack_50 = iVar4;
  uStack_44 = uVar1;
  piStack_40 = param_1;
  iStack_3c = iVar8;
  func_0x810874e4(*ppiVar2);
  piVar7 = *ppiVar2;
  iVar8 = func_0x81005aaa(0x14);
  iVar5 = *piVar7;
  *piVar7 = iVar8;
  piVar7[1] = 0x14;
  func_0x81005b02(iVar5);
  piVar7 = *ppiVar2;
  piVar7[4] = 1;
  piStack_58 = *(int **)(iVar9 + 4);
  iVar8 = iVar3 * ((uVar6 & 0xf) * 4 * (iVar4 + 7U & 0xfffffff8) >> 3);
  if (iVar8 == 0) {
    iVar8 = 1;
  }
  iStack_54 = (**(code **)(*piStack_58 + 0xc))(piStack_58,iVar8,piStack_58 + 9,piStack_58[1]);
  if ((int **)(piVar7 + 9) != &piStack_58) {
    FUN_8107db94(piVar7 + 9);
    piVar7[10] = iStack_54;
    piVar7[9] = (int)piStack_58;
    piStack_58 = (int *)0x0;
    iStack_54 = 0;
  }
  FUN_8107db94(&piStack_58);
  uVar1 = func_0x81088f3e(uVar6);
  func_0x811168c0(**ppiVar2,(*ppiVar2)[10],uVar1,iStack_50,iVar3,0);
  iVar8 = **ppiVar2;
  uVar6 = func_0x81116ae0(iVar8);
  if (uVar6 == 0) {
    iVar3 = func_0x811167b0(iVar8);
    func_0x81116c20(iVar8);
    uVar6 = func_0x81088d98();
    uVar6 = (uVar6 & 0xf) * 4 * (iVar3 + 7U & 0xfffffff8) >> 3;
  }
  *(uint *)(**ppiVar2 + 0x10) = uVar6;
  if (_UNK_8111a5b0 == iStack_4c) {
    return 0;
  }
  piVar7 = (int *)func_0x811185a0(0);
  return *(undefined4 *)(*piVar7 + 0x10);
}

