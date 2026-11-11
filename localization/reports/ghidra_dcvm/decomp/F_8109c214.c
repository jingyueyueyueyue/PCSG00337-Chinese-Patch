
undefined4 FUN_8109c214(int *param_1,int param_2,char param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = *param_1;
  iVar8 = param_1[1];
  piVar6 = (int *)0x0;
  iVar9 = *(int *)(param_2 + 0x28);
  if (param_3 == '\0') {
    uVar2 = param_1[2];
  }
  else {
    uVar2 = param_1[2];
  }
  *(uint *)(param_2 + 0x70) = (uint)(param_3 == '\0');
  do {
    uVar2 = uVar2 + 1 & 0xff;
    param_1[2] = uVar2;
    if (uVar2 == 0) {
      uVar2 = 1;
      param_1[2] = 1;
    }
    iVar4 = iVar10;
    if (iVar10 == 0) break;
    do {
      if (*(uint *)(iVar4 + 0x74) == uVar2) break;
      iVar4 = *(int *)(iVar4 + 8);
    } while (iVar4 != 0);
  } while (iVar4 != 0);
  *(uint *)(param_2 + 0x74) = uVar2;
  if ((iVar9 != 0) && (uVar7 = *(uint *)(param_2 + 0x2c), uVar7 != 0)) {
    uVar5 = 0;
    do {
      if ((*(byte *)(iVar9 + 4) != 0) && (*(byte *)(iVar9 + 4) < 3)) {
        *(char *)(iVar9 + 0xb) = (char)uVar2;
      }
      uVar5 = uVar5 + 1;
      iVar9 = iVar9 + 0xc;
    } while (uVar5 < uVar7);
  }
  if (iVar8 == 0) {
    iVar8 = 0;
    if (param_2 != 0) {
      iVar8 = param_2 + 4;
    }
    *(undefined4 *)(iVar8 + 4) = 0;
    puVar3 = (undefined4 *)0x0;
    if (param_2 != 0) {
      puVar3 = (undefined4 *)(param_2 + 4);
    }
    *puVar3 = 0;
    *param_1 = param_2;
  }
  else {
    iVar9 = 0;
    if (param_2 != 0) {
      iVar9 = param_2 + 4;
    }
    *(undefined4 *)(iVar9 + 4) = 0;
    if (param_2 != 0) {
      piVar6 = (int *)(param_2 + 4);
    }
    *piVar6 = iVar8;
    *(int *)(iVar8 + 8) = param_2;
  }
  uVar1 = *(undefined4 *)(param_2 + 0x74);
  param_1[1] = param_2;
  return uVar1;
}

