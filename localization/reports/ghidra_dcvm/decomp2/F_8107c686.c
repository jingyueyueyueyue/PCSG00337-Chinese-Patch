
void FUN_8107c686(int *param_1,int *param_2)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  uint uVar7;
  undefined *puVar8;
  ushort *puVar9;
  undefined2 *puVar10;
  int iVar11;
  uint uVar12;
  
  (**(code **)(*param_1 + 0x18))(param_1);
  if (param_1 + 3 != param_2) {
    piVar2 = (int *)param_1[3];
    param_1[3] = *param_2;
    *param_2 = 0;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))();
    }
  }
  iVar3 = (**(code **)(*(int *)param_1[3] + 0x14))();
  param_1[10] = iVar3;
  if (iVar3 == 0) {
    param_1[10] = 1;
  }
  iVar3 = (**(code **)(*(int *)param_1[3] + 0x18))();
  param_1[0xb] = iVar3;
  if (iVar3 == 0) {
    iVar3 = 1;
    param_1[0xb] = 1;
  }
  puVar4 = (undefined *)func_0x81005aaa(iVar3 << 1);
  if ((puVar4 != (undefined *)0x0) && (puVar8 = puVar4, 0 < iVar3)) {
    do {
      *puVar8 = 0;
      iVar3 = iVar3 + -1;
      puVar8[1] = 0;
      puVar8 = puVar8 + 2;
    } while (iVar3 != 0);
  }
  iVar3 = param_1[4];
  param_1[4] = (int)puVar4;
  param_1[5] = 2;
  func_0x81005b02(iVar3);
  iVar3 = param_1[10];
  puVar5 = (ushort *)func_0x81005aaa(iVar3 << 1);
  if ((puVar5 != (ushort *)0x0) && (puVar9 = puVar5, 0 < iVar3)) {
    do {
      uVar1 = *puVar9;
      *puVar9 = uVar1 & 0xfffe;
      *puVar9 = uVar1 & 0xfffc;
      *puVar9 = uVar1 & 0xfff8;
      *puVar9 = uVar1 & 0xff00;
      iVar3 = iVar3 + -1;
      puVar9 = puVar9 + 1;
    } while (iVar3 != 0);
  }
  iVar3 = param_1[6];
  param_1[6] = (int)puVar5;
  param_1[7] = 2;
  func_0x81005b02(iVar3);
  iVar11 = param_1[10];
  puVar6 = (undefined2 *)func_0x81005aaa(iVar11 * 0xc);
  iVar3 = param_1[8];
  if ((puVar6 != (undefined2 *)0x0) && (puVar10 = puVar6, 0 < iVar11)) {
    do {
      *puVar10 = 0;
      iVar11 = iVar11 + -1;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10 = puVar10 + 6;
    } while (iVar11 != 0);
  }
  param_1[8] = (int)puVar6;
  param_1[9] = 0xc;
  func_0x81005b02(iVar3);
  uVar7 = param_1[10];
  uVar12 = 0;
  if (uVar7 != 0) {
    iVar3 = param_1[8];
    iVar11 = param_1[9];
    do {
      if ((iVar3 != 0) && (uVar12 < uVar7)) {
        puVar6 = (undefined2 *)(uVar12 * iVar11 + iVar3);
        *puVar6 = 0;
        puVar6[2] = 0;
        puVar6[1] = 1;
        puVar6[3] = 0;
        puVar6[4] = 0;
      }
      uVar12 = uVar12 + 1;
    } while (uVar12 < uVar7);
  }
  return;
}

