
void FUN_810705f0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = *(undefined4 *)(param_1 + 0xf0);
  puVar3 = (undefined4 *)(param_1 + 0xf0);
  iVar5 = 0x10;
  puVar2 = param_2;
  do {
    uVar4 = puVar3[1];
    iVar5 = iVar5 + -1;
    *puVar2 = uVar1;
    puVar2[1] = uVar4;
    uVar1 = puVar3[3];
    puVar2[2] = puVar3[2];
    puVar2[3] = uVar1;
    puVar2 = puVar2 + 4;
    puVar3 = puVar3 + 4;
    uVar1 = *puVar3;
  } while (iVar5 != 0);
  param_2[0x40] = uVar1;
  iVar5 = 4;
  param_2[0x41] = *(undefined4 *)(param_1 + 500);
  do {
    *param_2 = 0;
    iVar5 = iVar5 + -1;
    param_2[2] = 0;
    param_2[4] = 0;
    param_2[6] = 0;
    param_2[8] = 0;
    param_2[10] = 0;
    param_2[0xc] = 0;
    param_2[0xe] = 0;
    param_2 = param_2 + 0x10;
  } while (iVar5 != 0);
  return;
}

